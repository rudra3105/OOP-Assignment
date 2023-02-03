#ifndef TOYS_H
#define TOYS_H

#include <string>

class Toys
{
    public:
        Toys();
        Toys(const std::string &tname, int sku, double price, int age);

        void setToys(const std::string &tname, int sku, double price, int age);
        void display() const;

        int getSKU() const;

    private:
        std::string name;
        int SKU;
        double cost;
        int recommendedAge;
};

#endif // TOYS_H

