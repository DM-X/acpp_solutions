#include "core.hpp"

std::string Core::name() const
{
   return n;
}

double Core::grade() const
{
   return ::grade(midterm, fin, homework);
}

std::istream& Core::read_common(std::istream& in)
{
   in >> n >> midterm >> fin;
   return in;
}

std::istream& Core::read(std::istream& in)
{
   read_common(in);
   read_hw(in, homework);
   return in;
}

Core::Core() : midterm(0.0), fin(0.0)
{
}

Core::Core(std::istream& in)
{
   read(in);   
}

bool compare(const Core& c1, const Core& c2)
{
   return c1.name() < c2.name();
}

bool compare_grades(const Core& c1, const Core& c2)
{
   return c1.grade() < c2.grade();
}

bool compare_Core_ptrs(const Core* cp1, const Core* cp2)
{
   return compare(*cp1, *cp2);
}
