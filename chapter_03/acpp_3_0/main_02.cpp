#include <iostream>
#include <iomanip>    //setprecision
#include <ios>        //streamsize
#include <algorithm>  //sort
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::setprecision;
using std::string;
using std::streamsize;
using std::vector;
using std::sort;

int main()
{
   // ask for and read the student's name
   cout << "Please enter your first name: ";
   string name;
   cin >> name;
   cout << "Hello, " << name << "!" << endl;

   // ask for and read the midterm and final grades
   cout << "Please enter your midterm and final exam grades: ";
   double midterm, final_;
   cin >> midterm >> final_;

   // ask for the homework grades
   cout << "Enter all your homework grades, "
      "followed by end-of-file (CTRL + d (LINUX) and CTRL + z (WIN)): ";


   // a variable into which to read
   double x;
   vector<double> homework;

   while (cin >> x) {
      homework.push_back(x);
   }

   typedef vector<double>::size_type vec_sz;
   vec_sz size = homework.size();
   if (size==0) {
      cout << endl << "You must enter your grades. Try again..." << endl;
      return 1;
   }

   sort(homework.begin(), homework.end());

   //compute the median
   vec_sz mid = size/2;
   double median;
   if (size%2 == 0) {
      median = (homework[mid] + homework[mid-1]) / 2.0;
   } else {
      median = homework[mid];
   }

   // write the result
   streamsize prec_orig = cout.precision();
   cout << "Your final grade is " << setprecision(3)
      << 0.2 * midterm + 0.4 * final_ + 0.4 * median 
      << setprecision(prec_orig) << endl;

   return 0;
}
