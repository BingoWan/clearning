/**
 * @Author: ruo_van
 * @Date:   2019-02-26T17:11:44+08:00
 * @Email:  wanwb1224@gmail.com
 * @Last modified by:   ruo_van
 * @Last modified time: 2019-02-27T10:05:36+08:00
 */
#ifndef OPERATOR_H_
#define OPERATOR_H_
#include <iostream>

class Time {
private:
  int hours;
  int minutes;
public:
  Time();
  Time(int h, int m = 0);
  void AddMin(int m);
  void AddHr(int h);
  void Reset(int h = 0, int m = 0);
  Time Sum(const Time &t) const;
  Time operator+(const Time &t) const;
  Time operator-(const Time &t) const;
  Time operator*(double n) const;
  friend Time operator*(double n, const Time &t);
  friend std::ostream & operator<<(std::ostream &os, const Time &t);
  void Show() const;
};
#endif
