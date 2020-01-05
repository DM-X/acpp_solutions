#include "list_string.hpp"

void List_string::print() const
{
   int cnt=0;
   for (list<string>::const_iterator i=this.begin(); i!=this.end(); ++i) {
      cout << "cnt = " << cnt++ << " : " << *i << endl;
   }
   //for (list<string>::size_type i=0; i!=l.size(); ++i) {
   //   cout << "i = " << i << " : " << l[i] << endl;
   //}
}
