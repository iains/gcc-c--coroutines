//  { dg-additional-options "-std=c++23 " }
//  { dg-do run }
#include <generator>
//#include <print>
#include <vector>

std::generator<int> get_seq()
{
  std::vector<int> data_{1, 2, 3};
  for (auto item : data_)
    co_yield item;
}

int main()
{
  int res = 0;
  for (auto item : get_seq())
    res = item;   //std::println("{}", item);
  if (res != 3)
    __builtin_abort ();
}
