#ifndef PointOfSale_H
#define PointOfSale_H
#include <iostream>
#include "List.h"
#include "Product.h"
using namespace std;

class PointOfSale
{
private:
    int id;
    string name;
    List<Product*> productList;

public:
    PointOfSale();
    PointOfSale(int id, string name);
    string getName();
    int getId();
    void addProduct(Product &);
    void removeproduct(int);
    void sellproduct(int, int, Product &);
    void returnproduct(int, int);
    ~PointOfSale();
};

#include "PointOfSale.cpp"
#endif