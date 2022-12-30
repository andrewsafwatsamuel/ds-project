#include <iostream>
#include "PointOfSale.h"
#include "Product.h"
#include "PointOfSaleOperations.h"
#include "Customer.h"
using namespace std;

void fillPointOfSaleProducts(PointOfSaleOperations &);

int main()
{
    PointOfSale pointOfSale(1001, "market place");
    PointOfSaleOperations pointOfSaleOperations(pointOfSale);
    fillPointOfSaleProducts(pointOfSaleOperations);
    Customer *andro = new Customer(121, "Andro");
    Customer *sara = new Customer(122, "Sara");
    Customer *ahmed = new Customer(123, "Ahmed");
    Customer *mostafa = new Customer(124, "Mostafa");
    Customer *mohamed = new Customer(125, "Mohamed");
    pointOfSaleOperations.insertCustomer(andro);
    pointOfSaleOperations.insertCustomer(sara);
    pointOfSaleOperations.insertCustomer(ahmed);
    pointOfSaleOperations.insertCustomer(mostafa);
    pointOfSaleOperations.insertCustomer(mohamed);

    pointOfSaleOperations.makeSellingOperation(1101, 10);
    pointOfSaleOperations.makeSellingOperation(1102, 10);
    pointOfSaleOperations.makeSellingOperation(1103, 10);

    delete andro;
    delete sara;
    delete ahmed;
    delete mostafa;
    delete mohamed;

    return 0;
}

void fillPointOfSaleProducts(PointOfSaleOperations &pointOfSale)
{
    Product milk(1101, "almarai", "one litre", 15.5f, "1-12-2023", "1-12-2022", 1000);
    Product oil(1102, "cristal", "one litre", 40.5f, "1-12-2024", "1-12-2022", 1000);
    Product tea(1103, "libton", "one kilo", 15.5f, "1-12-2023", "1-12-2022", 1000);
    Product coffee(1104, "shaheen", "one kilo", 150.5f, "1-12-2023", "1-12-2022", 1000);
    Product molto(1105, "mega", "one piece", 5.5f, "1-12-2023", "1-12-2022", 1000);
    pointOfSale.addProduct(milk);
    pointOfSale.addProduct(oil);
    pointOfSale.addProduct(tea);
    pointOfSale.addProduct(coffee);
    pointOfSale.addProduct(molto);
}