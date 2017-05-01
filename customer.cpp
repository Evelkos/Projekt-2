#include "customer.hpp"

Customer::Customer(std::string n, std::string s, double m): name(n), surname(s), money(m), collection(NULL)
{
  D(std::cout<<"Tworzymy klienta"<<std::endl;)
}

Customer::~Customer()
{
  while(collection != NULL)
    collection = delete_o(1, collection);
  D(std::cout<<"Usuwamy kilenta"<<std::endl;)
}

//dodaje nowa ksiazke do listy
void Customer::add_to_collection(Book &b)
{
  collection = new_o(collection, b);
}

void Customer::show_collection(){ show_l(collection);}

//operator przypisania - nie likwiduje listy ksiazek klienta, ktorego dane ulegly zmianie (w programie nie jest to potrzebne)
Customer& Customer::operator= (Customer &c2)
{
  this->name = c2.get_name();
  this->surname = c2.get_surname();
  this->money = c2.get_money();
  return *this;
}
