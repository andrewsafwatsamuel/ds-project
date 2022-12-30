#include <iostream>
#include "Product.h"
using namespace std;

Product::Product()
{
	this->id = -1;
	this->name = "";
	this->description = "";
	this->price = 0.0f;
	this->expiryDate = "";
	this->productionDate = "";
	this->quantity = new int;
	*quantity=0;
}

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
	if (quantity < 0)
	{
		cout << "Invalid quantity" << endl;
		return;
	}
	this->quantity = quantity;
}
