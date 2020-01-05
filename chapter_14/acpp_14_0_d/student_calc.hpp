#ifndef GUARD_student_calc_h
#define GUARD_student_calc_h

#include <iostream> 
#include <vector>
#include <algorithm>

double median(std::vector<double> vec);
double grade(double midterm, double fin, const std::vector<double>& hw);
double grade(double midterm, double fin, double homework);
std::istream& read_hw(std::istream& in, std::vector<double>& hw);

#endif
