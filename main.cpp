#include <iostream>
#include "PointOfSale.h"
#include "Product.h"
#include "PointOfSaleOperations.h"
#include "Customer.h"
using namespace std;

int main()
{
    PointOfSale pointOfSale(1001, "market place");
    Product *milk = new Product(1101, "almarai", "one litre", 15.5f, "1-12-2023", "1-12-2022", 1000);
    Product *oil = new Product(1102, "cristal", "one litre", 40.5f, "1-12-2024", "1-12-2022", 1000);
    Product *tea = new Product(1103, "libton", "one kilo", 15.5f, "1-12-2023", "1-12-2022", 1000);
    Product *coffee = new Product(1104, "shaheen", "one kilo", 150.5f, "1-12-2023", "1-12-2022", 1000);
    Product *molto = new Product(1105, "mega", "one piece", 5.5f, "1-12-2023", "1-12-2022", 1000);
    pointOfSale.addProduct(milk);
    pointOfSale.addProduct(oil);
    pointOfSale.addProduct(tea);
    pointOfSale.addProduct(coffee);
    pointOfSale.addProduct(molto);
    PointOfSaleOperations pointOfSaleOperations(pointOfSale);
    Customer andro(121, "Andro");
    Customer sara(122, "Sara");
    Customer ahmed(123, "Ahmed");
    Customer mostafa(124, "Mostafa");
    Customer mohamed(125, "Mohamed");
    pointOfSaleOperations.insertCustomer(andro);
    pointOfSaleOperations.insertCustomer(sara);
    pointOfSaleOperations.insertCustomer(ahmed);
    pointOfSaleOperations.insertCustomer(mostafa);
    pointOfSaleOperations.insertCustomer(mohamed);

    return 0;
}