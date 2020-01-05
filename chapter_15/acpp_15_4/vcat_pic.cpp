#include "vcat_pic.hpp"

using std::ostream;

void VCat_Pic::display(ostream& os, ht_sz row, bool do_pad) const
{
   wd_sz w = 0;
   if (row < top->height()) {
      // we are in the top subpicture
      top->display(os, row, do_pad);
      w = top->width();
   } else if (row < height()) {
      // we are in the bottom subpicture
      bottom->display(os, row - top->height(), do_pad);
      w = bottom->width();
   }
   if (do_pad) {
      pad(os, w, width());
   }
}

void VCat_Pic::reframe(char tb, char s, char c)                                 
{                                                                                
   top->reframe(tb, s, c);
   bottom->reframe(tb, s, c);
}  
