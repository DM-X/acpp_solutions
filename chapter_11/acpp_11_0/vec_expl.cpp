#include "vec_expl.hpp"

using std::ptrdiff_t;
using std::uninitialized_copy;
using std::uninitialized_fill;
using std::max;

//uninstantiated template definitions are not put into object (.obj) files!!
template class Vec<int>; //explicit instantiation

template <class T> Vec<T>& Vec<T>::operator=(const Vec& rhs) {
   if (&rhs != this) {
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
   uninitialized_fill(data, limit, val);
}
template <class T> void Vec<T>::create(const_iterator a, const_iterator b) {
   data = alloc.allocate(b-a);
   avail = limit = uninitialized_copy(a, b, data); 
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
   size_type new_size = max(2*(limit-data), ptrdiff_t(1));
   iterator new_data = alloc.allocate(new_size);
   iterator new_avail = uninitialized_copy(data, avail, new_data); 

   uncreate();

   data  = new_data;
   avail = new_avail;
   limit = new_data + new_size; 
}

template <class T> void Vec<T>::unchecked_append(const value_type& val)
{
   alloc.construct(avail++, val);
}
