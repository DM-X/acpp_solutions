#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

//b and e are input iterators
template <class T1, class T2> bool my_equal(T1 b, T1 e, T2 d);


int main(void) 
{
   vector<double> vd1 = {1.0, 1.0, 2.0, 5.5};
   vector<double> vd2 = {1.1, 1.0, 2.0, 5.5};

   cout << "1: " << my_equal(vd1.begin(), vd1.end(), vd2.begin()) << endl;
   cout << "2: " << my_equal(vd1.begin()+1, vd1.end(), vd2.begin()+1) << endl;
   return 0;
}

template <class T1, class T2> bool my_equal(T1 b, T1 e, T2 d)
{
   while (b != e) {
      if (*b++ != *d++) return false;
   }
   return true;
}
