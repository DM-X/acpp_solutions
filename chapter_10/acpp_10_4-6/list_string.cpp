#include <iostream>
#include "list_string.hpp"

using std::cout;
using std::endl;
using std::string;
using std::list;

void List_string::print(void) const
{
   if (this->empty()) cout << "list is empty" << endl; 
   else { 
      int cnt=0;
      for (List_string::const_iterator i=this->begin(); i!=this->end(); ++i) {
         cout << "cnt = " << cnt++ << " : " << *i << endl;
      }
   }
}
