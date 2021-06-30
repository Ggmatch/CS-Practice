/*
    作业2：string数组的使用
    char buf[100] = “xxxx:yyyy:zzzz:aaaa:bbb”分解到string数组中去

*/

#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

int main()
{
    // // c风格：先用c库strtok切分好，再赋给string
    // char buf[100] = "xxxx:yyyy:zzzz:aaaa:bbb";
    // const char s[2] = ":";
    // char *token;
    // vector<string> res;

    // /* 获取第一个子字符串 */
    // token = strtok(buf, s);
    // res.push_back(token);

    // /* 继续获取其他的子字符串 */
    // while (token != NULL)
    // {
    //     token = strtok(NULL, s);
    //     if (token == NULL)
    //         break;
    //     res.push_back(token);
    // }
    // // cout<<"hello cpp"<<endl;
    // for(auto elem : res)
    // {
    //     cout<<elem<<endl;
    // }

    // c++风格：先转换为string，再去切分
    char buf[100] = "xxxx:yyyy:zzzz:aaaa:bbb";
    string buf1 = buf;
    int pos1 = 0;
    vector<string> res;
    while(pos1<buf1.length())
    {
        int pos2 = buf1.find(":",pos1);
        if(pos2==-1)
            pos2=buf1.length();
        res.push_back(buf1.substr(pos1,pos2-pos1));
        pos1=pos2+1;
    }
    for(auto elem : res)
    {
        cout<<elem<<endl;
    }

    return 0;
}