#ifndef GUARD_ptr_h
#define GUARD_ptr_h

#include <iostream>

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
      void make_unique() {
         if (*refptr != 1) {
            --*refptr;
            refptr = new size_t(1);
            p = p ? p->clone() : 0;
         }
      }
      size_t get_refptr() {return *refptr;}
   private:
      T* p;
      size_t* refptr;
};

#include "ptr.cpp"
#endif
