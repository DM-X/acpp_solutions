#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <algorithm>
#include <stdexcept>
#include "picture.hpp"
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

Picture histogram(const vector<Student_info>& students, int bin=5);

int main()
{
   vector<Student_info> students;
   Student_info record;           

   // read and store the data
   while (record.read(cin)) {
      students.push_back(record);
   }

   // alphabetize the student records
   sort(students.begin(), students.end(), Student_info::compare);

   // write the names and grades
   cout << frame(histogram(students, 1)) << endl;
   return 0;
}

Picture histogram(const vector<Student_info>& students, int bin) {
   Picture names;
   Picture grades;

   //for each student
   for (vector<Student_info>::const_iterator it = students.begin();
         it != students.end(); ++it) {

      // create vertically concatenated pictures of the names and grades
      names  = vcat(names,  vector<string>(1, it->name()));
      grades = vcat(grades, vector<string>(1, " " + string(it->grade()/bin,'=')));
   }

   // horizontally concatenate the name and grade pictures to combine them
   return hcat(names, grades);
}
