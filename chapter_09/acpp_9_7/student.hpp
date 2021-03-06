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
      std::vector<double> homework;

   public:
      Student_info(): mid(0), fin(0) {}
      Student_info(std::istream& is) {read(is);}
      std::string get_name() const {return name;}
      std::istream& read(std::istream&);
      double grade() const;
      bool valid() const {return !homework.empty();}
      std::istream& read_hw(std::istream& in, std::vector<double>& hw);
};

bool compare(const Student_info&, const Student_info&);

#endif
