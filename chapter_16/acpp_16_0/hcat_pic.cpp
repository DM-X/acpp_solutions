#include "hcat_pic.hpp"

using std::ostream;

void HCat_Pic::display(ostream& os, ht_sz row, bool do_pad) const
{
   ht_sz l_row = row;
   ht_sz r_row = row;

   if (left->height() > right->height()) {
      ht_sz v_pad = (left->height()  - right->height())/2;
      if (row<v_pad) 
         r_row = right->height(); //forces a padding with spaces
      else
         r_row = row - v_pad;
   } else {
      ht_sz v_pad = (right->height() - left->height())/2;
      if (row<v_pad) 
         l_row = left->height(); //forces a padding with spaces
      else
         l_row = row - v_pad;
   }
   left->display(os,  l_row, do_pad || row < right->height());
   right->display(os, r_row, do_pad);
}

void HCat_Pic::reframe(char tb, char s, char c)
{
   left->reframe(tb, s, c);
   right->reframe(tb, s, c);
}
