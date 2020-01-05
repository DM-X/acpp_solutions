#ifndef list_string_guard
#define list_string_guard

#include <string>
#include <list>

class List_string {
   private:
      typedef std::list<std::string> container;
      container l;
   public: 
      typedef container::size_type size_type;
      typedef container::iterator iterator;
      typedef container::const_iterator const_iterator;
      typedef container::value_type value_type;

      List_string() = default; //def. constructor
      List_string(size_type n, std::string s = "") : l(n, s) {};
      List_string(iterator a, iterator b) : l(a, b) {};
      //List_string::~List_string() {}; //destructor
 
      iterator begin() {return l.begin();} 
      const_iterator begin() const {return l.begin();} 
      iterator end() {return l.end();} 
      const_iterator end() const {return l.end();} 
      void push_back(value_type s) {l.push_back(s);}
      void print() const;
      bool empty() const {return l.empty();}
      void clear() {l.clear();}
      size_type size() const {return l.size();}
};

#endif
