#ifndef GUARD_grad_h
#define GUARD_grad_h

#include <iostream>
#include "core.hpp"

class Grad: public Core {
   public:
      Grad();
      Grad(std::istream&);
      double grade() const;
      std::istream& read(std::istream&);
   private:
      double thesis;
};

#endif
