/*Author: Daniel Maier
 * Date: Sat 30 Nov 2019 11:41:51 (CET)
 * Program description:
 * */
#include <iostream>
#include <string>
#include <vector>
#include "vec.hpp"

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

   vector<int> v;
   v.push_back(1);
   v.push_back(2);
   v.push_back(3);
   v.erase(v.begin(), v.begin()+3);
   for (vector<int>::size_type i=0; i!=v.size(); ++i) {
      cout << "v (" << i << ") :" << v[i] << endl;
   }



   Vec<int> v_int2(10);
   Vec<int> v_int3;
   cout << "v_int3 size0: " << v_int3.size() << " len=" << v_int3.len() << endl;
   v_int3.push_back(1);
   cout << "v_int3 size0: " << v_int3.size() << " len=" << v_int3.len() << endl;
   v_int3.push_back(2);
   cout << "v_int3 size0: " << v_int3.size() << " len=" << v_int3.len() << endl;
   v_int3.push_back(3);
   cout << "v_int3 size0: " << v_int3.size() << " len=" << v_int3.len() << endl;
   v_int3.push_back(4);
   cout << "v_int3 size0: " << v_int3.size() << " len=" << v_int3.len() << endl;
   v_int3.push_back(5);
   cout << "v_int3 size0: " << v_int3.size() << " len=" << v_int3.len() << endl;
   for (Vec<int>::size_type i=0; i<=v_int3.len()-1; ++i) {
      cout << "3 (" << i << ") :" << v_int3[i] << endl;
   }
   cout << "--------removing-------" << endl;

   v_int3.erase(v_int3.begin()+1, v_int3.begin()+5);
   for (Vec<int>::size_type i=0; i!=v_int3.len(); ++i) {
      cout << "3 (" << i << ") :" << v_int3[i] << endl;
   }
   v_int3.clear();
   cout << "size: " << v_int3.size() << endl;
   cout << "len: "  << v_int3.len() << endl;

   //!! ATTENTION: size_type is unsigned !! -> don't do i<=v_int3.len()-1
   Vec<int>::size_type ii = v_int3.len()-1;
   cout << ii << endl;

   for (Vec<int>::size_type i=0; i!=v_int3.len(); ++i) {
      cout << "3 (" << i << ") :" << v_int3[i] << endl;
   }
   return 0;
}
