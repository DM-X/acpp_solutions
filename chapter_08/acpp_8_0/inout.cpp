#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::sort;
using std::istream_iterator;
using std::ostream_iterator;

int main(void) 
{
   vector<int> vi;

   copy(istream_iterator<int>(cin), istream_iterator<int>(), back_inserter(vi));

   copy(vi.begin(), vi.end(), ostream_iterator<int>(cout, "\n"));
   cout << endl;

   return 0;
}
