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

template<class T>
  T median(std::vector<T> v);
template<class T>
  T median(T* arr, size_t size);

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
   cout << "median of test_v: " << median(test_v) << endl;
   for (int i=0; i<=4; ++i) {
      cout << "test_v[" << i << "] = " << test_v[i] << endl;
   }
   cout << "median of test_a: " << median(test_a, 5) << endl;
   for (int i=0; i<=4; ++i) {
      cout << "test_a[" << i << "] = " << test_a[i] << endl;
   }
   return 0;
}

template<class T>
  T median(vector<T> v)
{
   typedef typename vector<T>::size_type vec_sz;
   vec_sz size = v.size();
   if (size == 0) {
      throw domain_error("median of an empty vector");
   }
   sort(v.begin(), v.end());
   vec_sz mid = size/2;
   return size % 2 == 0 ? (v[mid] + v[mid-1]) / 2 : v[mid];
}

template<class T>
  T median(T arr[], size_t size)
{
   if (size == 0) {
      throw domain_error("median of an empty array");
   }

   T arr2[size];
   for (size_t i=0; i<=size; ++i) {
      arr2[i] = arr[i];
   }
   sort(arr2, arr2 + size);
   size_t mid = size/2;
   return size % 2 == 0 ? (arr2[mid] + arr2[mid-1]) / 2 : arr2[mid];
}
