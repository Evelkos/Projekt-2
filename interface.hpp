#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include "debug_head.hpp"
#include "bookshop.hpp"

void main_menu(Bookshop **first, Bookshop **last);
void bookshop_menu1(Bookshop **first, Bookshop **last);
void bookshop_menu2(Bookshop *first);
void employee_menu1(Bookshop *first);
void employee_menu2(Employee *currentE, Bookshop *currentB);
void customer_menu1(Bookshop *first);
void customer_menu2(Customer *currentC, Bookshop *currentB);

//int operator -(Bookshop current, int n);
int show_bookshop_list(Bookshop *first);
void add_to_list_bookshop(Bookshop **first, Bookshop **last);
void delete_bookshop(Bookshop **first, Bookshop **last, int n);
void add_order(Bookshop *current);
void add_order2(Bookshop *current);
void show_order(Bookshop *current);
void order(Bookshop *current);
void accept(Bookshop *current);

#endif
