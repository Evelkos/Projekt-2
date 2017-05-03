#ifndef customer_h
#define customer_h

#include "book.hpp"
#include "list.hpp"

//klient sklada zamowienie na konkretna ksiazke
class Customer
{
  std::string name;
  std::string surname;
  double money;
  List<Book> *collection;

  public:

  Customer(std::string = "-", std::string = "-", double = 0);
  ~Customer();

  std::string get_name() {return name;}
  std::string get_surname() {return surname;}
  double get_money() {return money;}
  List<Book>* get_collection() {return collection;}

  void set_name(std::string n) {name = n;}
  void set_surname(std::string s) {surname = s;}
  void set_money(double m) {money = m;}
  void set_collection(List<Book> *c) {collection = c;}

  void add_to_collection(Book &b);
  void operator +=(double m) {this->set_money(this->get_money() + m);}
  void show_collection();
  void buy(Book&);

  friend std::ostream& operator<< (std::ostream&, Customer*);
  Customer& operator= (Customer &c2);
};

#endif
