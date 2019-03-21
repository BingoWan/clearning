/**
 * @Author: ruo_van
 * @Date:   2019-02-27T10:40:44+08:00
 * @Email:  wanwb1224@gmail.com
 * @Last modified by:   ruo_van
 * @Last modified time: 2019-02-28T11:17:36+08:00
 */
#include <cmath>
#include "vector.h"
using std::sqrt;
using std::sin;
using std::cos;
using std::atan;
using std::atan2;
using std::cout;

namespace VECTOR {
  const double Rad_to_deg = 45.0/atan(1.0);

  // private methods
  void Vector::set_mag() {
    mag = sqrt(x*x + y*y);
  }
  void Vector::set_ang() {
    if (x == 0.0 && y == 0.0)
      ang = 0.0;
    else
      ang = atan2(y, x);
  }
  void Vector::set_x() {
    x = mag*cos(ang);
  }
  void Vector::set_y() {
    y = mag*sin(ang);
  }
  // pulic methods

}
