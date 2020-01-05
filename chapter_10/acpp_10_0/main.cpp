/*Author: Daniel Maier
 * Date: /2019
 * Program description:
 * */
#include <iostream>
#include <string>

std::string letter_grade(double grade);

using std::cout;
using std::endl;
using std::string;


int main(int argc, char** argv)
{
   cout << "grade = 34 yields letter grade: " << letter_grade(34) << endl;
   cout << "grade = 84 yields letter grade: " << letter_grade(84) << endl;
   cout << "grade = 98 yields letter grade: " << letter_grade(98) << endl;
   cout << "grade = -2 yields letter grade: " << letter_grade(-2) << endl;
   return 0;
}

string letter_grade(double grade)
{
   // range posts for numeric grades
   static double const numbers[] = { //equivalent to const double
      97, 94, 90, 87, 84, 80, 77, 74, 70, 60, 0
   };
   // names for the letter grades
   //static char const * const letters[] = {
   static const char * const letters[] = { //equivalent to char const * const 
      "A+", "A", "A-", "B+", "B", "B-", "C+", "C", "C-", "D", "F"
   };
   // compute the number of grades given the size of the array
   // and the size of a single element
   static const size_t ngrades = sizeof(numbers)/sizeof(*numbers);
   // given a numeric grade, find and return the associated letter grade
   for (size_t i = 0; i < ngrades; ++i) {
      if (grade >= numbers[i])
         return letters[i];
   }
   return "?\?\?";
}
