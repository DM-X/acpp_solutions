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

   switch (ch) {
      case 'U': 
         //cout << "U" << endl;
         type = 'U';
         cp = new Core(is);
         break;
      case 'G': 
         //cout << "G" << endl;
         type = 'G';
         cp = new Grad(is);
         break;
      case 'P': 
         //cout << "P" << endl;
         type = 'P';
         cp = new Pass(is);
         break;
      case 'A': 
         //cout << "A" << endl;
         type = 'A';
         cp = new Audit(is);
         break;
      default: //is necessary for last record (empty) -> if not delete cp fails 
         //cout << "default" << endl;
         type = '-';
         cp = new Pass(is);
   }

   return is;
}

//copy
Student_info::Student_info(const Student_info& s) : cp(0)
{
   if (s.cp) cp = s.cp->clone();
   type = s.type;
}

//assignment
Student_info& Student_info::operator=(const Student_info& s)
{
   if (&s != this) {
      delete cp;
      if (s.cp) {
         cp   = s.cp->clone();
         type = s.type;
      } else {
         cp = 0;
         type = s.type;
      }
   }
   return *this;
}
