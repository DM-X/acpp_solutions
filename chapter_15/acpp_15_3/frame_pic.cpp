#include "frame_pic.hpp"

using std::ostream;
using std::string;

void Frame_Pic::display(ostream& os, ht_sz row, bool do_pad) const
{
   if (row >= height()) {
      // out of range
      if (do_pad)
         pad(os, 0, width());
   } else {
      if (row == 0 || row == height() - 1) {          // top or bottom row
         os << corner_char;
         os << string(width()-2, topbot_char);
         os << corner_char;
      } else if (row == 1 || row == height() - 2) {   // 2nd top or bottom row
         os << side_char;
         pad(os, 1, width() - 1);
         os << side_char;
      } else {                                        // interior row
         os << side_char << " ";
         p->display(os, row - 2, true);
         os << " " << side_char;
      }
   }
}
