#ifndef GUARD_student_h
#define GUARD_student_h

#include <iostream> 
#include <string>
#include <vector>
#include "student_calc.hpp"

struct Student_info {
   private:
      std::string name;
      double mid, fin;
      bool pass;

   public:
      Student_info(): mid(0), fin(0), pass(false) {}
      Student_info(std::istream& is) {read(is);}
      std::string get_name() const {return name;}
      std::istream& read(std::istream&);
      bool get_pass() const {return pass;}
};

bool compare(const Student_info&, const Student_info&);

#endif
