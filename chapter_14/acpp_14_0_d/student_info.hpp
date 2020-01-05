#ifndef GUARD_student_info_h
#define GUARD_student_info_h

#include <iostream>
#include <stdexcept>
#include <string>
#include "core.hpp"
#include "grad.hpp"
#include "ptr.hpp"

class Student_info { //handle class: cp is a Core pointer (also used by Grad)
   public:
      // constructors and copy control
      Student_info() { }
      Student_info(std::istream& is) { read(is); }

      // operations
      std::istream& read(std::istream&);
      void set_name(std::string name) { 
         cp.make_unique();

         if (cp) {
            cp->set_name(name);
         }
         else throw std::runtime_error("uninitialized Student");
      }
      std::string name() const {
         if (cp) return cp->name();
         else throw std::runtime_error("uninitialized Student");
      }
      double grade() const {
         if (cp) return cp->grade();
         else throw std::runtime_error("uninitialized Student");
      }
      static bool compare(const Student_info& s1, const Student_info& s2) {
         return s1.name() < s2.name();
      }
   private:
      Ptr<Core> cp;
};

#endif
