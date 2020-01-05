#include "str.hpp"
#include <iostream>

using std::istream;
using std::ostream;
using std::cout;
using std::endl;

istream& operator>>(istream& is, Str& s)
{
   s.uncreate();
   s.create();

   //discard leading whitespace
   char c;
   while(is.get(c) && isspace(c))
      ;
   
   do
      s.push_back(c);
   while(is.get(c) && !isspace(c));

   //if there was whitespace, then put it back
   if (is)
      is.unget();
   return is;
}

std::ostream& operator<<(std::ostream& os, Str& s)
{
   for (Str::size_type i = 0; i!= s.size(); ++i) {
      os << s[i];
   }
   return os;
}

void Str::create() {
   data  = new char[1];
   data[0] = '\0';
   len  = 0;
}

void Str::uncreate() {
   delete data;
   data = 0;
   len  = 0;
}

void Str::create(size_type n, const char& val) {
   data  = new char[n+1];
   len   = n;
   for (size_type i = 0; i!= len; ++i) {
      data[i] = val;
   }
   data[len] = '\0';
}

void Str::create(const_iterator cp) {
   size_type n = std::strlen(cp);
   data  = new char[n+1];
   len   = n;
   for (size_type i = 0; i!= len; ++i) {
      data[i] = cp[i];
   }
   data[len] = '\0';
}

Str Str::operator+=(const Str& s) {
   size_type len_1 = this->size();
   size_type len_2 = s.size();
   size_type n = len_1 + len_2;
   Str tmp = this->data;

   this->uncreate();

   data  = new char[n+1];
   len   = n;

   for (size_type i = 0; i!= len_1; ++i) {
      data[i] = tmp[i];
   }
   for (size_type i = 0; i!=len_2; ++i) {
      data[len_1 + i] = s[i];
   }
   data[len] = '\0';

   return this->data;
}

Str operator+(const Str& s, const Str& t)
{
   Str tmp = s;
   tmp += t;
   return tmp;
}

Str& Str::operator=(const Str& rhs)
{
   cout << "ass op" << endl;
   if (&rhs != this) {
      uncreate();
      create(rhs.data);
   }
   return *this;
}
Str& Str::operator=(const char rhs)
{
   cout << "char ass op" << endl;
   uncreate();
   create(1, rhs);
   return *this;
}
void Str::push_back(const char c)
{
   Str tmp = *this;
   size_type len_old = len; 
   uncreate();
   create(len_old+1, ' ');
   for (size_type i=0; i!=len_old; ++i) {
      data[i] = tmp[i];
   }
   data[len_old] = c;
   data[len] = '\0';
}
