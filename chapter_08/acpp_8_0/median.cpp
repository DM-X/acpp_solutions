#include <iostream>
#include <vector>
#include <algorithm>

using std::cout;
using std::endl;
using std::vector;
using std::sort;

template <class T> T median(vector<T> vec);

int main(void) 
{
   
   vector<double> vd = {1.0, 1.0, 2.0, 5.5};
   vector<int>    vi = {1, 1, 2, 5};

   cout << "median double: " << median(vd) << endl;
   cout << "median int:    " << median(vi) << endl;
   return 0;
}

template <class T> T median(vector<T> vec)
{
   typedef typename vector<T>::size_type sz;
   sz size = vec.size();
   sz mid = size/2;
   sort(vec.begin(), vec.end());

   return (size % 2 ==0) ? ((vec[mid-1] + vec[mid])/2) : (vec[mid]);
}
