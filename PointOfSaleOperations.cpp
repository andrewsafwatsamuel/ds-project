#include <iostream>
#include "Queue.h"
#include "PointOfSale.h"
#include "PointOfSaleOperations.h"
#include "Customer.h"
using namespace std;

PointOfSaleOperations::PointOfSaleOperations(PointOfSale &pointOfSale)
{
    this->customers = Queue<Customer *>();
    this->pointOfSale  = new PointOfSale(pointOfSale.getId(),pointOfSale.getName());
}

void PointOfSaleOperations::insertCustomer(Customer *customer)
{
    customers.enqueue(customer);
}

void PointOfSaleOperations::removeCustomer()
{
    Customer *c;
    customers.dequeue(c);
}

void PointOfSaleOperations::addProduct(Product &product)
{
    pointOfSale->addProduct(product);
}

void PointOfSaleOperations::removeProduct(int id)
{
    pointOfSale->removeproduct(id);
}

void PointOfSaleOperations::makeSellingOperation(int id, int quantity)
{
    Product product;
    pointOfSale->sellproduct(id, quantity, product);
    if (product.getQuantity() > 0)
    {
        Customer *currentCustomer;
        customers.getFront(currentCustomer);
        currentCustomer->addBoughtProduct(product);
    }
}

void PointOfSaleOperations::makeReturnOperation(int id, int quantity)
{
    Customer *currentCustomer;
    customers.getFront(currentCustomer);
    Product product;
    currentCustomer->returnBoughtProduct(id, quantity, product);
    if (product.getQuantity() > 0)
    {
        pointOfSale->returnproduct(product.getId(), product.getQuantity());
    }
}

PointOfSaleOperations::~PointOfSaleOperations(){
    pointOfSale = NULL;
    delete pointOfSale;
}