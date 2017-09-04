/********************************************************************* 
** Author: Shawn Berg
** Date: 6/3/17
** Description: This program represents a product in an online store
*********************************************************************/

#include <iostream>
#include "Product.hpp"

using namespace std;

// Overload Constructor
Product::Product(string id, string t, string d, double p, int qa)
{
    idCode = id;
    title = t;
    description = d;
    price = p;
    quantityAvailable = qa;
}

// Getters
std::string Product::getIdCode()
{
    return idCode;
}

std::string Product::getTitle()
{
    return title;
}

std::string Product::getDescription()
{
    return description;
}

double Product::getPrice()
{
    return price;
}

int Product::getQuantityAvailable()
{
    return quantityAvailable;
}

// Methods
void Product::decreaseQuantity()
{
    quantityAvailable -= 1;
}

