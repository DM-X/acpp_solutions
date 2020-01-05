#ifndef GUARD_frame_pic_h
#define GUARD_frame_pic_h

#include "pic_base.hpp" //nec.
#include "ptr.hpp"


class Frame_Pic: public Pic_base {
   friend Picture frame(const Picture&);
   private:
      Ptr<Pic_base> p;
      Frame_Pic(const Ptr<Pic_base>& pic): p(pic) { }

      wd_sz width() const {return p->width() + 4;}
      ht_sz height() const {return p->height() + 4;}
      void display(std::ostream&, ht_sz, bool) const;
};

#endif
