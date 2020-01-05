#include "hcat_pic.hpp"

using std::ostream;

void HCat_Pic::display(ostream& os, ht_sz row, bool do_pad) const
{
   left->display(os, row, do_pad || row < right->height());
   right->display(os, row, do_pad);
}

void HCat_Pic::reframe(char tb, char s, char c)                                 
{                                                                                
   left->reframe(tb, s, c);
   right->reframe(tb, s, c);
}  
