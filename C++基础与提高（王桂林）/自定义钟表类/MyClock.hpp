/*
 * 钟表类
 * 属性：时分秒
 * 行为：run() 在屏幕上实现电子时钟（形式如13:34:45），从当前系统时间开始，每隔1s更新一个显示
 * 
 * 作者：yifan
 * 时间：2020/12/14
 */
#pragma once

#include <ctime>
#include <iomanip>
#include <thread>
using namespace std;

class MyClock
{
private:
    int hour;
    int minute;
    int sec;
    void display(); //刷新显示
    void update();  //更新时间

public:
    MyClock(std::time_t t = -1);
    void run();
    ~MyClock();
};

MyClock::MyClock(std::time_t t)
{
    if (t == -1)
    {
        // 获取当前系统本地时间
        t = time(nullptr);
    }
    std::tm tm = *std::localtime(&t);

    // 初始化
    hour = tm.tm_hour;
    minute = tm.tm_min;
    sec = tm.tm_sec;
}

MyClock::~MyClock()
{
}

void MyClock::run()
{
    // 每隔1s刷新一次
    while (true)
    {
        display();
        update();
    }
}

void MyClock::update()
{
    int jinwei = 0;
    sec += 1;
    jinwei = sec / 60;
    sec %= 60;
    minute += jinwei;
    jinwei = minute / 60;
    minute %= 60;
    hour += jinwei;
    hour %= 24;
}

void MyClock::display()
{
    // using namespace std::chrono_literals;
    system("cls");
    cout << setw(2) << setfill('0') << hour << ":"
         << setw(2) << setfill('0') << minute << ":"
         << setw(2) << setfill('0') << sec << endl;
    // chrono::seconds sec(1);

    std::this_thread::sleep_for(std::chrono::seconds(1));
}
