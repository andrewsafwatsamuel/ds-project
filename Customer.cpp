#include <iostream>
#include "Customer.h"
#include "Product.h"

using namespace std;

Customer::Customer()
{
	boughtProducts = List<Product *>();
	id = 0;
	name = "";
}

Customer::Customer(int id, string name)
{
	boughtProducts = List<Product *>();
	this->id = id;
	this->name = name;
}

int Customer::getId()
{
	return id;
}

string Customer::getName()
{
	return name;
}

void Customer::addBoughtProduct(Product &product)
{
	int productid = product.getId(); // product id
	boughtProducts.toFirst();
	while (!boughtProducts.cursorIsEmpty())
	{
		Product *innerProduct;
		boughtProducts.retireveData(innerProduct);
		if (innerProduct->getId() == productid)
		{
			int totalquantity = innerProduct->getQuantity() + product.getQuantity();
			innerProduct->setQuantity(totalquantity);
			return;
		}
		boughtProducts.advance();
	}
	boughtProducts.insertFirst(new Product(
		product.getId(),
		product.getName(),
		product.getDescripton(),
		product.getPrice(),
		product.getExpiryDate(),
		product.getProductionDate(),
		product.getQuantity()));
}

void Customer::returnBoughtProduct(int id, int quantity, Product &result)
{
	if (boughtProducts.listIsEmpty())
	{
		cout << "no products found" << endl;
		return;
	}
	boughtProducts.toFirst();
	while (!boughtProducts.cursorIsEmpty())
	{
		Product *product;
		boughtProducts.retireveData(product);
		if (product->getId() == id)
		{
			if (product->getQuantity() >= quantity)
			{
				result = Product(
					id,
					product->getName(),
					product->getDescripton(),
					product->getPrice(),
					product->getExpiryDate(),
					product->getProductionDate(),
					quantity);
				product->setQuantity(product->getQuantity() - quantity);
			}
			else
			{
				result = Product(
					id,
					product->getName(),
					product->getDescripton(),
					product->getPrice(),
					product->getExpiryDate(),
					product->getProductionDate(),
					product->getQuantity());
				product->setQuantity(0);
			}
			return;
		}
		boughtProducts.advance();
	}

	cout << "The product not found" << endl;
}


List<Product*> Customer::getBoughtProducts(){
	return boughtProducts;
}

Customer::~Customer()
{
	boughtProducts.toFirst();
	while (!boughtProducts.cursorIsEmpty())
	{
		Product *product;
		boughtProducts.retireveData(product);
		product = NULL;
		delete product;
		boughtProducts.advance();
	}
}