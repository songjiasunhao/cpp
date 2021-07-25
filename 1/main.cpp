#include <iostream>

struct Point
{
    int x;
    int y;
    void fun1()
    {
        x=x+1;
    }
};
void fun(const char* pInfo)
{
    std::cout<<pInfo<<std::endl;
};

int main()
{
    fun("Hello World");
    fun("Hello china");
    Point p;
    p.x=3;
    p.y=4;
    p.fun1();
    std::cout<<p.x;
    return 0;
}
