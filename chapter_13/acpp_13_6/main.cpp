#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <algorithm>
#include <stdexcept>
#include "student_info.hpp"

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
   sort(students.begin(), students.end(), Student_info::compare);

   // write the names and grades
   for (vector<Student_info>::size_type i = 0; i != students.size(); ++i) {
      cout << students[i].name()
           << string(maxlen + 1 - students[i].name().size(), ' ');
      try {
         double final_grade = students[i].grade();
         char   type        = students[i].get_type();
         streamsize prec = cout.precision();
         if (type=='A') {
            cout << "auditing" << endl;
            continue;
         }
         if (type=='P') {
            if (students[i].grade() >= 60) {
               cout << "passed" << endl;
            } else {
               cout << "not passed" << endl;
            }
            continue;
         }
         cout << setprecision(3) << final_grade
              << setprecision(prec) << endl;
      } catch (domain_error e) {
         cout << e.what() << endl;
      }
   }
   return 0;
}
