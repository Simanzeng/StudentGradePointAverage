//计算绩点
#include <iostream>
#include<fstream>
#include<cstdlib>      //system
#include<cstring>      //strcat
#include<windows.h>    //GetCurrentDirectory
#include<sstream>
#include<cctype>

using namespace std;

int main()
{
    ifstream in;
    ofstream out;
    char buf[1000],buf1[1000];
    GetCurrentDirectory(1000,buf);     //获取当前路径
    GetCurrentDirectory(1000,buf1);
    strcat(buf,"\\text.txt");    //buf+"\bin\Debug\text.txt"
    strcat(buf1,"\\Simanzeng'score.txt");
    in.open(buf);    //打开文件  buf=="E:\C++projectCoding\student_PDA\bin\Debug\text.txt"
    out.open(buf1,ofstream::out | ofstream::app);
    if(!out)
    {
        cerr<<"文件打开失败!"<<endl;
    }
    if(!in)
    {
        cerr<<"文件打开失败！"<<endl;
    }
    double n,m,s,am=0.0,dm=0.0,allm=0.0;
    string line;
    while(getline(in,line))
    {
        string s;
        stringstream s1(line);
        s1>>s;
        if(isalnum(s[0]))   //如果s[0]是字母或数字，则为 True。
            break;
    }
    do
    {
        string word;
        stringstream strm(line);
        bool b1=true;
        strm>>word;
        if(!isalnum(word[0]))   //如果word[0]是字母或数字，则为 True。
        {
            break;
        }
        while(strm>>word)
        {
            if(word=="优秀")
            {
                word="95";
            }
            if(word=="良好")
            {
                word="85";
            }
            if(word=="中")
            {
                word="75";
            }
            if(word=="合格")
            {
                word="65";
            }
            if(isdigit(word[0]))   //如果word[0]是数字(1~9)，则为 true。
            {
                double b=atof(word.c_str());
                if(b>=0 && b<=100 && b1==true)
                {
                    n=b;
                    b1=false;
                }
                else if(b>0 && b<15)
                {
                    m=b;
                }
            }
        }
        if(n>=60&&n<=100)
        {
            s=n/10-5.0;
        }
        if(n>=0&&n<=59)
        {
            s=0;
        }

        dm=dm+s*m;
        allm=allm+m;
    }while(getline(in,line));
    in.close();
    am=dm/allm;
    cout<<"你这学期的总学分绩点："<<dm<<endl;
    cout<<"该学期所修全部课程的总学分："<<allm<<endl;
    cout<<"你这学期的平均绩点为："<<am<<endl;
    out<<endl;
    out<<"尊敬的用户您好："<<endl;
    out<<"你这学期的总学分绩点："<<dm<<endl;
    out<<"该学期所修全部课程的总学分："<<allm<<endl;
    out<<"你这学期的平均绩点为："<<am<<endl;
    out.close();
    cout<<"你的信息已被保存在Simanzeng'score.txt文档中！"<<endl;
    system("PAUSE");
    return 0;
}
