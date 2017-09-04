/********************************************************************* 
** Author: Shawn Berg
** Date: 6/3/17
** Description: This program represents an online store
*********************************************************************/

#include <iostream>
#include "Store.hpp"

using namespace std;

// Methods
void Store::addProduct(Product *p) // adds product to inventory
{
    inventory.push_back(p);
}

void Store::addMember(Customer *c) // adds customer to members
{
    members.push_back(c);
}

// Getter function for product using ID as parameter
Product* Store::getProductFromID(std::string strIn)
{
    bool proFound = false;
    int i = 0;

    while (proFound == false && i<inventory.size()) // while product has not yet been found
    {
        if (strIn == inventory[i]->getIdCode()) //if input ID and product ID are the same
        {
            proFound = true; // product is found
        }
        else i++;
    }

    if (proFound == false) // if product is not in the inventory
    {
        return NULL;
    }

    if (proFound == true) // if product is in inventory
    {
        return inventory[i]; // return found product
    }
}

// getter function for customer using ID as a parameter
Customer* Store::getMemberFromID(std::string strIn)
{
    bool custFound = false;
    int i = 0;

    while (custFound == false && i<members.size()) // while customer has not been found
    {
        if (strIn == members[i]->getAccountID()) // if input ID and customer ID are the same
        {
            custFound = true; // customer is found
        }
        else i++;
    }

    if (custFound == false) // if customer is not in members
    {
        return NULL;
    }

    if (custFound == true) // customer is found in members
    {
        return members[i]; // return found customer
    }
}

void Store::productSearch(std::string str) // product search function
{
    for (int i=0; i<inventory.size(); i++)
    {
        string proDescription = (inventory[i]->getDescription()); //get description of product

        str[0] = toupper(str[0]); //capitalize first letter of search string
        string str2 = str; // create copy of search string
        str2[0] = tolower(str[0]); //lower case first letter of copy of search string

        if (proDescription.find(str) != string::npos ||
                proDescription.find(str2) != string::npos) // if the search string is found in the description
        {
            cout << inventory[i]->getTitle() << endl; // print product title
            cout << inventory[i]->getIdCode() << endl; // print product ID
            cout << inventory[i]->getPrice() << endl; // print product price
            cout << inventory[i]->getDescription() << endl; // print product description
        }
    }
}

// function to add a product to a customer's cart
void Store::addProductToMemberCart(std::string pID, std::string mID)
{
    bool proFound = false;
    bool memFound = false;
    int i = 0;
    int j = 0;
    Product *foundPro;
    Customer *foundCust;

    while (proFound == false && i<inventory.size()) // while product has not yet been found
    {
        if (inventory[i]->getIdCode() == pID)
        {
            proFound = true;
            foundPro = inventory[i];
        }

        else i++;
    }

    while (memFound == false && j<members.size()) // while member has not yet been found
    {
        if (members[j]->getAccountID() == mID)
        {
            memFound = true;
            foundCust = members[j];
        }
        else j++;
    }

    // if product is in inventory and has quantity availabel and customer is in members
    if ((proFound == true && memFound == true)
        && foundPro->getQuantityAvailable() > 0)
    {
        // ask customer for amount of product
        int quantity = 0;
        cout << "How many " << foundPro->getTitle() << "s would you like? There are "
             << foundPro->getQuantityAvailable()
             << " available." << endl;
        cin >> quantity;

        for (int h = 0; h < quantity; h++) // add product to customer cart (quantity) times
        {
            foundCust->addProductToCart(foundPro->getIdCode());
        }
    }

    if ((proFound == true && memFound == true) // if product is out of stock
        && foundPro->getQuantityAvailable() == 0)
    {
        cout << "Sorry, product #" << pID
             << " is currently out of stock." << endl;
    }

    if (proFound == false) // if product is not in the inventory
    {
        cout << "Product #" << pID << " not found." << endl;
    }

    if (memFound == false) // if the customer is not in the members list
    {
        cout << "Member #" << mID << " not found." << endl;
    }

}

// function to check out customer
void Store::checkOutMember(std::string mID)
{
    bool memFound = false;
    int i = 0;
    Customer *foundCust;
    Store tempStore;
    double subtotal = 0.0;
    double total = 0.0;
    double shippingCost = 0.0;

    while (memFound == false && i<members.size()) // search for member to check out
    {
        if(members[i]->getAccountID() == mID)
        {
            memFound = true;
            foundCust = members[i];
        }
        else i++;
    }

    if (memFound == false) // if member not found
    {
        cout << "Member #" << mID << " not found." << endl;
    }

    else
    {

        vector<std::string> custCart = foundCust->getCart(); // create a copy of customer's cart

        if (custCart.size() == 0) // if cart is empty
        {
            cout << "There are no items in the cart." << endl;
        }

        else
        {

            for (int j = 0; j < custCart.size(); j++) // for loop to go through cart
            {
                Product *cartProduct = Store::getProductFromID(custCart[j]); // create copy of product in cart
                if (cartProduct->getQuantityAvailable() > 0) // if product in stock
                {
                    cout << cartProduct->getTitle() << " - " // print product title
                         << cartProduct->getPrice() // print product price
                         << endl;
                    subtotal += cartProduct->getPrice(); // add product price to subtotal
                    cartProduct->decreaseQuantity(); // decrease quantity of product
                }
                else // if product not in stock
                {
                    cout << "Sorry, product #" << cartProduct->getIdCode()
                         << ", " << cartProduct->getTitle()
                         << ", is no longer available." << endl;
                }
            }

            if (foundCust->isPremiumMember() == false) // if customer is not premium member
            {
                shippingCost = .07 * subtotal; // shipping cost is 7% of subtotal
            }
            else // if customer is premium member
            {
                shippingCost = 0.0; // free shipping
            }

            total = subtotal + shippingCost; // add shipping and subtotal together

            cout << "Subtotal: $" << subtotal << endl;
            cout << "Shipping Cost: $" << shippingCost << endl;
            cout << "Total: $" << total << endl;

            foundCust->emptyCart(); // empty cart
        }
    }
}
