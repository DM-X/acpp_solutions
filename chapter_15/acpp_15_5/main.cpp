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

   Picture q = frame(p, '1', '1', '1');
   cout << q << endl;

   Picture q2 = frame(hcat(q, vcat(q, frame(hcat(p, q), '2', '2', '2'))));
   cout << "q2:" << endl << q2 << endl;
   q2.reframe('3', '3', '3');
   cout << "q2:" << endl << q2 << endl;
}
