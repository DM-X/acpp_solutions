#include <iostream>
#include <vector>
#include <numeric>

int main(void)
{
   std::vector<double> v(3, 1.4);
   std::cout << "accumulate int/double for variable and for initializer: \n";
   std::cout << "type variable = tv, type initializer = ti:  tv_sum_ti\n";
   std::cout << v[0] << " + " << v[1] << " + " << v[2] << std::endl;
   int    iSum_i = accumulate(v.begin(), v.end(), 0);
   int    iSum_d = accumulate(v.begin(), v.end(), 0.0);
   double dSum_i = accumulate(v.begin(), v.end(), 0);
   double dSum_d = accumulate(v.begin(), v.end(), 0.0);

   std::cout << "i_sum_i = " << iSum_i << std::endl;
   std::cout << "i_sum_d = " << iSum_d << std::endl;
   std::cout << "d_sum_i = " << dSum_i << std::endl;
   std::cout << "d_sum_d = " << dSum_d << std::endl;
   return 0;
}
