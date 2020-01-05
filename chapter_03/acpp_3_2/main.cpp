#include <iostream>
#include <vector>
#include <algorithm>


using std::cout;
using std::cin;
using std::endl;
using std::vector;


int main()
{

   vector<double> grades;

   cout << "Give your grades follwed by end-of-file: ";
   double x;
   while (cin >> x) {
      grades.push_back(x);
   }
   sort(grades.begin(), grades.end());

   typedef vector<double>::size_type vec_sz;
   vec_sz size = grades.size();
   if (size==0) {
      cout << "You need to enter at least one number" << endl;
      return 1;
   }
   if (size==1) {
      cout << "q1 = " << grades[0] << endl;
      cout << "q2 = " << grades[0] << endl;
      cout << "q3 = " << grades[0] << endl;
      return 0;
   }

   vec_sz mid = size/2;

   double median = (size % 2 == 0) ? ((grades[mid] + grades[mid-1])/2.0)
                                   : grades[mid];

   double q1, q3;
   vec_sz n = size/4;
   if (size % 2 == 0) {
      vec_sz q = mid / 2;
      if (mid % 2 == 0) {
         q1 = 0.5*grades[q] + 0.5*grades[q-1];
         q3 = 0.5*grades[mid+q] + 0.5*grades[mid+q-1];
      } else {
         q1 = grades[q];
         q3 = grades[mid+q];
      }
   } else {
      if (size % 4 == 1) {
         q1 = 0.25*grades[n   - 1] + 0.75*grades[n];
         q3 = 0.75*grades[3*n    ] + 0.25*grades[3*n + 1];
      } else {
         if (size % 4 == 3) {
            cout << "n = " << n << endl;
            q1 = 0.75*grades[n      ] + 0.25*grades[n   + 1];
            q3 = 0.25*grades[3*n + 1] + 0.75*grades[3*n + 2];
         } else {
            cout << "error" << endl;
         }
      }
   }

   for (int i = 0; i != size; ++i) {
      cout << grades[i] << endl;
   }
   cout << "q1 = " << q1 << endl;
   cout << "q2 = " << median << endl;
   cout << "q3 = " << q3 << endl;

   return 0;
}
