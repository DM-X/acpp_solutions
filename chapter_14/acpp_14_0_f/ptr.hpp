#ifndef GUARD_ptr_h
#define GUARD_ptr_h

#include <iostream>
#include "vec.hpp"

template<class T> T* clone(const T* tp);
template<> Vec<char>* clone(const Vec<char>* vp);

template <class T> class Ptr {
   public:// manage reference count as well as pointer
      //constructors
      Ptr(): refptr(new size_t(1)), p(0) { }
      Ptr(T* t): refptr(new size_t(1)), p(t) { }
      //copy
      Ptr(const Ptr& h): refptr(h.refptr), p(h.p) {++*refptr;}
      //assignment
      Ptr& operator=(const Ptr&);
      //destructor
      ~Ptr();

      operator bool() const { return p; }
      T& operator*() const
      {
         if (p)
            return *p;
         throw std::runtime_error("unbound Ptr");
      }
      T* operator->() const {
         if (p)
            return p;
         throw std::runtime_error("unbound Ptr");
      }
      void make_unique();

   private:
      T* p;
      size_t* refptr;
};


#include "ptr.cpp"
#endif
