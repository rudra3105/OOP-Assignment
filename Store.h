#ifndef STORE_H
#define STORE_H

#include "Toys.h"

const int MAX_NUM_TOYS = 10;
const int MAX_SNAME = 31;

class Store
{
    char m_sName[MAX_SNAME];
    int m_noOfToys;
    int m_addToys;
    Toys m_toy[MAX_NUM_TOYS];

public:
    void setStore(const char* sName, int no);
    void setToys(const char* tname, int sku, double price, int age);
    void display() const;
    void find(int sku);
    void setEmpty();
};

#endif

