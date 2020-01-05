#ifndef vec_guard
#define vec_guard

#include <memory>
#include <exception>

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
      size_type len()  const {return avail - data;}

      iterator begin() {return data;}
      const_iterator begin() const {return data;}
      iterator end() {return limit;}
      const_iterator end() const {return limit;}

      void erase(iterator beg) {erase(beg, beg+1);}
      void erase(iterator beg, iterator end);
      void clear();
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

template <class T> Vec<T>& Vec<T>::operator=(const Vec& rhs) {
   if (this != &rhs) {
      uncreate();
      create(rhs.begin(), rhs.end());
   }
   return *this;
}

template <class T> void Vec<T>::create() {
   data = avail = limit = 0;
}
template <class T> void Vec<T>::create(size_type n, const T& val) {
   data = alloc.allocate(n);
   avail = limit = data + n;
   std::uninitialized_fill(data, limit, val);
}
template <class T> void Vec<T>::create(const_iterator a, const_iterator b) {
   data = alloc.allocate(b-a);
   avail = limit = std::uninitialized_copy(a, b, data); 
}

template <class T> void Vec<T>::uncreate() {
   if (data) {
      for (iterator it=avail-1; it>=data; --it) {
         alloc.destroy(it);
      }
      alloc.deallocate(data, limit-data);
   }
   data = avail = limit = 0;
}

template <class T> void Vec<T>::grow()
{
   size_type new_size = std::max(2*(limit-data), std::ptrdiff_t(1));
   iterator new_data = alloc.allocate(new_size);
   iterator new_avail = std::uninitialized_copy(data, avail, new_data); 

   uncreate();

   data  = new_data;
   avail = new_avail;
   limit = new_data + new_size; 
}

template <class T> void Vec<T>::unchecked_append(const value_type& val)
{
   alloc.construct(avail++, val);
}

template <class T> void Vec<T>::erase(iterator beg, iterator end)
{
   size_type size = limit-data;
   iterator new_data  = alloc.allocate(limit-data);
   iterator second    = std::uninitialized_copy(data, beg,   new_data); 
   iterator new_avail = std::uninitialized_copy(end,  avail, second); 

   uncreate();

   data  = new_data;
   avail = new_avail;
   limit = new_data + size; 
}

template <class T> void Vec<T>::clear()
{
   uncreate();
}

#endif
