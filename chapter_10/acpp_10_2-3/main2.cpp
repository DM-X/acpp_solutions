/*Author: Daniel Maier
 * Date: Sun 17 Nov 2019 20:42:24 (CET)
 * Program description:
 * */
#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>
#include <algorithm>
#include <cstddef>

template<class it, class T>
  T median(it begin, it end, const T initialElement);

using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::domain_error;
using std::sort;
using std::size_t;

int main(int argc, char** argv)
{
   vector<double> test_v = {2.0, 1, 4.1, 5.1, 6.2};
   double test_a[] = {6.2, 1, 4.1, 5.1, 15.2};
   cout << "median of test_v: " << median(test_v.begin(), test_v.end(), test_v[0]) << endl;
   for (int i=0; i<=4; ++i) {
      cout << "test_v[" << i << "] = " << test_v[i] << endl;
   }
   cout << "median of test_a: " << median(test_a, test_a+5, test_a[0]) << endl;
   for (int i=0; i<=4; ++i) {
      cout << "test_a[" << i << "] = " << test_a[i] << endl;
   }
   return 0;
}

template<class it, class T>
  T median(it begin, it end, const T initialElement)
{
   if(begin == end)
      throw domain_error("median of an empty container");
   vector<T> v(begin, end);
   typename vector<T>::difference_type size = v.end() - v.begin();
   sort(v.begin(), v.end());
   typename vector<T>::const_iterator mid = v.begin() + size/2;
   return size % 2 == 0 ? (*mid + *(mid-1)) / 2 : *mid;
}
