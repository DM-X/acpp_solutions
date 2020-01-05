#include "str.hpp"

using std::istream;
using std::ostream;

istream& operator>>(istream& is, Str& s)
{
   s.data->clear();

   //discard leading whitespace
   char c;
   while(is.get(c) && isspace(c))
      ;
   
   do s.data->push_back(c);
   while(is.get(c) && !isspace(c));

   //if there was whitespace, then put it back
   if (is)
      is.unget();
   return is;
}

ostream& operator<<(ostream& os, Str& s)
{
   for(Str::size_type i=0; i!=s.size(); ++i) {
      os << s[i];
   }
   return os;
}


Str operator+(const Str& s, const Str& t)
{
   Str r = s;
   r += t;
   return r;
}
