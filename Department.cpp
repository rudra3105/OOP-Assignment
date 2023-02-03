#include <iostream>
#include <cstring>
#include <iomanip>

#define MAX_NUM_TOYS 10
#define MAX_SNAME 31

class Toys {
  public:
    void addToys(const char* tname, int sku, double price, int age);
    void isSale(bool sale);
    void calSale();
    void display() const;

  private:
    char m_tname[MAX_TNAME];
    int m_sku;
    double m_price;
    int m_age;
    bool m_onSale;
};

class Store {
  public:
    void setStore(const char* sName, int no);
    void setToys(const char* tname, int sku, double price, int age);
    void display() const;
    void find(int sku);
    void setEmpty();

  private:
    char m_sName[MAX_SNAME];
    int m_noOfToys;
    int m_addToys;
    Toys m_toy[MAX_NUM_TOYS];
};

void Toys::addToys(const char* tname, int sku, double price, int age) {
  if (strlen(tname) > 0 && strlen(tname) <= MAX_TNAME && sku >= 0 && price > 0 && age >= 0) {
    strcpy(m_tname, tname);
    m_sku = sku;
    m_price = price;
    m_age = age;
    m_onSale = false;
  } else {
    strcpy(m_tname, "");
    m_sku = -1;
    m_price = -1;
    m_age = -1;
    m_onSale = false;
  }
}

void Toys::isSale(bool sale) {
  m_onSale = sale;
}

void Toys::calSale() {
  m_price = m_price * 0.8;
}

void Toys::display() const {
  if (strlen(m_tname) > 0) {
    std::cout << std::left << std::setw(15) << m_tname;
    std::cout << std::right << std::setw(10) << m_sku;
    std::cout << std::right << std::setw(6) << m_age;
    std::cout << std::right << std::setw(12) << std::fixed << std::setprecision(2) << m_price;
    if (m_onSale) {
      std::cout << std::right << std::setw(10) << "On Sale" << std::endl;
    } else {
      std::cout << std::right << std::setw(8) << " " << std::endl;
    }
  } else {
    std::cout << "Invalid Toy" << std::endl;
  }
}

void Store::setStore(const char* sName, int no) {
  if (strlen(sName) <= MAX_SNAME && no <= MAX_NUM_TOYS) {
    strcpy(m_sName, sName);
    m_noOfToys = no;
  } else {
    setEmpty();
  }
}

void Store::setToys(const char* tname, int sku, double price, int age) {
  if (m_addToys < m_noOfToys) {
    m_toy[m_addToys].addToys(tname, sku, price, age);
    m_addToys++;
  }
}

void Store::display() const {
  if (m_sName[0] == '\0' && m_noOfToys == 0) {
    cout << "Invalid Store" << endl;
  } else {
    cout << setw(60) << setfill('*') << "*" << endl;
    cout << m_sName << endl;
    cout << setw(60) << setfill('*') << "*" << endl;
    cout << setw(30) << "SKU" << setw(10) << "Age" << setw(11) << "Price" << setw(10) << "Sale" << endl;
    for (int i = 0; i < m_addToys; i++) {
      m_toy[i].display();
    }
  }
}

void Store::find(int sku) {
  for (int i = 0; i < m_addToys; i++) {
    if (m_toy[i].m_sku == sku) {
      m_toy[i].isSale(true);
      m_toy[i].calSale();
      break;
    }
  }
}

void Store::setEmpty() {
  m_sName[0] = '\0';
  m_noOfToys = 0;
  m_addToys = 0;
  for (int i = 0; i < MAX_NUM_TOYS; i++) {
    m_toy[i].setEmpty();
  }
}


