#ifndef GUARD_student2_h
#define GUARD_student2_h

#include <iostream> 
#include <string>
#include <vector>
#include "student_calc.hpp"

class Student_info {
   private:
      std::string name;
      double mid, fin, grade;
      std::vector<double> homework;

   public:
      Student_info(): mid(0), fin(0) {}
      Student_info(std::istream& is) {read(is);}
      std::string get_name() {return name;}
      std::istream& read(std::istream&);
      double get_grade() const {return grade;}
      bool valid() const {return !homework.empty();}
};

bool compare(Student_info&, Student_info&);

#endif
