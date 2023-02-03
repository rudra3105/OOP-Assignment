#include <iostream>
#include "Store.h"
#include "Toys.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

using namespace std;

int main(int argc, char** argv) {

 Store store;
  store.setStore("Toyland", 1);
  store.setToys("Car", 1001, 19.99, 3);
  store.setToys("Doll", 1002, 14.99, 5);
  store.display();
  cout << "Searching for SKU 1001:" << endl;
  store.find(1001);
 return 0;
}
