/*Author: Daniel Maier
 * Date: Sat 30 Nov 2019 11:41:51 (CET)
 * Program description:
 * */
#include <iostream>
#include <string>
#include <vector>
#include "vec_expl.hpp"

using std::cout;
using std::endl;
using std::string;
using std::vector;

int main(int argc, char** argv)
{
   Vec<int> v_int;
   Vec<int> v_int2(10);
   Vec<int> v_int3(3, 5);

   for (Vec<int>::size_type i=0; i<=v_int2.size()-1; ++i) {
      cout << v_int2[i] << endl;
   }
   for (Vec<int>::size_type i=0; i<=v_int3.size()-1; ++i) {
      cout << v_int3[i] << endl;
   }
   v_int3.push_back(444);
   for (Vec<int>::size_type i=0; i<=v_int3.size()-1; ++i) {
      cout << v_int3[i] << endl;
   }
   v_int3.push_back(555);
   for (Vec<int>::size_type i=0; i<=v_int3.size()-1; ++i) {
      cout << v_int3[i] << endl;
   }
   return 0;
}
