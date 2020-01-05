#include <iostream>
#include "student_info.hpp"

using std::istream;
using std::cout;
using std::endl;

istream& Student_info::read(istream& is) 
{
   delete cp;   // delete previous object, if any

   char ch;     // get record type
   is >> ch;

   if (ch == 'U') {
      cout << "u" << endl;
      cp = new Core(is);
   } else {
      cout << "g" << endl;
      cp = new Grad(is);
   }

   return is;
}

Student_info::Student_info(const Student_info& s) : cp(0)
{
   if (s.cp) cp = s.cp->clone();
}

Student_info& Student_info::operator=(const Student_info& s)
{
   if (&s != this) {
      delete cp;
      if (s.cp)
         cp = s.cp->clone();
      else
         cp = 0;
   }
   return *this;
}
