/********************************************************************* 
** Author: Shawn Berg
** Date: 6/3/17
** Description: This program represents a customer in an online store
*********************************************************************/

#include <iostream>
#include "Customer.hpp"

using namespace std;

// Overload Constructor
Customer::Customer(std::string n, std::string a, bool pm)
{
    name = n;
    accountID = a;
    premiumMember = pm;
}

// Getters
std::string Customer::getAccountID()
{
    return accountID;
}

std::vector<std::string> Customer::getCart()
{
    return cart;
}

// Methods
void Customer::addProductToCart(std::string strIn)
{
    cart.push_back(strIn);
}

bool Customer::isPremiumMember()
{
    return premiumMember;
}

void Customer::emptyCart()
{
    cart.clear();
}


