/*Author: Daniel Maier
 *Date:  16/11/2019
 *Program description:
*/
#include <iostream> 
#include <string>
#include <vector>
#include <stdexcept>
#include <algorithm>

#include "student.hpp"
#include "student_calc.hpp"

using std::istream;
using std::string;
using std::vector;
using std::domain_error;
using std::sort;
using std::cout;
using std::cin;
using std::endl;
using std::max;

int main(int argc, char** argv)
{
   vector<Student_info> students;
   Student_info record;
   string::size_type maxlen = 0;
   // read and store the data
   while (record.read(cin)) {
      maxlen = max(maxlen, record.get_name().size());
      students.push_back(record);
   }
   // alphabetize the student records
   sort(students.begin(), students.end(), compare);
   // write the names and grades
   for (vector<Student_info>::size_type i = 0; i != students.size(); ++i) {
      cout << students[i].get_name()
           << string(maxlen + 1 - students[i].get_name().size(), ' ');
      if (students[i].get_pass()) {
         cout << "P" << endl;
      } else {
         cout << "F" << endl;
      }
   }
   return 0;
}
