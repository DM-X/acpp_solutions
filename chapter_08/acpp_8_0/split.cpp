#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <string>

using std::cout;
using std::endl;
using std::vector;
using std::ostream_iterator;
using std::string;

template <class T>
void split(const string& str, T os);
bool space(char c) {return isspace(c);}
bool not_space(char c) {return !isspace(c);}

int main(void) 
{
   string test = {"This is a short test."};
   vector<string> vs;

   split(test, back_inserter(vs));
   copy(vs.begin(), vs.end(), ostream_iterator<string>(cout, "\n"));
   cout << endl;

   return 0;
}

template <class T> void split(const string& str, T os)
{
   typedef string::const_iterator iter;
   iter i = str.begin();
   while (i != str.end()) {
      //ignore leading blanks
      i = find_if(i, str.end(), not_space);
      // find end of next word
      iter j = find_if(i, str.end(), space);
      // copy the characters in [i, j)
      if (i != str.end())
         *os++ = string(i, j);
      // changed
      i = j;
   }
}

