//### 尽可能使用const
//#1.使用const可以避免无意中修改数据的编程错误；
//#2.使用const使函数能够处理const和非const实参，否则将只能接受非const数据；
//#3.使用const引用使函数能够正确生成并使用临时变量。
//#因此，应尽可能将引用形声明为const.

#include <iostream>
#include <string>

struct free_throws {
  std::string name;
  int made;
  int attempt;
  float percent;
};

struct job {
  char name[40];
  double salary;
  int floor;
};

void display(const free_throws & ft);
template <typename T>
void swap(T &a, T &b);
template <> void swap(job &, job &);
template <typename T1, typename T2>
void swap(T1 &, T2 &);
free_throws & accumulate(free_throws & target, const free_throws & source);

int main() {
  free_throws one = {"wanwb", 20, 10};
  free_throws two = {"wanwb1", 20, 10};
  accumulate(one, two);
  display(one);
  int a = 1; int b = 2;
  double aa = 1.1; double bb = 2.2;
  swap(a, b);
  swap(aa, bb);
  return 0;
}

void display(const free_throws & ft) {
  using std::cout;
  cout << "Name: " << ft.name << "\n";
  cout << "Made: " << ft.made << "\t";
  cout << "attempt: " << ft.attempt << "\t";
}

// 为何要返回引用

free_throws & accumulate(free_throws & target, const free_throws & source) {
  target.attempt += source.attempt;
  target.made += source.made;
  return target;
}

// 返回引用时需要注意的问题
// 应避免函数终止时不再存在的内存单元的引用。


//###8.3 默认参数
// 对于带参数的函数，必须从右向左添加默认值。也就是说，要为某个参数设置默认值，则必须为
//它右边的所有的参数提供默认值

//###8.4 函数重载
//函数参数列表 也叫函数特征标
//匹配函数 并不区分const和非const变量。
// ***是特征标，而不是函数类型使得可以对函数进行重载。

//###8.5 泛型 函数模板

template <typename T>
void swap(T & a, T & b) {
  T c;
  c = a;
  b = c;
  a = b;
}

template <typename T1, typename T2>
auto swap(T1 &a, T2 &b) -> decltype(a + b) {
  using std::cout;
  cout << "test" << "\n";
  return a + b;
}

template <> void swap(job &j1, job &j2) {
  double t1; int t2;
  t1 = j2.salary;
  j2.salary = j1.salary;
  j1.salary = t1;
  t2 = j2.floor;
  j2.floor = j1.floor;
  j1.floor = t2;
}
// 上面的具体化，还可以写成如下形式：
// template <> void swap(job &j1, job &j2);
// 模板的局限性
// 显示具体化
// 第三代 具体化
// 具体化优于常规模板，而非模板函数优于具体化和常规模板


// 显示实例化和显示具体化
// 显示具体化的声明:
// template <> void swap<job>(job &j1, job &j2);
// 或 template <> void swap(job &j1, job &j2);
// 显示具体化要定义自己的函数原型，主要是为了实现模板不能通用实现的功能；
// 而实例具体化，是用函数模板的原型，实例具体化只是让编译器创建指定类型的实例，声明如下:
// template void swap<int>(int , int);

// 关键字 decltype
