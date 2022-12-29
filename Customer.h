#ifndef Customer_H
#define Customer_H
#include <iostream>
#include "List.h"
#include "Product.h"
using namespace std;
class Customer
{
private:
    int id;
    string name;
    List<Product> boughtProducts; // use linked list from section
public:
    Customer();
    Customer(int id, string name);
    string getName();
    int getId();
    void addBoughtProduct(Product &);
    void returnBoughtProduct(int, int, Product&); // id and quantity
};


#include "Customer.cpp"
#endif
