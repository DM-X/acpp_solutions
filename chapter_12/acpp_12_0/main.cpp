/*Author: Daniel Maier
 * Date: Thu 05 Dec 2019 18:32:57 (CET)
 * Program description:
 * */
#include <iostream>
#include <string>
#include <vector>
#include "str.hpp"

using std::cout;
using std::endl;
using std::string;
using std::vector;

int main(int argc, char** argv)
{
   Str n;                //def
   Str m = n;            //initialization with Str -> copy constructor
   Str name = "Daniel";  //initialization with const char* -> copy constructor
   Str s("hello");       //construct with const char*
   Str t(n);             //construct with Str 
   
   Str o;                //def
   o = m;                //assignment with Str
   n = "Maier";          //assignment with const char*
   cout << "name: " << name << endl;

   Str w = "Wang";

   Str all = name + " " + n + " " + w;
   cout << all << endl;

   Str b = "Hello, " + name + "!";
   b += " World!";
   cout << b << endl;
   return 0;
}
