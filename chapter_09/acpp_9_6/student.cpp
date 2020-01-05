#include "student.hpp"

std::istream& Student_info::read(std::istream& in)
{
   in >> name >> mid >> fin;
   pass = (mid + fin) > 60;
   return in;
}

bool compare(const Student_info& x, const Student_info& y)
{
   return (x.get_pass() > y.get_pass() ||
           x.get_name() < y.get_name());
}
