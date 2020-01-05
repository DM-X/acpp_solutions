#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::map;
using std::vector;
using std::istream;
using std::find_if;

bool space(char c);
bool not_space(char c);
vector<string> split(const string& str);
map<string, vector<int> > 
   xref(istream& in, vector<string> find_words(const string&) = split);

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
int main()
{
   map<string, vector<int> > ret = xref(cin);

   // write the results
   for (map<string, vector<int> >::const_iterator it = ret.begin();
         it != ret.end(); ++it) {
      // write the word
      cout << it->first << " occurs on line(s): ";
      // followed by one or more line numbers
      vector<int>::const_iterator line_it = it->second.begin();
      cout << *line_it; // write the first line number
      ++line_it;
      // write the rest of the line numbers, if any
      while (line_it != it->second.end()) {
         cout << ", " << *line_it;
         ++line_it;
      }
      // write a new line to separate each word from the next
      cout << endl;
   }

   return 0;
}
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
map<string, vector<int> > 
   xref(istream& in, vector<string> find_words(const string&))
{
   string line;
   int line_number = 0;
   map<string, vector<int> > ret;

   // read the next line
   while (getline(in, line)) {
      ++line_number;

      vector<string> words = find_words(line);
      for (vector<string>::const_iterator it = words.begin();
            it != words.end(); ++it)
         ret[*it].push_back(line_number);
   }
   return ret;
}
//------------------------------------------------------------------------------
bool space(char c)
{
   return isspace(c);
}
//------------------------------------------------------------------------------
bool not_space(char c)
{
   return !isspace(c);
}
//------------------------------------------------------------------------------
vector<string> split(const string& str)
{
   typedef string::const_iterator iter;
   vector<string> ret;
   iter i = str.begin();
   while (i != str.end()) {
      // ignore leading blanks
      i = find_if(i, str.end(), not_space);
      // find end of next word
      iter j = find_if(i, str.end(), space);
      // copy the characters in [i, j)
      if (i != str.end())
         ret.push_back(string(i, j));
      i = j;
   }
   return ret;
}
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
