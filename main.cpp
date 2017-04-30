#include "book.hpp"
#include "list.hpp"

using namespace std;

int main()
{
  List<Book> *f = NULL, *n = NULL;
  n = new List<Book>();
  cout<<n->obj.get_name()<<endl;
  delete(n);

  cout << "Lista:" << endl;
  f = new_o(f);
  f = new_o(f);
  cout<<f->obj.get_name()<<endl;
  show_l(f);
  f = delete_o(1, f);
  cout<<f->obj.get_name()<<endl;




  return 0;
}
