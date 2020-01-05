#ifndef str_guard
#define str_guard

#include <iostream>
#include <cstring>


class Str {
   friend std::istream& operator>>(std::istream&, Str&);
   public:
      typedef size_t size_type;
      typedef char* iterator;
      typedef const char* const_iterator;
      typedef char value_type;

      Str  operator+=(const Str& s);
      Str& operator=(const Str&);
      Str& operator=(const char rhs);

      //default constructor; create an empty Str
      Str() {create();}
      //default constructor; create an empty Str
      Str(const Str& s) {
         std::cout<<"cs"<<std::endl;
         create(s.data);
      }
      // create a Str containing n copies of c
      Str(size_type n, const char c) {create(n, c);}
      // create a Str from a null-terminated array of char
      Str(const_iterator cp) {std::cout<<"cc"<<std::endl;create(cp);}
      //default destructor; create an empty Str
      ~Str() {uncreate();}

      size_type size() const {return len;}

      iterator begin() {return data;}
      iterator end()   {return data + len;}
      const iterator begin() const {return data;}
      const iterator end()   const {return data + len;}

      char& operator[](size_type i) {return data[i];}
      const char& operator[](size_type i) const {return data[i];}

      void push_back(const char);

   private:
      iterator data;
      size_type len;

      void create();
      void create(size_type n, const value_type& val);
      void create(const_iterator cp);
      void uncreate();
};

std::ostream& operator<<(std::ostream& os, Str& s);

Str operator+(const Str&, const Str&);


#endif
