#include <iostream>
#include <queue>
#include "PointOfSale.h"
#include "PointOfSaleOperations.h"
#include "Customer.h"
using namespace std;

PointOfSaleOperations::PointOfSaleOperations(PointOfSale PointOfSale)
{
    this->pointOfSale = pointOfSale;
}

void PointOfSaleOperations::insertCustomer(Customer Customer)
{
    customers.push(Customer);
}

void PointOfSaleOperations::removeCustomer()
{
    customers.pop();
}

void PointOfSaleOperations::addProduct(Product product)
{
    pointOfSale.AddProduct(product);
}

void PointOfSaleOperations::removeProduct(Product product)
{
    pointOfSale.removeproduct(product);
}

void PointOfSaleOperations::makeSellingOperation(int id, int quantity)
{
    Product product = pointOfSale.sellproduct(id, quantity);
    if (product.getQuantity() > 0)
    {
        customers.front().addBoughtProduct(product);
    }
}

void PointOfSaleOperations::makeReturnOperation(int id, int quantity)
{
    Product product = customers.front().returnBoughtProduct(id, quantity);
    if (product.getQuantity() > 0)
    {
        pointOfSale.returnproduct(product.getId(), product.getQuantity());
    }
}