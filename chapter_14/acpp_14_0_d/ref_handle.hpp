#ifndef GUARD_ref_handle_h
#define GUARD_ref_handle_h

#include <iostream>

template <class T> class Ref_handle {
   public:// manage reference count as well as pointer
      //constructors
      Ref_handle(): refptr(new size_t(1)), p(0) { }
      Ref_handle(T* t): refptr(new size_t(1)), p(t) { }
      //copy
      Ref_handle(const Ref_handle& h): refptr(h.refptr), p(h.p) {
         //std::cout << "copy" << std::endl;
         ++*refptr;
         //std::cout << "refptr= " << *refptr << std::endl;
      }
      //assignment
      Ref_handle& operator=(const Ref_handle&);
      //destructor
      ~Ref_handle();

      operator bool() const { return p; }
      T& operator*() const
      {
         if (p)
            return *p;
         throw std::runtime_error("unbound Ref_handle");
      }
      T* operator->() const {
         if (p)
            return p;
         throw std::runtime_error("unbound Ref_handle");
      }
   private:
      T* p;
      size_t* refptr;
};

#include "ref_handle.cpp"
#endif
