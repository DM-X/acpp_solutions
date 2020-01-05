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
   Str n;                //def
   n = "hi";             //assignment
   cout << n << endl;
   Str m = n;            //initialization with Str -> copy constructor
   Str name = "Daniel";  //initialization with const char* -> copy constructor
   cout << name << endl;
   Str name2 = " Maier";
   name += name2;
   cout << name << endl;

   Str w = "Wang";
   Str all = name + n + " " + w;
   cout << all << endl;

   Str s("hello");       //construct with const char*
   Str t(n);             //construct with Str 
   
   Str o;                //def
   o = m;                //assignment with Str
   n = "Maier";          //assignment with const char*
   cout << "name: " << name << endl;

   Str b = "Hello, " + name + "!";
   b += " World!";
   cout << b << endl;

   Str text;
   cin >> text;
   cout << text << endl;
   return 0;
}
