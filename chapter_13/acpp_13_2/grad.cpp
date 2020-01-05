#include <algorithm>
#include <iostream>
#include "student_calc.hpp"
#include "grad.hpp"

using std::min;
using std::cout;
using std::cerr;
using std::endl;

double Grad::grade() const
{
   cout << "Grad::grade()" << endl;
   return 0.0;
   //return min(thesis, ::grade(midterm, fin, homework));
}

std::istream& Grad::read(std::istream& in)
{
   read_common(in);
   in >> thesis;
   read_hw(in, homework);
   cerr << "end of Grad:read(istream&)" << endl;
   return in;
}

Grad::Grad(): thesis(0.0)
{
   cerr << "Grad:Grad()" << endl;
}

Grad::Grad(std::istream& in)
{
   cerr << "Grad:Grad(istream&)" << endl;
   read(in);   
}
