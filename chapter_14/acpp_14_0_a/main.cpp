#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <algorithm>
#include <stdexcept>
#include "core.hpp"
#include "grad.hpp"
#include "handle.hpp"

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
   vector< Handle<Core> > students;
   Handle<Core> record;           
   char ch;
   string::size_type maxlen = 0;

   // read and store the data
   while (cin >> ch) {
      if (ch == 'U')
         record = new Core; //constructor: Handle(T* t):p(t){} impl. converts
      else                  //Core* to Handle<Core>
         record = new Grad;

      record->read(cin);
      maxlen = max(maxlen, record->name().size());
      students.push_back(record);
   }

   // alphabetize the student records
   sort(students.begin(), students.end(), compare_Core_handles);

   // write the names and grades
   for (vector<Core*>::size_type i = 0; i != students.size(); ++i) {
      cout << students[i]->name()
           << string(maxlen + 1 - students[i]->name().size(), ' ');
      try {
         double final_grade = students[i]->grade();
         streamsize prec = cout.precision();
         cout << setprecision(3) << final_grade
            << setprecision(prec) << endl;
      } catch (domain_error e) {
         cout << e.what() << endl;
      }
      //no delete statement
   }
   return 0;
}
