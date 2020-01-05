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
   cpy   = 0;
   data  = new char[1];
   data[0] = '\0';
   len  = 0;
}

void Str::uncreate() {
   delete cpy;
   delete data;
   data = 0;
   len  = 0;
}

void Str::create(size_type n, const char& val) {
   cpy   = 0;
   data  = new char[n+1];
   len   = n;
   for (size_type i = 0; i!= len; ++i) {
      data[i] = val;
   }
   data[len] = '\0';
}

void Str::create(const_iterator cp) {
   cpy = 0;
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
const char* Str::c_str()
{
   delete cpy;
   cpy = new char[len+1]; 
   for (size_type i=0; i!=len; ++i) {
      cpy[i] = data[i];
   }
   cpy[len] = '\0';
   return cpy;
} 
const char* Str::c_data()
{
   delete cpy;
   cpy = new char[len]; 
   for (size_type i=0; i!=len; ++i) {
      cpy[i] = data[i];
   }
   return cpy;
} 
void Str::c_copy(char* c, int n)
{
   size_type i;
   for (i=0; i!=n-1; ++i) {
      c[i] = data[i];
   }
   c[i] = '\0';
} 

bool operator<(const Str& s1, const Str& s2)
{
   int cmp = strcmp(s1.begin(), s2.begin());
   if (cmp < 0) return true;
   else return false;
}
bool operator<=(const Str& s1, const Str& s2)
{
   int cmp = strcmp(s1.begin(), s2.begin());
   if (cmp <= 0) return true;
   else return false;
}
bool operator>(const Str& s1, const Str& s2)
{
   int cmp = strcmp(s1.begin(), s2.begin());
   if (cmp > 0) return true;
   else return false;
}
bool operator>=(const Str& s1, const Str& s2)
{
   int cmp = strcmp(s1.begin(), s2.begin());
   if (cmp >= 0) return true;
   else return false;
}
bool operator==(const Str& s1, const Str& s2)
{
   int cmp = strcmp(s1.begin(), s2.begin());
   if (cmp == 0) return true;
   else return false;
}
bool operator!=(const Str& s1, const Str& s2)
{
   int cmp = strcmp(s1.begin(), s2.begin());
   if (cmp != 0) return true;
   else return false;
}

istream& getline(istream& is, Str& s)
{
   s.clear();

   char c;
   is.get(c);

   do {
      if ((c!='\n') && (c!='\r')) {
         s.push_back(c);
      }
   } while(is.get(c) && (c!='\n') && (c!='\r'));

   return is;
}
void Str::insert(size_type pos, Str s)
{
   Str tmp = *this;
   size_type old_len = len; 
   size_type new_len = old_len + s.size(); 

   char* new_data = new char[new_len+1];
   for (size_type i=0; i!=pos; ++i) { 
      new_data[i] = tmp[i];
   }
   for (size_type i=0; i!=s.size(); ++i) { 
      new_data[pos+i] = s[i];
   }
   for (size_type i=pos; i!=old_len; ++i) { 
      new_data[s.size()+i] = tmp[i];
   }
   new_data[new_len] = '\0';

   uncreate();
   data = new_data;
   len = new_len;
}
