#include <iostream>
#include "PointOfSale.h"
#include "Product.h"
#include "PointOfSaleOperations.h"
#include "Customer.h"
using namespace std;

const int MARAI_MILK_ID = 1101, CRISTAL_OIL_ID = 1102, LIBTON_TEA_ID = 1103, SHAHIN_COFFEE_ID = 1104, MEGA_MOLTO_ID = 1105;
Customer *andro, *sara, *ahmed, *mostafa, *mohamed;

void fillPointOfSaleProducts(PointOfSaleOperations &);
void initCustomers();
void releaseCustomers();
void printProductsPerCustomer(Customer *);

int main()
{
    PointOfSale pointOfSale(1001, "market place");
    PointOfSaleOperations pointOfSaleOperations(pointOfSale);
    fillPointOfSaleProducts(pointOfSaleOperations);
    initCustomers();
    pointOfSaleOperations.insertCustomer(andro);
    pointOfSaleOperations.insertCustomer(sara);
    pointOfSaleOperations.insertCustomer(ahmed);
    pointOfSaleOperations.insertCustomer(mostafa);
    pointOfSaleOperations.insertCustomer(mohamed);

    // Andrew
    pointOfSaleOperations.makeSellingOperation(MARAI_MILK_ID, 10);
    pointOfSaleOperations.makeSellingOperation(CRISTAL_OIL_ID, 10);
    pointOfSaleOperations.makeSellingOperation(LIBTON_TEA_ID, 10);
    pointOfSaleOperations.removeCustomer();
    cout << endl;

    // Sara
    pointOfSaleOperations.makeSellingOperation(MARAI_MILK_ID, 20);
    pointOfSaleOperations.makeSellingOperation(MEGA_MOLTO_ID, 20);
    pointOfSaleOperations.makeSellingOperation(SHAHIN_COFFEE_ID, 20);
    pointOfSaleOperations.removeCustomer();
    cout << endl;

    pointOfSaleOperations.removeProduct(MARAI_MILK_ID);

    // Ahmed
    pointOfSaleOperations.makeSellingOperation(MARAI_MILK_ID, 30);
    pointOfSaleOperations.makeSellingOperation(MEGA_MOLTO_ID, 30);
    pointOfSaleOperations.makeSellingOperation(SHAHIN_COFFEE_ID, 30);
    Product milk(MARAI_MILK_ID, "almarai", "one litre", 15.5f, "1-12-2023", "1-12-2022", 1000);
    pointOfSaleOperations.addProduct(milk);
    pointOfSaleOperations.makeSellingOperation(MARAI_MILK_ID, 30);
    pointOfSaleOperations.makeReturnOperation(MARAI_MILK_ID, 10);
    pointOfSaleOperations.makeReturnOperation(MEGA_MOLTO_ID, 10);
    pointOfSaleOperations.makeReturnOperation(SHAHIN_COFFEE_ID, 10);
    pointOfSaleOperations.removeCustomer();
    cout << endl;

    pointOfSaleOperations.insertCustomer(ahmed);

    // Mostafa
    pointOfSaleOperations.makeSellingOperation(MARAI_MILK_ID, 500);
    pointOfSaleOperations.makeSellingOperation(MEGA_MOLTO_ID, 500);
    pointOfSaleOperations.makeSellingOperation(SHAHIN_COFFEE_ID, 500);
    pointOfSaleOperations.removeCustomer();
    cout << endl;

    // Mohamed
    pointOfSaleOperations.makeSellingOperation(MARAI_MILK_ID, 500);
    pointOfSaleOperations.makeSellingOperation(MEGA_MOLTO_ID, 500);
    pointOfSaleOperations.makeSellingOperation(SHAHIN_COFFEE_ID, 500);
    pointOfSaleOperations.removeCustomer();
    cout << endl;

    // Ahmed
    pointOfSaleOperations.makeSellingOperation(MARAI_MILK_ID, 10);
    pointOfSaleOperations.makeSellingOperation(MEGA_MOLTO_ID, 10);
    pointOfSaleOperations.makeSellingOperation(SHAHIN_COFFEE_ID, 10);
    pointOfSaleOperations.removeCustomer();
    cout << endl;

    printProductsPerCustomer(andro);
    printProductsPerCustomer(sara);
    printProductsPerCustomer(ahmed);
    printProductsPerCustomer(mostafa);
    printProductsPerCustomer(mohamed);

    releaseCustomers();
    return 0;
}

void fillPointOfSaleProducts(PointOfSaleOperations &operations)
{
    Product milk(MARAI_MILK_ID, "almarai", "one litre", 15.5f, "1-12-2023", "1-12-2022", 1000);
    Product oil(CRISTAL_OIL_ID, "cristal", "one litre", 40.5f, "1-12-2024", "1-12-2022", 1000);
    Product tea(LIBTON_TEA_ID, "libton", "one kilo", 15.5f, "1-12-2023", "1-12-2022", 1000);
    Product coffee(SHAHIN_COFFEE_ID, "shaheen", "one kilo", 150.5f, "1-12-2023", "1-12-2022", 1000);
    Product molto(MEGA_MOLTO_ID, "mega", "one piece", 5.5f, "1-12-2023", "1-12-2022", 1000);
    operations.addProduct(milk);
    operations.addProduct(oil);
    operations.addProduct(tea);
    operations.addProduct(coffee);
    operations.addProduct(molto);
}

void initCustomers()
{
    andro = new Customer(121, "Andro");
    sara = new Customer(122, "Sara");
    ahmed = new Customer(123, "Ahmed");
    mostafa = new Customer(124, "Mostafa");
    mohamed = new Customer(125, "Mohamed");
}

void printProductsPerCustomer(Customer *customer)
{
    cout << "products bought by: " << customer->getName() << endl;
    int number = 1;
    List<Product *> boughtProducts = customer->getBoughtProducts();
    boughtProducts.toFirst();
    while (!boughtProducts.cursorIsEmpty())
    {
        Product *product;
        boughtProducts.retireveData(product);
        cout << number++ << "- name: " << product->getName() << ", description: " << product->getDescripton() << ", quantity: " << product->getQuantity() << endl;
        boughtProducts.advance();
    }
    cout << endl;
}

void releaseCustomers()
{
    delete andro;
    delete sara;
    delete ahmed;
    delete mostafa;
    delete mohamed;
}