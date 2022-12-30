#include <iostream>
#include "PointOfSale.h"
using namespace std;

PointOfSale::PointOfSale()
{
  productList = List<Product *>();
  id = -1;
  name = "";
}

PointOfSale::PointOfSale(int id, string name)
{
  this->productList = List<Product *>();
  this->id = id;
  this->name = name;
}

string PointOfSale::getName()
{
  return name;
}

int PointOfSale::getId()
{
  return id;
}

void PointOfSale::addProduct(Product &product)
{
  productList.toFirst();
  while (!productList.cursorIsEmpty())
  {
    Product *innerProduct;
    productList.retireveData(innerProduct);
    if (product.getId() == innerProduct->getId())
    {
      int productQuantity = product.getQuantity() + innerProduct->getQuantity();
      innerProduct->setQuantity(productQuantity);
      return;
    }
    productList.advance();
  }
  productList.insertFirst(new Product(
		product.getId(),
		product.getName(),
		product.getDescripton(),
		product.getPrice(),
		product.getExpiryDate(),
		product.getProductionDate(),
		product.getQuantity()));
}

void PointOfSale::removeproduct(int id)
{
  productList.toFirst();
  while (!productList.cursorIsEmpty())
  {
    Product *innerProduct;
    productList.retireveData(innerProduct);
    if (innerProduct->getId() == id)
    {
      innerProduct->setQuantity(0);
      return;
    }
    productList.advance();
  }
}

void PointOfSale::sellproduct(int id, int qty, Product &product)
{
  if (productList.listIsEmpty())
  {
    cout << "No Products Available" << endl;
    return;
  }
  productList.toFirst();
  while (!productList.cursorIsEmpty())
  {
    Product *innerProduct;
    productList.retireveData(innerProduct);

    if (innerProduct->getId() == id)
    {
      if (innerProduct->getQuantity() >= qty)
      {
        product = Product(id, innerProduct->getName(), innerProduct->getDescripton(), innerProduct->getPrice(), innerProduct->getExpiryDate(), innerProduct->getProductionDate(), qty);
        innerProduct->setQuantity(innerProduct->getQuantity() - qty);
        cout << "Sold " << qty << " of " << innerProduct->getName() << endl;
      }
      else
      {
        cout << "Available Quantity is not sufficient" << endl;
      }

      return;
    }
    productList.advance();
  }
  cout << "Product is not available" << endl;
} // id, quantity

void PointOfSale::returnproduct(int id, int qty)
{
  productList.toFirst();
  while (!productList.cursorIsEmpty())
  {
    Product *innerProduct;
    productList.retireveData(innerProduct);
    if (innerProduct->getId() == id)
    {
      innerProduct->setQuantity(innerProduct->getQuantity() + qty);
      return;
    }
    productList.advance();
  }
}

PointOfSale::~PointOfSale()
{
  if (!productList.listIsEmpty())
  {
    productList.toFirst();
    while (!productList.cursorIsEmpty())
    {
      Product *product;
      productList.retireveData(product);
      product = NULL;
      delete product;
      productList.advance();
    }
  }
}
