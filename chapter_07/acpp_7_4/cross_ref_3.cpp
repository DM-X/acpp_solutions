#include <iostream>
#include <iomanip>
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
using std::pair;

typedef struct{
   vector<int> vec;
   int cnt;
} xref_t;

bool space(char c);
bool not_space(char c);
vector<string> split(const string& str);
bool comp(const pair<string, xref_t>& a, const pair<string, xref_t>& b);
map<string, xref_t> 
   xref(istream& in, vector<string> find_words(const string&) = split);
void WriteMapResult(map<string, xref_t> ret);
void WriteVecResult(vector<pair<string, xref_t> > ret);
template<class T>
void WriteResult(T b, T e);

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
int main()
{
   map<string, xref_t> ret = xref(cin);

   //WriteMapResult(ret);
   WriteResult(ret.begin(), ret.end());

   cout << "------------sorted------------" << endl;

   vector<pair<string, xref_t> > ret_sorted(ret.begin(), ret.end());
   sort(ret_sorted.begin(), ret_sorted.end(), comp);

   //WriteVecResult(ret_sorted);
   WriteResult(ret_sorted.begin(), ret_sorted.end());

   return 0;
}
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
map<string, xref_t> 
   xref(istream& in, vector<string> find_words(const string&))
{
   string line;
   int line_number = 0;
   map<string, xref_t> ret;

   // read the next line
   while (getline(in, line)) {
      ++line_number;

      vector<string> words = find_words(line);
      for (vector<string>::const_iterator it = words.begin();
            it != words.end(); ++it) {
         ret[*it].vec.push_back(line_number);
         ret[*it].cnt += 1;
      }
   }
   return ret;
}
//------------------------------------------------------------------------------
void WriteMapResult(map<string, xref_t> ret) 
{
   for (map<string, xref_t>::const_iterator it = ret.begin();
         it != ret.end(); ++it) {
      // write the word
      cout << it->first << " occurs on line(s): ";
      // followed by one or more line numbers
      vector<int>::const_iterator line_it = it->second.vec.begin();
      cout << *line_it; // write the first line number
      ++line_it;
      // write the rest of the line numbers, if any
      while (line_it != it->second.vec.end()) {
         cout << ", " << *line_it;
         ++line_it;
      }
      //cout << " -> " << it->second.cnt;
      // write a new line to separate each word from the next
      cout << endl;
   }
}
//------------------------------------------------------------------------------
void WriteVecResult(vector<pair<string, xref_t> > ret) 
{
   int len, cnt, width=3;
   for (vector<pair<string, xref_t> >::const_iterator it = ret.begin();
         it != ret.end(); ++it) {
      // write the word
      if (it->second.cnt == 1) {
         cout << it->first << " occurs on line: ";
         len = 17 + (it->first).length();
      } else {
         cout << it->first << " occurs on lines: ";
         len = 18 + (it->first).length();
      }
      // followed by one or more line numbers
      vector<int>::const_iterator line_it = it->second.vec.begin();
      cnt = 0;
      while (line_it != it->second.vec.end()-1) {
         cout << std::setw(width) << *line_it << ", ";
         ++line_it;
         ++cnt;
         if (cnt%15==0) cout << std::endl << std::string(len, ' ');
      }
      cout << std::setw(width) << *line_it << endl; //write the last line number
   }
}
//------------------------------------------------------------------------------
template<class T>
void WriteResult(T b, T e) 
{
   int len, cnt, width=3;
   while (b != e) {
      // write the word
      if (b->second.cnt == 1) {
         cout << b->first << " occurs on line: ";
         len = 17 + (b->first).length();
      } else {
         cout << b->first << " occurs on lines: ";
         len = 18 + (b->first).length();
      }
      // followed by one or more line numbers
      vector<int>::const_iterator line_it = b->second.vec.begin();
      cnt = 0;
      while (line_it != b->second.vec.end()-1) {
         cout << std::setw(width) << *line_it << ", ";
         ++line_it;
         ++cnt;
         if (cnt%15==0) cout << std::endl << std::string(len, ' ');
      }
      cout << std::setw(width) << *line_it << endl; //write the last line number
      ++b;
   }
}
//------------------------------------------------------------------------------
bool comp(const pair<string, xref_t>& a, const pair<string, xref_t>& b)
{
   return a.second.cnt < b.second.cnt;
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
        // vector<int>* me = &(ret[*it]); //map entry
        // if (find(me->begin(), me->end(), line_number) == me->end()) 
        //    me->push_back(line_number);
