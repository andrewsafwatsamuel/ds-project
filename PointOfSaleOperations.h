#ifndef PointOfSaleOperstions_H
#define PointOfSaleOperstions_H
#include <queue>
#include "Customer.h"
#include "PointOfSale.h"

class PointOfSaleOperations
{
private:
    queue<Customer> customers;
    PointOfSale pointOfSale;

public:
    PointOfSaleOperations(PointOfSale);
    void insertCustomer(Customer);
    void removeCustomer();
    void addProduct(Product);
    void removeProduct(Product);
    void makeReturnOperation(int, int);  // id, quantity
    void makeSellingOperation(int, int); // id, quantity
};

#include "PointOfSaleOperations.cpp"
#endif