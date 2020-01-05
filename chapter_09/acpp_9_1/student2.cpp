#include "student2.hpp"

std::istream& Student_info::read(std::istream& in)
{
   in >> name >> mid >> fin;
   read_hw(in, homework);
   grade = ::grade(mid, fin, homework);
   return in;
}

bool compare(const Student_info& x, const Student_info& y)
{
   return x.get_name() < y.get_name();
}
