#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <algorithm>
#include <stdexcept>
#include "core.hpp"
#include "grad.hpp"
#include "ref_handle.hpp"
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

void PrintStudent(Student_info& s, string::size_type maxlen);

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
      PrintStudent(students[i], maxlen);
   }

   Student_info test1 = students[0];
   cout << "copy test1 into test2" << endl;
   Student_info test2 = test1; //copy
   cout << "---end" << endl;
   Student_info test3 = test1; //copy

   cout << "test1:" << endl;
   PrintStudent(test1, maxlen);
   cout << "test2:" << endl;
   PrintStudent(test2, maxlen);
   cout << "test3:" << endl;
   PrintStudent(test3, maxlen);

   cout << "test1 = students[1]" << endl;
   test1 = students[1];

   cout << "test1:" << endl;
   PrintStudent(test1, maxlen);
   cout << "test2:" << endl;
   PrintStudent(test2, maxlen);
   cout << "test3:" << endl;
   PrintStudent(test3, maxlen);

   cout << "students[0] = students[2]" << endl;
   students[0] = students[2];

   cout << "test1:" << endl;
   PrintStudent(test1, maxlen);
   cout << "test2:" << endl;
   PrintStudent(test2, maxlen);
   cout << "test3:" << endl;
   PrintStudent(test3, maxlen);

   cout << "test2.set_name(\"Hans\")" << endl;
   test2.set_name("Hans");

   cout << "test1:" << endl;
   PrintStudent(test1, maxlen);
   cout << "test2:" << endl;
   PrintStudent(test2, maxlen);
   cout << "test3:" << endl;
   PrintStudent(test3, maxlen);

   return 0;
}

void PrintStudent(Student_info& s, string::size_type maxlen)
{
   cout << s.name()
        << string(maxlen + 1 - s.name().size(), ' ');
   try {
      double final_grade = s.grade();
      streamsize prec = cout.precision();
      cout << setprecision(3) << final_grade
           << setprecision(prec) << endl;
   } catch (domain_error e) {
      cout << e.what() << endl;
   }
}
