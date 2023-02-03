#include "Toys.h"
#include <iostream>

using namespace std;

void Toys::setToys(const char* tname, int sku, double price, int age)
{
    int len = strlen(tname);
    toyName = new char[len + 1];
    strcpy(toyName, tname);
    this->sku = sku;
    this->price = price;
    this->age = age;
}

void Toys::display() const
{
    cout << "Toy Name: " << toyName << endl;
    cout << "SKU: " << sku << endl;
    cout << "Price: " << price << endl;
    cout << "Age: " << age << endl;
}
 int Toys::getSKU() const
 {
     return sku;
 }
