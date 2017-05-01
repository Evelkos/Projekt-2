#ifndef bookshop_h
#define bookshop_h

#include "debug_head.hpp"
#include "list.hpp"
#include "book.hpp"
#include "employee.hpp"
#include "customer.hpp"
//#include "customer.hpp"

using namespace std;
class Bookshop
{
  std::string name, city;
  double budget;
  List<Book> *firstB;
  List<Book> *order;
  List<Employee> *firstE;
  List<Customer> *firstC;
  int oA; //aktywnosc zamowienia

  protected:
  static int numBookshops;  //liczba ksiegarni ogolem

  public:
  Bookshop(std::string = "-", std::string = "-", double = 0);
  ~Bookshop();

  static int get_numBookshops(){return numBookshops;}
  double get_budget() {return budget;}
  int get_oA() {return oA;}
  std::string get_name() {return name;}
  std::string get_city() {return city;}
  List<Book>* get_firstB() {return firstB;}
  List<Book>* get_order() {return order;}
  List<Employee>* get_firstE() {return firstE;}
  List<Customer>* get_firstC() {return firstC;}

  void set_name(std::string n) {name = n;}
  void set_city(std::string c) {city = c;}
  void set_budget(double b) {budget = b;}
  void set_firstB(List<Book> *fB) {firstB = fB;}
  void set_firstE(List<Employee> *fE) {firstE = fE;}
  void set_firstC(List<Customer> *fC) {firstC = fC;}
  void set_order(List<Book>* o) {order = o;}
  void set_oA(int oa) {oA = oa;}

  void show_book();
  void new_book();
  void add_book(std::string t, std::string a, std::string p, float pr, int nO);
  void withdraw_book(int n);
  List<Book>* find_book(std::string t, std::string a, std::string p);

  void show_customer_list();
  void add_to_list_customer();
  void delete_customer(int n);

  void show_employee_list();
  void delete_employee(int n);
  void new_employee();

 // friend std::ostream& operator<< (std::ostream &os, Bookshop *b) {os << b->get_name();
 // os << " " << b->get_city() <<" " << b->get_budget() << std::endl; return os;}

  friend std::ostream& operator<< (std::ostream&, Bookshop*);

  void operator +(float p){this->budget+=p;}
  void  operator -(float n) { this->budget-=n;}
  Bookshop& operator= (Bookshop &b2);
};

#endif
