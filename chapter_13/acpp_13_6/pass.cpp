#include <iostream>
#include "pass.hpp"

using std::cout;
using std::endl;

bool Pass::passed() const {return (grade() >= 60);}

double Pass::grade() const
{
   if (homework.empty()) {
      return 0.5 * midterm + 0.5 * fin;
   } else {
      return ::grade(midterm, fin, homework);
   }
}

std::istream& Pass::read(std::istream& in)
{
   read_common(in);
   read_hw(in, homework);
   return in;
}

Pass::Pass()
{
   //cout << "Pass:Pass()" << endl;
}

Pass::Pass(std::istream& in)
{
   read(in);
}
