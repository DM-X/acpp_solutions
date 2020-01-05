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
   cout << "-> objects have no dynamic binding!" << endl;

   cout << "---------------------p1 = new Core------------" << endl;
   Core* p1 = new Core;

   cout << "---------------------p2 = new Grad------------" << endl;
   Core* p2 = new Grad;

   cout << "---------------------Core s1------------------" << endl;
   Core s1;

   cout << "---------------------Grad s2------------------" << endl;
   Grad s2;
   cout << "----------------------------------------------" << endl;
   cout << "----------------------------------------------" << endl;

   cout << "---------------------p1->grade()--------------" << endl;
   cout << "expect: Core::grade()" << endl;
   cout << "result: ";
   p1->grade();
   cout << "----------------------------------------------" << endl;

   cout << "---------------------p1->name()--------------" << endl;
   cout << "expect: Core::name()" << endl;
   cout << "result: ";
   p1->name();
   cout << "----------------------------------------------" << endl;

   cout << "---------------------p2->grade()--------------" << endl;
   cout << "expect: Grad::grade()" << endl;
   cout << "result: ";
   p2->grade();
   cout << "----------------------------------------------" << endl;

   cout << "---------------------p2->name()--------------" << endl;
   cout << "expect: Core::name()" << endl;
   cout << "result: ";
   p2->name();
   cout << "----------------------------------------------" << endl;

   cout << "---------------------s1->grade()--------------" << endl;
   cout << "expect: Core::grade()" << endl;
   cout << "result: ";
   s1.grade();
   cout << "----------------------------------------------" << endl;

   cout << "---------------------s1->name()--------------" << endl;
   cout << "expect: Core::name()" << endl;
   cout << "result: ";
   s1.name();
   cout << "----------------------------------------------" << endl;

   cout << "---------------------s2->grade()--------------" << endl;
   cout << "expect: Grad::grade()" << endl;
   cout << "result: ";
   s2.grade();
   cout << "----------------------------------------------" << endl;

   cout << "---------------------s2->name()--------------" << endl;
   cout << "expect: Core::name()" << endl;
   cout << "result: ";
   s2.name();
   cout << "----------------------------------------------" << endl;

   return 0;
}
