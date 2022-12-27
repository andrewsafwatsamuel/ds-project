#include <iostream>
#include "Product.h"
using namespace std;

Product::Product(int id, string name, string description, float price, string expiryDate, string productionDate, int quantity)
{
	this->id = id;
	this->name = name;
	this->description = description;
	this->price = price;
	this->expiryDate = expiryDate;
	this->productionDate = productionDate;
	this->quantity = quantity;
}

int Product::getId()
{
	return id;
}

string Product::getName()
{
	return name;
}

string Product::getDescripton()
{
	return description;
}

float Product::getPrice()
{
	return price;
}

string Product::getExpiryDate()
{
	return expiryDate;
}

string Product::getProductionDate()
{
	return productionDate;
}

int Product::getQuantity()
{

	return quantity;
}

void Product::setQuantity(int quantity)
{
	this->quantity = quantity;
}
