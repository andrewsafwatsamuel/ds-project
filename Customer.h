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
    Customer(int id, string name);
    string getName();
    int getId();
    void addBoughtProduct(Product);
    Product returnBoughtProduct(int, int); // id and quantity
};

#endif