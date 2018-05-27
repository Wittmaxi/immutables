#include "immutables.hpp"
#include <iostream>

class foo
{
  public:
    foo(int a, int b, float c)
    {
    }
    void bar()
    {
    }
    void miz()
    {
        a = 23;
    }
    int a;
};

main()
{
    IMU<foo> my_immutable(5, 4, 3.4);
}