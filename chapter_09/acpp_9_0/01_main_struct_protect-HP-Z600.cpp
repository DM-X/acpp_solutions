/*Author: Daniel Maier
 *Date:  15/11/2019
 *Program description:
*/
#include <iostream> 
#include <vector>
#include <stdexcept>
#include <algorithm>

using std::istream;
using std::vector;
using std::domain_error;
using std::sort;
using std::cout;
using std::cin;
using std::endl;

struct Student_info {
   private:
      std::string name;
      double midterm, final;
      std::vector<double> homework;

   public:
      std::istream& set_name(std::istream& in) {in >> name};
      std::string get_name() {return name};
      std::istream& set_mid(std::istream& in) {in >> mid};
      double get_mid() {return mid};
      std::istream& set_fin(std::istream& in) {in >> fin};
      double get_fin() {return fin};
      std::istream& read(std::istream&);
      double grade() const;
};

istream& read_hw(istream& in, vector<double>& hw);
double median(vector<double> vec);
double grade(double midterm, double final, const vector<double>& hw);
double grade(double midterm, double final, double homework);

int main(int argc, char** argv)
{
   Student_info s;
   s.read(cin);
   cout << "the final grade for " << s.name << " is: " << s.grade() << endl;
   cout << "BUT: I still can change the internal state of the object" << endl;
   cout << "     Changing the name to \"Bert\"" << endl;
   s.name = "Bert";
   cout << "the final grade for " << s.name << " is: " << s.grade() << endl;
   return 0;
}
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
double Student_info::grade() const
{
   return ::grade(midterm, final, homework);
}

istream& Student_info::read(istream& in)
{
   in >> set_name() >> set_midterm() >> set_final();
   read_hw(in, homework);
   return in;
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

double grade(double midterm, double final, const vector<double>& hw)
{
   if (hw.size() == 0)
      throw domain_error("student has done no homework");
   return grade(midterm, final, median(hw));
}


double grade(double midterm, double final, double homework)
{
   return 0.2 * midterm + 0.4 * final + 0.4 * homework;
}
