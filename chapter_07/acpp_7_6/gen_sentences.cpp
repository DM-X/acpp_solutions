#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
#include <stdexcept>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::map;
using std::vector;
using std::istream;
using std::find_if;
using std::logic_error;
using std::domain_error;

typedef vector<string> rule;
typedef vector<rule> rule_collection;
typedef map<string, rule_collection> grammar;

bool space(char c);
bool not_space(char c);
vector<string> Split(const string& str);
grammar ReadGrammar(istream& in);
bool Bracketed(const string s);
void GenSentAux(const grammar& g, const string word, vector<string>& ret);
vector<string> GenSentence(const grammar& g);
int nrand(int n);
void ConstructSentence(grammar& g, string& stack_element,
                       rule& rule_stack, vector<string>& sentence);
void PushStack(const grammar& g, const string word, rule& rule_stack);

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
int main() {
   /* initialize random seed: */
   srand (time(NULL));

   grammar g = ReadGrammar(cin);

   vector<string> rule_stack;
   rule_stack.push_back("<sentence>");
   vector<string> sentence;
   string stack_element;

   while (!rule_stack.empty()) {
      stack_element = rule_stack.back();
      rule_stack.pop_back();
      ConstructSentence(g, stack_element, rule_stack, sentence);
   }

   // write the first word, if any
   vector<string>::const_iterator it = sentence.begin();
   if (!sentence.empty()) {
      cout << *it;
      ++it;
   }
   // write the rest of the words, each preceded by a space
   while (it != sentence.end()) {
      cout << " " << *it;
      ++it;
   }
   cout << endl;
   return 0;
}
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
grammar ReadGrammar(istream& in)
{
   string line;
   grammar ret;

   // read the next line
   while (getline(in, line)) {
      vector<string> words = Split(line);
      if (!words.empty()) {
         ret[words[0]].push_back(rule(words.begin() + 1, words.end()));
      }
   }
   return ret;
}
//------------------------------------------------------------------------------
void ConstructSentence(grammar& g, string& stack_element,
                       rule& rule_stack, vector<string>& sentence)
{
   cout << "deb: " << "string= " << stack_element << endl;
   if (!Bracketed(stack_element)) {
      sentence.push_back(stack_element);
   } else {
      PushStack(g, stack_element, rule_stack);
   }
}
//------------------------------------------------------------------------------
void PushStack(const grammar& g, const string word, rule& rule_stack)
{
   // locate the rule that corresponds to word
   grammar::const_iterator it = g.find(word);
   if (it == g.end())
      throw logic_error("empty rule");
   // fetch the set of possible rules
   const rule_collection& c = it->second;
   // from which we select one at random
   const rule& r = c[nrand(c.size())];
   for (rule::const_reverse_iterator i = r.rbegin(); i != r.rend(); ++i) {
      rule_stack.push_back(*i);
   }
}
//------------------------------------------------------------------------------
bool Bracketed(const string s)
{
   return (s.size() > 1 && s[0]=='<' && s[s.size()-1]=='>');
}
//------------------------------------------------------------------------------
int nrand(int n)
{
   if (n <= 0 || n > RAND_MAX)
      throw domain_error("Argument to nrand is out of range");

   const int bucket_size = RAND_MAX/n;
   int r;

   do {
      r = rand()/bucket_size;
   } while (r >= n);

   return r;
}
//------------------------------------------------------------------------------
vector<string> Split(const string& str)
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
