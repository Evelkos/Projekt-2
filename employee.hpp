#ifndef employee_h
#define employee_h
#include "debug_head.hpp"
#include "book.hpp"

class Employee
{
  std::string name, surname;
  double salary;

  public:
  std::string get_name() {return name;}
  std::string get_surname() {return surname;}
  double get_salary() {return salary;}

  void set_name(std::string n) {name = n;}
  void set_surname(std::string s) {surname = s;}
  void set_salary(double sal) {salary = sal;}

  Employee(std::string = "-", std::string = "-", double = 0);
  ~Employee();

  friend std::ostream& operator<< (std::ostream &os, Employee *e) {os << e->get_name()<<" "<<e->get_surname()
                <<" "<<e->get_salary()<<"zl"<<std::endl; return os;}
  Employee& operator= (Employee &e2);

};

int show_employee_list(Employee *first);

#endif
