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

void Customer::buy(Book &bo)
{
  int i;

  if(this->get_money() >= bo.get_price())
  {
    this->set_money(this->get_money() - bo.get_price());
    i = bo.get_number() - 1;       //zapis liczby egzemplarzy pomniejszonej o sprzedany egzemplarz
    bo.set_number(1);              //wynika ze specyfikacji operatora przypisania (kupowany jest 1 egz => number = 1)
    this->add_to_collection(bo);   //dodawanie ksiazki do kolekcji
    bo.set_number(i);              //ustawianie poprawnej ilosci ksiazek w ksiegarni
  }

  else
    std::cout<<"-Mam zbyt malo pieniedzy. Nie moge kupic tej ksiazki"<<std::endl;
}
