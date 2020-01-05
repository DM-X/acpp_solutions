#ifndef vec_guard
#define vec_guard

#include <memory>

template <class T> class Vec {
   public:
      typedef T* iterator;
      typedef const T* const_iterator;
      typedef size_t size_type;
      typedef T value_type; 

      Vec() {create();}
      explicit Vec(size_type n, const T& t = T()) {create(n, t);}
      Vec(const Vec& v) {create(v.begin(), v.end());} //copy

      Vec& operator=(const Vec& v);
      ~Vec() {uncreate();}


      value_type& operator[](size_type i) {return data[i];}
      const value_type& operator[](size_type i) const {return data[i];}

      void push_back(const value_type& t) {
         if (avail == limit) grow();
         unchecked_append(t);
      }

      size_type size() const {return limit - data;}

      iterator begin() {return data;}
      const_iterator begin() const {return data;}
      iterator end() {return limit;}
      const_iterator end() const {return limit;}
   private:
      iterator data;
      iterator avail;
      iterator limit;

      std::allocator<T> alloc;

      void create();
      void create(size_type n, const value_type& val);
      void create(const_iterator a, const_iterator b);

      void uncreate();
      
      void grow();
      void unchecked_append(const value_type& t);
};

#endif
