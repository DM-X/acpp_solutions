#ifndef GUARD_frame_pic_h
#define GUARD_frame_pic_h

#include "pic_base.hpp" //nec.
#include "ptr.hpp"


class Frame_Pic: public Pic_base {
   friend Picture frame(const Picture&, const char, const char, const char);
   private:
      Ptr<Pic_base> p;
      char topbot_char, side_char, corner_char;
      Frame_Pic(const Ptr<Pic_base>& pic, const char tb, 
                const char s, const char c): p(pic), 
      topbot_char(tb), side_char(s), corner_char(c) { }

      wd_sz width() const {return p->width() + 4;}
      ht_sz height() const {return p->height() + 4;}
      void display(std::ostream&, ht_sz, bool) const;
      void reframe(char, char, char);
};

#endif
