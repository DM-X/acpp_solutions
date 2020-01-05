#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <algorithm>
#include <stdexcept>
#include "student_info.hpp"
#include "core.hpp"
#include "grad.hpp"

using std::cin;
using std::max;
using std::cout;
using std::endl;
using std::vector;
using std::string;
using std::streamsize;
using std::setprecision;
using std::domain_error;

int main()
{
   vector<Student_info> students;
   Student_info record;           
   char ch;
   string::size_type maxlen = 0;

   // read and store the data
   while (record.read(cin)) {
      maxlen = max(maxlen, record.name().size());
      students.push_back(record);
   }

   // alphabetize the student records
   //sort(students.begin(), students.end(), Student_info::compare);

   // write the names and grades
   for (vector<Student_info>::size_type i = 0; i != students.size(); ++i) {
      cout << students[i].name()
           << string(maxlen + 1 - students[i].name().size(), ' ');
      try {
         double final_grade = students[i].grade();
         streamsize prec = cout.precision();
         cout << setprecision(3) 
              << final_grade << " " 
              << letter_grade(final_grade)
              << setprecision(prec) << endl;
      } catch (domain_error e) {
         cout << e.what() << endl;
      }
   }

   Student_info s_u;
   Student_info s_g;

   //if (s_u.valid()) 
   //   cout << "s_u is valid" << endl;
   //else 
   //   cout << "s_u is invalid" << endl;

   //if (s_g.valid()) 
   //   cout << "s_g is valid" << endl;
   //else 
   //   cout << "s_g is invalid" << endl;


   if (students[0].valid()) 
      cout << "s0 is valid" << endl;
   else 
      cout << "s0 is invalid" << endl;

   if (students[1].valid()) 
      cout << "s1 is valid" << endl;
   else 
      cout << "s1 is invalid" << endl;
   
   if (students[3].valid()) 
      cout << "s3 is valid" << endl;
   else 
      cout << "s3 is invalid" << endl;

   if (students[4].valid()) 
      cout << "s4 is valid" << endl;
   else 
      cout << "s4 is invalid" << endl;

   return 0;
}
