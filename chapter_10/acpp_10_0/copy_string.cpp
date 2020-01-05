/*Author: Daniel Maier
Date: Sun 17 Nov 2019 18:29:43 (CET)
Program description:
*/
#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <algorithm>

char* duplicate_chars(const char* p);

using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::copy;

int main(int argc, char** argv)
{
   const char s[] = "Hallo";
   char* s2;
   s2 = duplicate_chars(s);
   string s3 = s;
   string s4 = s2;
   cout << "s : " << s << endl;
   cout << "s2: " << s2 << endl;
   cout << "s3: " << s3 << endl;
   cout << "s4: " << s4 << endl;

   delete s2;
   return 0;
}

char* duplicate_chars(const char* p)
{
   size_t length = strlen(p) + 1;
   char* result = new char[length];

   copy(p, p+length, result);
   return result;
}
