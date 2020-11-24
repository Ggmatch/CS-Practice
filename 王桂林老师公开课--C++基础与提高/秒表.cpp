#include <iostream>
#include <iomanip>
#include <thread>
#include <chrono>
using namespace std;

/*
  秒表：
  显示格式h:m:s : 00:00:00
  每个1s刷新一次
*/

int main()
{
    int h,m,s;
    h=m=s=0;
    int jinwei=0;
    while(true)
    {
        // using namespace std::chrono_literals;
        cout<<setw(2)<<setfill('0')<<h<<":"
        <<setw(2)<<setfill('0')<<m<<":"
        <<setw(2)<<setfill('0')<<s<<endl;
        // chrono::seconds sec(1);
        this_thread::sleep_for(chrono::seconds(1));
        system("clear");
        jinwei=0;
        s+=1;
        jinwei = s/60;
        s%=60;
        m+=jinwei;
        jinwei = m/60;
        m%=60;
        h+=jinwei;
        h%=24;
    }
    
    return 0;
}