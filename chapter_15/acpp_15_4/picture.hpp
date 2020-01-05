#ifndef GUARD_picture_h
#define GUARD_picture_h

#include <iostream>
#include <vector>
#include <string>
#include "ptr.hpp"
#include "pic_base.hpp"

#include "string_pic.hpp" //could be placed in cpp
#include "frame_pic.hpp"  //--"--
#include "hcat_pic.hpp"
#include "vcat_pic.hpp"

class Picture
{
   friend std::ostream& operator<<(std::ostream&, const Picture&);
   friend Picture frame(const Picture&, const char, const char, const char);
   friend Picture reframe(const Picture&, const char, const char, const char);
   friend Picture hcat(const Picture&, const Picture&);
   friend Picture vcat(const Picture&, const Picture&);
   public:
      Picture(const std::vector<std::string>& = std::vector<std::string>());
   private:
      Ptr<Pic_base> p;
      Picture(Pic_base* ptr): p(ptr) { }
};

Picture frame(const Picture&, const char='*', const char='*', const char='*');
Picture reframe(const Picture&, const char='*', const char='*', const char='*');
Picture hcat(const Picture&, const Picture&);
Picture vcat(const Picture&, const Picture&);
std::ostream& operator<<(std::ostream&, const Picture&);

#endif
