#ifndef GUARD_student_calc_h
#define GUARD_student_calc_h

#include <iostream> 
#include <vector>
#include <algorithm>

std::istream& read_hw(std::istream& in, std::vector<double>& hw);
double median(std::vector<double> vec);
double grade(double midterm, double final, const std::vector<double>& hw);
double grade(double midterm, double final, double homework);

#endif
