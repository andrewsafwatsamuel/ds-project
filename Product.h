#ifndef Product_H
#define Product_H
#include <iostream>
using namespace std;

class Product
{
private:
    int id, quantity;
    string name, description, expiryDate, productionDate;
    float price;

public:
    Product();
    Product(int id, string name, string description, float price, string expiryDate, string productionDate, int quantity);
    int getId();
    string getName();
    string getDescripton();
    float getPrice();
    string getExpiryDate();
    string getProductionDate();
    int getQuantity();
    void setQuantity(int);
};

#endif