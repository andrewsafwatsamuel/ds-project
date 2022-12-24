#ifndef PointOfSale_H
#define PointOfSale_H
#include <iostream>
#include <list>
#include "Product.h"
using namespace std;

class PointOfSale
{
private:
    int id;
    string name;
    list<Product> productList;

public:
    PointOfSale();
    PointOfSale(int id, string name);
    string getName();
    int getId();
    void AddProduct(Product);
    void removeproduct(Product);
    Product sellproduct(int, int); // id, quantity
    void returnproduct(int, int);  // id, quantity
};

#endif