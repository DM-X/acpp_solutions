#include "student_calc.hpp"

using std::istream;
using std::vector;
using std::domain_error;
using std::sort;
using std::cout;
using std::cin;
using std::endl;

double median(vector<double> vec)
{
   typedef vector<double>::size_type vec_sz;
   vec_sz size = vec.size();
   if (size == 0)
      throw domain_error("median of an empty vector");
   sort(vec.begin(), vec.end());
   vec_sz mid =
      size / 2;
   return size % 2 == 0 ? (vec[mid] + vec[mid-1]) / 2 : vec[mid];
}

double grade(double midterm, double fin, const vector<double>& hw)
{
   if (hw.size() == 0)
      throw domain_error("student has done no homework");
   return grade(midterm, fin, median(hw));
}


double grade(double midterm, double fin, double homework)
{
   return 0.2 * midterm + 0.4 * fin + 0.4 * homework;
}

// read homework grades from an input stream into a `vector'
istream& read_hw(istream& in, vector<double>& hw)
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

