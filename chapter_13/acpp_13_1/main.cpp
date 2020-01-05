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
   cout << "-> base class constructor is run each time a " << endl;
   cout << "   derived class is constructed." << endl;
   //vector<Student_info> students;
   //Student_info record;           
   //char ch;
   //string::size_type maxlen = 0;

   //// read and store the data
   //while (record.read(cin)) {
   //   cout << "reading..." << endl;
   //   maxlen = max(maxlen, record.name().size());
   //   students.push_back(record);
   //   cout << "       ...loop" << endl;
   //}

   //// alphabetize the student records
   //sort(students.begin(), students.end(), Student_info::compare);

   //// write the names and grades
   //for (vector<Student_info>::size_type i = 0; i != students.size(); ++i) {
   //   cout << students[i].name()
   //        << string(maxlen + 1 - students[i].name().size(), ' ');
   //   try {
   //      double final_grade = students[i].grade();
   //      streamsize prec = cout.precision();
   //      cout << setprecision(3) << final_grade
   //           << setprecision(prec) << endl;
   //   } catch (domain_error e) {
   //      cout << e.what() << endl;
   //   }
   //}

   cout << "---------------------Core c1-----------------------" << endl;
   Core c1;

   cout << "---------------------Grad g1-----------------------" << endl;
   Grad g1;

   cout << "---------------------Core c2(cin)------------------" << endl;
   Core c2(cin);

   cout << "---------------------Grad g2(cin)------------------" << endl;
   Grad g2(cin);
   return 0;
}
