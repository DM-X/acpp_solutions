#include <algorithm>
#include "student_calc.hpp"
#include "grad.hpp"

using std::min;

double Grad::grade() const
{
   return min(thesis, ::grade(midterm, fin, homework));
}

std::istream& Grad::read(std::istream& in)
{
   read_common(in);
   in >> thesis;
   read_hw(in, homework);
   return in;
}

Grad::Grad(): thesis(0.0)
{
}

Grad::Grad(std::istream& in)
{
   read(in);   
}
