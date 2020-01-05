#ifndef GUARD_handle_h
#define GUARD_handle_h

#include "core.hpp"
#include <stdexcept>

template <class T> class Handle {
   public:
      Handle(): p(0) { }
      Handle(const Handle& s): p(0) { if (s.p) p = s.p->clone(); }
      Handle& operator=(const Handle& rhs);
      ~Handle() { delete p; }
      Handle(T* t): p(t) { }
      operator bool() const { return p; }
      T& operator*() const;
      T* operator->() const;
   private:
      T* p;
};

#include "handle.cpp"
#endif
