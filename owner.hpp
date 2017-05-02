#include "bookshop.hpp"

class Owner
{
  std::string name, surname;
  double budget;
  List<Bookshop> *firstBs;

  public:

  Owner(string = "-", string = "-", double = 0);
  ~Owner();
  std::string get_name() {return name;}
  std::string get_surname() {return surname;}
  double get_budget() {return budget;}
  List<Bookshop>* get_firstBs() {return firstBs;}

  void set_name(string n) {name = n;}
  void set_surname(string s) {surname = s;}
  void set_budget(double b) {budget = b;}
  void set_firstBs(List<Bookshop> *fBs) {firstBs = fBs;}

  void show_bs();
  void show_order(Bookshop *current);
  void new_bs();
  void delete_bs(int n);
  void accept(Bookshop *b);
};
