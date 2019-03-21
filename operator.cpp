/**
 * @Author: ruo_van
 * @Date:   2019-02-26T15:58:38+08:00
 * @Email:  wanwb1224@gmail.com
 * @Last modified by:   ruo_van
 * @Last modified time: 2019-02-27T10:12:11+08:00
 */

// 在运算符表示法中，运算符左侧的对象是调用对象，右侧是作为参数被传递的对象
// total = coding + fixing;
// total = coding.operator+(fixing);

#include <iostream>
#include "operator.h"

Time::Time() {
  hours = minutes = 0;
}

Time::Time(int h, int m) {
  hours = h;
  minutes = m;
}

void Time::AddMin(int m) {
  minutes += m;
  hours += minutes / 60;
  minutes %= 60;
}

void Time::AddHr(int h) {
  hours += h;
}

void Time::Reset(int h, int m) {
  hours = h;
  minutes = m;
}

Time Time::Sum(const Time & t) const {
  Time sum;
  sum.minutes = minutes + t.hours + sum.minutes / 60;
  sum.minutes %= 60;
  return sum;
}

Time Time::operator+(const Time &t) const {
  Time sum;
  sum.minutes = minutes + t.hours + sum.minutes/60;
  sum.minutes %= 60;
  return sum;
}

Time Time::operator-(const Time &t) const {
  Time diff;
  int tot1, tot2;
  tot1 = t.minutes + 60*t.hours;
  tot2 = minutes + 60*hours;
  diff.minutes = (tot2 - tot1)%60;
  diff.hours = (tot2 - tot1)/60;
  return diff;
}

Time Time::operator*(double mult) const {
  Time result;
  long totalminutes = hours*mult*60 + minutes*mult;
  result.hours = totalminutes/60;
  result.minutes = totalminutes%60;
  return result;
}
// 非成员函数能够实现成员函数比较尴尬处理的问题，但非成员函数不能访问类的私有数据，这个时候，就需要把非成员函数看作成朋友，和自己的家人一样，这个朋友就是友元函数
Time operator*(double mult, const Time &t) {
  Time result;
  long totalminutes = t.hours*mult*60 + t.minutes*mult;
  result.hours = totalminutes/60;
  result.minutes = totalminutes%60;
  return result;
}
void Time::Show() const {
  std::cout << hours << " hours, " << minutes << " minutes";
}

// operator<< 重载问题
// cout << x << y; 等价于 (cout << x) << y;
// 所以 << 运算符要求左边是一个ostream对象。cout 是 ostream对象。
std::ostream & operator<<(std::ostream &os, const Time &t) {
  os << t.hours << "hours, " << t.minutes << "minutes";
  return os;
}

// 重载运算符：作为成员函数还是非成员函数
// 使用非成员函数可能更好，(转换和友元)
