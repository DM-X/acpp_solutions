#ifndef GUARD_core_h
#define GUARD_core_h

#include <vector>
#include <iostream>
#include "student_calc.hpp"

class Core {
   friend class Student_info;
   public:
      Core();
      Core(std::istream&);
      virtual ~Core() {};
      std::string name() const;
      virtual std::istream& read(std::istream&);
      virtual double grade() const;
   protected:
      virtual Core* clone() const {return new Core(*this);}
      std::istream& read_common(std::istream&);
      double midterm, fin;
      std::vector<double> homework;
   private:
      std::string n;
};

bool compare(const Core& c1, const Core& c2);
bool compare_grades(const Core& c1, const Core& c2);
bool compare_Core_ptrs(const Core* cp1, const Core* cp2);

#endif
