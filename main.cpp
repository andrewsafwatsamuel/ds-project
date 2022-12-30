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

    pointOfSaleOperations.makeSellingOperation(MARAI_MILK_ID, 10);
    pointOfSaleOperations.makeSellingOperation(CRISTAL_OIL_ID, 10);
    pointOfSaleOperations.makeSellingOperation(LIBTON_TEA_ID, 10);
    cout << endl;

    List<Product *> bp = andro->getBoughtProducts();

    bp.toFirst();
    while (!bp.cursorIsEmpty())
    {
        Product *p;
        bp.retireveData(p);
        cout << p->getName() << endl;
        cout << p->getId() << endl;
        cout << p->getQuantity() << endl;
        cout << endl;
        bp.advance();
    }
    releaseCustomers();
    return 0;
}

void fillPointOfSaleProducts(PointOfSaleOperations &pointOfSale)
{
    Product milk(MARAI_MILK_ID, "almarai", "one litre", 15.5f, "1-12-2023", "1-12-2022", 1000);
    Product oil(CRISTAL_OIL_ID, "cristal", "one litre", 40.5f, "1-12-2024", "1-12-2022", 1000);
    Product tea(LIBTON_TEA_ID, "libton", "one kilo", 15.5f, "1-12-2023", "1-12-2022", 1000);
    Product coffee(SHAHIN_COFFEE_ID, "shaheen", "one kilo", 150.5f, "1-12-2023", "1-12-2022", 1000);
    Product molto(MEGA_MOLTO_ID, "mega", "one piece", 5.5f, "1-12-2023", "1-12-2022", 1000);
    pointOfSale.addProduct(milk);
    pointOfSale.addProduct(oil);
    pointOfSale.addProduct(tea);
    pointOfSale.addProduct(coffee);
    pointOfSale.addProduct(molto);
}

void initCustomers()
{
    andro = new Customer(121, "Andro");
    sara = new Customer(122, "Sara");
    ahmed = new Customer(123, "Ahmed");
    mostafa = new Customer(124, "Mostafa");
    mohamed = new Customer(125, "Mohamed");
}

void releaseCustomers()
{
    delete andro;
    delete sara;
    delete ahmed;
    delete mostafa;
    delete mohamed;
}