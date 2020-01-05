#include <algorithm>
#include <iostream>
#include "student_calc.hpp"
#include "grad.hpp"

using std::min;
using std::cout;
using std::endl;

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

bool Grad::valid() const
{
   cout << "Grad::valid()" << endl;
   cout << "thesis= " << thesis << endl;
   return (thesis!=0.0 && this->Core::valid());
}
