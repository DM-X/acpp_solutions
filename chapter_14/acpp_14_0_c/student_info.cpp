#include <iostream>
#include "student_info.hpp"

using std::istream;

istream& Student_info::read(istream& is) 
{
   char ch;     // get record type
   is >> ch;

   if (ch == 'U') {
      cp = new Core(is);
   } else {
      cp = new Grad(is);
   }

   return is;
}
