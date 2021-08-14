#include <iostream>
#include  <cstdlib>
#include <chrono>
#include <string>
#include <vector>
#include <stdlib.h>
#include   <algorithm>

struct suanshi
{
    int t1;
    int t2;
    float result;
    std::string oper1;
    std::string oper2;
    int tihao;//题号
};



int main()
{
    int num1;
    int num2;
    int num3;
    std::cout<<"请输入题目数量"<<std::endl;
    std::cin>>num1;
    std::cout<<"请输入题目难度，如果需要乘除请输入4，否则输入2"<<std::endl;
    std::cin>>num2;
    std::cout<<"请输入运算的大小范围"<<std::endl;
    std::cin >>num3;
    
    srand(time(NULL));
    int flag = 0;
    std::vector<suanshi> cuoti;
    std::vector<float> timesort;//用于时间排序
    float time = 0;//计算平均时间

    for (size_t i = 0; i < num1; i++)
    {   //生成数字随即与操作符随机数
        
        int t;
        int t1 = rand()%num3;
        int t2 = rand()%num3;
        int oper = rand()%num2;
        //进行判断计算，并将错题放入vector中
        if (oper==0)//+运算符
        {      
            std::cout<<"第"<<i+1<<"题"<<std::endl;
            std::cout<<t1<<"+"<<t2<<"="<<std::endl;
            //计算时间
            float start = clock();
            std::cin >>t;
            float end = clock() -start;
            time +=end;
           
            if (t == t1+t2)
            {
                flag+=1;
            }
            else
            {
                    suanshi ct;
                    ct.tihao = i+1;
                    ct.t1 = t1;
                    ct.t2 = t2;
                    ct.result = t1+t2;
                    ct.oper1 = "+";
                    ct.oper2 = "=";
                    cuoti.push_back(ct);
           } 
          timesort.push_back(end);  
        }
        else if(oper ==1)//-运算符
        {
            std::cout<<"第"<<i+1<<"题"<<std::endl;
            std::cout<<t1<<"-"<<t2<<"="<<std::endl;
            
            float start = clock();
            std::cin >>t;
            float end = clock() -start;
            time +=end;

            if (t == t1-t2)
            {
                flag+=1;
            }
            else
            {
                    suanshi ct;
                    ct.tihao = i+1;
                    ct.t1 = t1;
                    ct.t2 = t2;
                    ct.result = t1-t2;
                    ct.oper1 = "-";
                    ct.oper2 = "=";
                    cuoti.push_back(ct);
            }
            timesort.push_back(end);
        } else if(oper ==2)//乘运算符 
        {
            std::cout<<"第"<<i+1<<"题"<<std::endl;
            std::cout<<t1<<"*"<<t2<<"="<<std::endl;

            float start = clock();
            std::cin >>t;
            float end = clock() -start;
            time +=end;

            if (t == t1*t2)
            {
                flag+=1;
            }
            else
            {
                    suanshi ct;
                    ct.tihao = i+1;
                    ct.t1 = t1;
                    ct.t2 = t2;
                    ct.result = t1*t2;
                    ct.oper1 = "*";
                    ct.oper2 = "=";
                    cuoti.push_back(ct);
            }
            timesort.push_back(end);
        }
        else if(oper ==3)//除运算符,改变了条件定义
        {
            float tt;
            std::cout<<"第"<<i+1<<"题"<<std::endl;
            if (t2 == 0)//除数不等于0
            {
                t2+=1;
            }
            
            std::cout<<t1<<"/"<<t2<<"="<<std::endl;
                        
            float start = clock();
            std::cin >>tt;
            float end = clock() -start;
            time +=end;
            
            if (abs((float)t1/(float)t2-tt)<=0.01)
            {
                flag+=1;
            }
            else
            {
                    suanshi ct;
                    ct.tihao = i+1;
                    ct.t1 = t1;
                    ct.t2 = t2;
                    ct.result = (float)t1/(float)t2;
                    ct.oper1 = "/";
                    ct.oper2 = "=";
                    cuoti.push_back(ct);
            }
            timesort.push_back(end);
        }
    }

    //判断有多少个错题,以及回答时间，并输出
    if (flag == num1)
    {
        std::cout<<"恭喜您全部回答正确"<<std::endl;
    }else
    {
        std::cout<<"您答错的题目一共有"<<num1-flag<<"道，这些题目及正确答案分别是："<<std::endl;
        for (size_t i = 0; i < 10-flag; i++)
        {
            std::cout<<"第"<<cuoti[i].tihao<<"题";
            std::cout<<cuoti[i].t1<<cuoti[i].oper1<<cuoti[i].t2<<cuoti[i].oper2;
            std::cout<<cuoti[i].result<<std::endl;
        }
    }
    
    std::sort(timesort.begin(),timesort.end());
    std::cout<<"答题最短用时:"<<timesort[0]<<"毫秒"<<std::endl;
    std::cout<<"答题平均用时:"<<time/num1<<"毫秒"<<std::endl;
}