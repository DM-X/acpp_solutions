#include "student.hpp"

bool Student_info::pass() const
{
   return (mid + fin) > 60;
}

std::istream& Student_info::read(std::istream& in)
{
   in >> name >> mid >> fin;
   return in;
}

bool compare(const Student_info& x, const Student_info& y)
{
   return x.get_name() < y.get_name();
}
