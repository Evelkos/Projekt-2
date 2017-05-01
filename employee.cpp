#include"employee.hpp"

Employee::Employee(std::string n, std::string s, double sal): name(n), surname(s), salary(sal)
{
  D(std::cout<<"Zatrudniamy pracownika"<<std::endl;)
}

Employee::~Employee()
{
  D(std::cout<<"Zwalniamy pracownika."<<std::endl;)
}

Employee& Employee::operator= (Employee &e2)
{
  this->name = e2.get_name();
  this->surname = e2.get_surname();
  this->salary = e2.get_salary();
  return *this;
}
