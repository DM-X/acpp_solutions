#ifndef GUARD_pass_h
#define GUARD_pass_h

#include <iostream>
#include "core.hpp"

class Pass: public Core {
   public:
      Pass();
      Pass(std::istream&);
      double grade() const;
      bool passed() const;
      std::istream& read(std::istream&);
   protected:
      Pass* clone() const {return new Pass(*this);}
};

#endif
