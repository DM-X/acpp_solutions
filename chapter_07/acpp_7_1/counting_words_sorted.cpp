#include <iostream>
#include <string>
#include <map>
#include <algorithm>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::map;
using std::sort;
using std::pair;
using std::vector;

bool comp(const pair<string, int>& a, const pair<string, int>& b);

int main()
{
   string s;
   map<string, int> counters;
   // store each word and an associated counter
 
   // read the input, keeping track of each word and how often we see it
   while (cin >> s) {
      ++counters[s];
   }

   //sort by values
   vector<pair<string, int> > v(counters.begin(), counters.end());

   sort(v.begin(), v.end(), comp);

   // write the words and associated counts
   for (map<string, int>::const_iterator it = counters.begin();
         it != counters.end(); ++it) {
      cout << it->first << "\t\t" << it->second << endl;
   }

   cout << "------------sorted------------" << endl;

   // write the words and associated counts
   for (vector<pair<string, int> >::const_iterator it = v.begin();
         it != v.end(); ++it) {
      cout << it->first << "\t\t" << it->second << endl;
   }

   return 0;
}

bool comp(const pair<string, int>& a, const pair<string, int>& b) {
   return a.second < b.second;
}
