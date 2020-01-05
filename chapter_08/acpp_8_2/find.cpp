#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

//b and e are input iterators
template <class T1, class T2> T1 my_find(T1 b, T1 e, T2 d);


int main(void) 
{
   vector<double> vd1 = {0.0, 1.0, 1.0, 2.0, 5.5};

   vector<double>::iterator it = my_find(vd1.begin(), vd1.end(), 2.0);
   cout << "found: " << *it << endl;
   return 0;
}

template <class T1, class T2> T1 my_find(T1 b, T1 e, T2 d)
{
   while (b != e) {
      if (*b == d) return b;
      b++;
   }
   return b;
}
