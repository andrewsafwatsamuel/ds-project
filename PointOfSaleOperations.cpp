#include <iostream>
#include "Queue.h"
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
    customers.enqueue(Customer);
}

void PointOfSaleOperations::removeCustomer()
{
    Customer c;
    customers.dequeue(c);
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
        Customer currentCustomer;
        customers.getFront(currentCustomer);
        currentCustomer.addBoughtProduct(product);
    }
}

void PointOfSaleOperations::makeReturnOperation(int id, int quantity)
{
    Customer currentCustomer;
    customers.getFront(currentCustomer);
    Product product = currentCustomer.returnBoughtProduct(id, quantity);
    if (product.getQuantity() > 0)
    {
        pointOfSale.returnproduct(product.getId(), product.getQuantity());
    }
}