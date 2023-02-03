#include <iostream>
#include <iomanip>
#include <cstring>
#include "Store.h"

using namespace std;

void Store::setStore(const char* sName, int no)
{
    if (sName == nullptr || strlen(sName) == 0 || no <= 0)
    {
        setEmpty();
        return;
    }

    strncpy(m_sName, sName, MAX_SNAME - 1);
    m_sName[MAX_SNAME - 1] = '\0';
    m_noOfToys = no;
    m_addToys = 0;
}

void Store::setToys(const char* tname, int sku, double price, int age)
{
    if (m_addToys >= m_noOfToys)
    {
        return;
    }

    m_toy[m_addToys].addToys(tname, sku, price, age);
    m_addToys++;
}

void Store::display() const
{
    if (m_sName[0] == '\0')
    {
        cout << "Invalid Store" << endl;
        return;
    }

    cout << setfill('*') << setw(60) << "*" << endl;
    cout << m_sName << endl;
    cout << setfill('*') << setw(60) << "*" << endl;
    cout << "List of the toys" << endl;
    cout << setfill(' ') << setw(30) << left << "SKU"
         << setw(10) << "Age"
         << setw(11) << "Price"
         << setw(10) << "Sale" << endl;

    for (int i = 0; i < m_addToys; i++)
    {
        m_toy[i].display();
    }
}

void Store::find(int sku)
{
    for (int i = 0; i < m_addToys; i++)
    {
        if (m_toy[i].getSKU() == sku)
        {
            m_toy[i].isSale(true);
            m_toy[i].calSale();
        }
    }
}

void Store::setEmpty()
{
    m_sName[0] = '\0';
    m_noOfToys = 0;
    m_addToys = 0;
    for (int i = 0; i < MAX_NUM_TOYS; i++)
    {
        m_toy[i].setEmpty();
    }
}
   

