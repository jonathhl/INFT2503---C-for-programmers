#include <iostream>
#include <string>

const double mva = 1.25;

using namespace std;

class Commodity {
  
  string name;
  long id;
  double price;
  
  public:
    Commodity(string name_, long id_, double price_);
    string get_name() const;
    long get_id() const;
    double get_price(double quantity = 1) const;
    void set_price(double price_);
    double get_price_with_sales_tax(double quantity = 1) const;
};

Commodity::Commodity(string name_, long id_, double price_) : name(name_), id(id_), price(price_) {}

string Commodity::get_name() const {
  return name;
}

long Commodity::get_id() const {
  return id;
}

double Commodity::get_price(double quantity) const {
  return price * quantity;
}

void Commodity::set_price(double price_) {
  price = price_;
}

double Commodity::get_price_with_sales_tax(double quantity) const {
  return price *quantity * mva;
}

int main() {
  const double quantity = 2.5;
  Commodity commodity("Norvegia", 123, 73.50);

  cout << "Varenavn: " << commodity.get_name() << ", varenr: " << commodity.get_id() << " Pris pr enhet: " << commodity.get_price() << endl;

  cout << "Kilopris: " << commodity.get_price() << endl;
  cout << "Prisen for " << quantity << " kg er " << commodity.get_price(quantity) << " uten moms" << endl;
  cout << "Prisen for " << quantity << " kg er " << commodity.get_price_with_sales_tax(quantity) << " med moms" << endl;

  commodity.set_price(79.60);
  cout << "Ny kilopris: " << commodity.get_price() << endl;
  cout << "Prisen for " << quantity << " kg er " << commodity.get_price(quantity) << " uten moms" << endl;
  cout << "Prisen for " << quantity << " kg er " << commodity.get_price_with_sales_tax(quantity) << " med moms" << endl;
}

/* Utskrift:
Varenavn: Norvegia, varenr: 123 Pris pr enhet: 73.5
Kilopris: 73.5
Prisen for 2.5 kg er 183.75 uten moms
Prisen for 2.5 kg er 229.688 med moms
Ny kilopris: 79.6
Prisen for 2.5 kg er 199 uten moms
Prisen for 2.5 kg er 248.75 med moms
*/
