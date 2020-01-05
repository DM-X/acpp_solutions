/*Author: Daniel Maier
 * Date: Thu 05 Dec 2019 18:32:57 (CET)
 * Program description:
 * */
#include <iostream>
#include "str.hpp"

using std::cout;
using std::cin;
using std::endl;

int main(int argc, char** argv)
{
   Str text;
   cin >> text;
   cout << text << endl;

   cout << "applying c_str():" << endl;
   cout << "you wrote: " << text.c_str() << "-" << endl;

   cout << "applying c_data():" << endl;
   cout << "you wrote: " << text.c_data() << "-" << endl;

   cout << "applying c_copy():" << endl;
   char* my_text = new char[20];
   text.c_copy(my_text, 20);
   cout << "you wrote: " << my_text << "-" << endl;
   delete my_text;

   return 0;
}
