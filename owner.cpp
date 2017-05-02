#include "owner.hpp"

Owner::Owner(string n, string s, double b): name(n), surname(s), budget(b), firstBs(NULL) {}

Owner::~Owner()
{
  while(firstBs != NULL)
    delete_bs(1);
}

//pokazuje liste ksiegarni
void Owner::show_bs(){show_l(firstBs);}

//tworzy nowa ksiegarnie
void Owner::new_bs()
{
  std::string n, c;
  double b;

  std::cout<<"Nowa ksiegarnia: "<<std::endl;
  std::cout<<"Nazwa: ";       std::cin>>n;
  std::cout<<"Miasto: ";      std::cin>>c;
  std::cout<<"Budzet: ";      std::cin>>b;
  budget -= b;

  Bookshop bs(n, c, b);
  firstBs = new_o(firstBs, bs);
}

//usuwa ksiegarnie o zadanym numerze (aktualnie na liscie)
void Owner::delete_bs(int n)
{
  int i;
  List<Bookshop> *current = firstBs;

  for(i = 1 ; i < n ; i++)
    current = current->get_next();
  budget += current->get_obj()->get_budget();
  delete_o(n, firstBs);
}

//akceptowanie zlozonego zamowienia
void Owner::accept(Bookshop *b)
{
  List<Book> *curr, *f;
  Book *currB;
  char choice;
  if(b->get_oA() == 0)
    std::cout<<"Aktualnie nie ma zlozonych zadnych zamowien"<<std::endl;
  else if((curr = b->get_order()) != NULL)
  {
    show_order(b);
    std::cout<<std::endl<<"Czy akceptujesz zamowienie?"<<std::endl<<"1. Tak"<<std::endl<<"2. Nie"<<std::endl;
    std::cin>>choice;
    if(choice == '1')
    {
      do
      {
        f = find_o(*(curr->get_obj()), b->get_firstB());
        if(f != NULL)
        {
          currB = f->get_obj();
          if((b->get_budget() - currB->get_nOrd()*quantity_pr(currB->get_year(), currB->get_pages())) > 0)
          {
            *b - quantity_pr(currB->get_year(), currB->get_pages());
            currB->set_number(currB->get_number()+curr->get_obj()->get_nOrd());
          }
          else
            *b + quantity_pr(currB->get_year(), currB->get_pages());
        }
        curr = curr->get_next();
      }while(curr != b->get_order());
    }
    while(b->get_order() != NULL)
      b->set_order(delete_o(1, b->get_order()));
    b->set_oA(0);
  }
}

//wyswietlanie zlozonego przez pracownikow zamowienia
void Owner::show_order(Bookshop *current)
{
  if(current->get_oA() == 0)
    std::cout<<"Zadne zamowienie nie jest aktualnie zlozone"<<std::endl;
  else
    show_l(current->get_order());
}
