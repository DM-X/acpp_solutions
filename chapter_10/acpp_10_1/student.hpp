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
      std::string l_grade;

   public:
      Student_info(): mid(0), fin(0) {}
      Student_info(std::istream& is) {read(is);}
      std::string get_name() const {return name;}
      std::istream& read(std::istream&);
      std::string letter_grade(double grade);
      std::string get_lgrade() const {return l_grade;}

};

bool compare(const Student_info&, const Student_info&);

#endif
