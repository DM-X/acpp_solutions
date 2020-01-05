/*Author: Daniel Maier
 * Date: Sat 30 Nov 2019 11:41:51 (CET)
 * Program description:
 * */
#include <iostream>
#include <string>
#include <vector>
#include "vec_impl.hpp"

using std::cout;
using std::endl;
using std::string;
using std::vector;

int main(int argc, char** argv)
{
   Vec<int> v_int;
   v_int.push_back(7);
   cout << "v_int size: " << v_int.size() << endl;
   cout << "v_int[0]: "   << v_int[0] << endl;
   Vec<int>::iterator v_it = v_int.begin(); 
   cout << " v_it = " << v_it << endl;
   cout << "*v_it = " << *v_it << endl;
   *v_it = 8;
   cout << "*v_it = " << *v_it << endl;
   cout << "v_int[0]: "   << v_int[0] << endl;

   Vec<int>::const_iterator v_cit = v_int.begin(); 
   cout << " v_cit = " << v_cit << endl;
   cout << "*v_cit = " << *v_cit << endl;


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

   Vec<int> a(2, 3);
   Vec<int> b=a;  //copy constructor
   b = a;         //assignment
   for (Vec<int>::size_type i=0; i<=b.size()-1; ++i) {
      cout << "b: " << b[i] << endl;
   }
   return 0;
}
