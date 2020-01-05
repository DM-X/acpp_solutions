#include "student.hpp"

double Student_info::grade() const
{
   return ::grade(mid, fin, homework);
}

std::istream& Student_info::read(std::istream& in)
{
   in >> name >> mid >> fin;
   read_hw(in, homework);
   return in;
}

bool compare(const Student_info& x, const Student_info& y)
{
   return x.get_name() < y.get_name();
}
