#ifndef GUARD_audit_h
#define GUARD_audit_h

#include <iostream>
#include "core.hpp"

class Audit: public Core {
   public:
      Audit();
      Audit(std::istream&);
      double grade() const;
      std::istream& read(std::istream&);
   protected:
      Audit* clone() const {return new Audit(*this);}
};

#endif
