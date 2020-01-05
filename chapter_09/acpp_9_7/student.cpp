#include "student.hpp"

using std::istream;
using std::vector;

double Student_info::grade() const
{
   return ::grade(mid, fin, homework);
}

istream& Student_info::read(istream& in)
{
   in >> name >> mid >> fin;
   read_hw(in, homework);
   return in;
}

bool compare(const Student_info& x, const Student_info& y)
{
   return x.get_name() < y.get_name();
}

// read homework grades from an input stream into a `vector'
istream& Student_info::read_hw(istream& in, vector<double>& hw)
{
   if (in) {
      // get rid of previous contents
      hw.clear();
      // read homework grades
      double x;
      while (in >> x)
         hw.push_back(x);
      // clear the stream so that input will work for the next student
      in.clear();
   }
   return in;
}

