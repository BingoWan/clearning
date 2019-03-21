/**
 * @Author: ruo_van
 * @Date:   2019-02-27T10:28:17+08:00
 * @Email:  wanwb1224@gmail.com
 * @Last modified by:   ruo_van
 * @Last modified time: 2019-02-27T10:40:21+08:00
 */
#ifndef VECTOR_H_
#define VECTOR_H_
#include <iostream>
namespace VECTOR {
  class Vector {
  public:
    enum Mode {RECT, POL};
  private:
    double x;
    double y;
    double mag;
    double ang;
    void set_mag();
    void set_ang();
    void set_x();
    void set_y();
  public:
    Vector();
    Vector(double n1, double n2, Mode form = RECT);
    void reset(double n1, double n2, Mode form = RECT);
    ~Vector();
    double xval() const {return x;}
    double yval() const {return y;}
    double magval() const {return mag;}
    double angval() const {return ang;}
    void polar_mode();
    void rect_mode();
    Vector operator+(const Vector &b) const;
    Vector operator-(const Vector &b) const;
    Vector operator-() const;
    Vector operator*(double n) const;

    friend Vector operator*(double n, const Vector &a);
    friend std::ostream & operator<<(std::ostream &os, const Vector &v);
  };
} // end namespace VECTOR
#endif
