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
      Str(const Str& s) {create(s.data);}
      // create a Str containing n copies of c
      Str(size_type n, const char c) {create(n, c);}
      // create a Str from a null-terminated array of char
      Str(const_iterator cp) {create(cp);}
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
      const char* c_str(); 
      const char* c_data();
      void c_copy(char* c, int n);

      operator bool() {return (len>0);};

      void clear() {uncreate(); create();}
      void insert(size_type pos, Str s);

   private:
      iterator data;
      size_type len;

      iterator cpy;

      void create();
      void create(size_type n, const value_type& val);
      void create(const_iterator cp);
      void uncreate();
};

std::ostream& operator<<(std::ostream& os, Str& s);

Str operator+(const Str&, const Str&);

bool operator<(const Str&, const Str&);
bool operator<=(const Str&, const Str&);
bool operator>(const Str&, const Str&);
bool operator>=(const Str&, const Str&);
bool operator==(const Str&, const Str&);
bool operator!=(const Str&, const Str&);

std::istream& getline(std::istream& is, Str& s);

#endif
