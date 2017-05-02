#ifndef INTERFACE_H
#define INTERFACE_H

#include "owner.hpp"

void main_menu(Owner&);
void bs_menu1(Owner&);
void bs_menu2(Owner&);
void em_menu1(Owner&);
void em_menu2(Employee*, Bookshop*);
void cu_menu1(Owner&);
void cu_menu2(Customer*, Bookshop*);

#endif
