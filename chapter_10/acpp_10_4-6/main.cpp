/*Author: Daniel Maier
 * Date: Sun 17 Nov 2019 23:08:35 (CET)
 * Program description:
 * */
#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <algorithm>
#include "list_string.hpp"

using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::list;
using std::find_if;

bool space(char c);
bool not_space(char c);
void split(const string& str, List_string& li);

int main(void)
{
   List_string li;
   string s1 = "Hallo";
   string s2 = "Welt";
   li.push_back(s1);
   li.push_back(s2);

   li.print();
   List_string::size_type len = li.size();
   cout << "len1 = " << len << endl;


   List_string li2;
   if (li2.empty()) cout << "list2 is empty" << endl; 
   else li2.print();
   li2.print();


   List_string li3(10, "test");
   li3.print();
   List_string::size_type len3 = li3.size();
   cout << "len3 = " << len3 << endl;

   List_string li3b(10);
   li3b.print();
   List_string::size_type len3b = li3b.size();
   cout << "len3b = " << len3b << endl;


   List_string::iterator a = li3.begin();
   List_string::iterator b = li3.end();
   List_string li4(a, b);
   li4.print();

   List_string li5(li4);
   li5.print();

   li5 = li3b;
   li5.print();

   li5.clear();
   li5.print();

   li5.push_back("something new");
   li5.print();

   List_string::iterator a1 = li.begin();
   cout << "a1: " << *a1 << endl;
   a1++;
   cout << "a1: " << *a1 << endl;
   a1--;
   cout << "a1: " << *a1 << endl;
   cout << "a1->size(): " << a1->size() << endl;
   cout << "len1 = " << li.size() << endl;

   string s = "hello, this is a test.";
   split(s, li5); 
   li5.print();

   return 0;
}

void split(const string& str, List_string& li)
{
   typedef string::const_iterator iter;
   iter i = str.begin();
   while (i != str.end()) {
      // ignore leading blanks
      i = find_if(i, str.end(), not_space);
      // find end of next word
      iter j = find_if(i, str.end(), space);
      // copy the characters in [i, j)
      if (i != str.end())
         li.push_back(string(i, j));
      i = j;
   }
}

bool space(char c)
{
   return isspace(c);
}
bool not_space(char c)
{
return !isspace(c);
}
