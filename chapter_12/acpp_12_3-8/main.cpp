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
   Str text1;
   cin >> text1;

   Str text2;
   cin >> text2;

   if (text1 <  text2) cout << "smaller" << endl;
   if (text1 <= text2) cout << "smaller eq" << endl;
   if (text1 >  text2) cout << "bigger" << endl;
   if (text1 >= text2) cout << "bigger eq" << endl;
   if (text1 == text2) cout << "equal" << endl;
   if (text1 != text2) cout << "unequal" << endl;

   Str text = text1 + text2;
   cout << text << endl;
   if (text) cout << "text is not empty" << endl;
   else cout << "text is empty" << endl;

   Str a;
   if (a) cout << "a is not empty" << endl;
   else cout << "a is empty" << endl;

   getline(cin, a);
   cout << a << endl;

   Str s = "Hello world";
   Str i = "nice ";
   s.insert(6, i);
   cout << s << endl;
   
   return 0;
}
