#ifndef bookshop_h
#define bookshop_h

#include "employee.hpp"  //book.hpp zostaje dolaczony poprzez inne pliki naglowkowe
#include "customer.hpp"

extern char* load(char*, int length);
extern double load_n();

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

  void show_books();
  void show_customers();
  void show_employees();

  void new_book();
  void new_employee();
  void new_customer();

  void delete_book(int n);
  void delete_employee(int n);
  void delete_customer(int n);

  List<Book>* find_book(std::string t, std::string a, std::string p);

  void order_e();     //do pracownika
  void show_order();  //do pracownika

  friend std::ostream& operator<< (std::ostream&, Bookshop*);
  Bookshop& operator= (Bookshop &b2);
  void operator +(float p){this->budget+=p;}
  void  operator -(float n) { this->budget-=n;}
};

#endif
