#ifndef str_guard
#define str_guard

#include <iostream>
#include <cstring>
#include "vec.hpp"
#include "ptr.hpp"

// does this version work?
class Str {
   friend std::istream& operator>>(std::istream&, Str&);
   public:
   Str& operator+=(const Str& s) {
      data.make_unique();
      std::copy(s.data->begin(), s.data->end(),
                std::back_inserter(*data));
      return *this;
   }
   // interface as before
   typedef Vec<char>::size_type size_type;
   // reimplement constructors to create Ptrs
   Str(): data(new Vec<char>) { }
   Str(const char* cp): data(new Vec<char>) {
      std::copy(cp, cp + std::strlen(cp),
            std::back_inserter(*data));
   }
   Str(size_type n, char c): data(new Vec<char>(n, c)) { }
   template<class In> Str(In i, In j): data(new Vec<char>) {
      std::copy(i, j, std::back_inserter(*data));
   }
   // call make_unique as necessary
   char& operator[](size_type i) {
      data.make_unique();
      return (*data)[i];
   }
   const char& operator[](size_type i) const { return (*data)[i]; }
   size_type size() const { return data->size(); }
   private:
   // store a Ptr to a vector
   Ptr< Vec<char> > data;
};

std::ostream& operator<<(std::ostream& os, Str& s);

Str operator+(const Str&, const Str&);

#endif

