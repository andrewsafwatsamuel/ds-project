#ifndef PointOfSaleOperstions_H
#define PointOfSaleOperstions_H
#include "Queue.h"
#include "Customer.h"
#include "PointOfSale.h"

class PointOfSaleOperations
{
private:
    Queue<Customer*> customers;
    PointOfSale *pointOfSale;

public:
    PointOfSaleOperations(PointOfSale&);
    void insertCustomer(Customer*);
    void removeCustomer();
    void addProduct(Product&);
    void removeProduct(int);
    void makeReturnOperation(int, int);  // id, quantity
    void makeSellingOperation(int, int); // id, quantity
    ~PointOfSaleOperations();
};

#include "PointOfSaleOperations.cpp"
#endif