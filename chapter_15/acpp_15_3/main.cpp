#include <iostream>
#include <vector>
#include <string>
#include "picture.hpp"

using std::cout;
using std::endl;
using std::string;
using std::vector;

int main()
{
   vector<string> vs = {"Hallo,", "World.", "This is a test image."};
   cout << vs[0] << endl;
   cout << vs[1] << endl;
   cout << vs[2] << endl;
   Picture p = vs;
   cout << p << endl;

   Picture q = frame(p, '-', '|', '#');
   cout << q << endl;

   Picture r = hcat(p, q);
   cout << frame(r) << endl;
}
