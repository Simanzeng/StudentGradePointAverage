//���㼨��
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
    GetCurrentDirectory(1000,buf);     //��ȡ��ǰ·��
    GetCurrentDirectory(1000,buf1);
    strcat(buf,"\\text.txt");    //buf+"\bin\Debug\text.txt"
    strcat(buf1,"\\Simanzeng'score.txt");
    in.open(buf);    //���ļ�  buf=="E:\C++projectCoding\student_PDA\bin\Debug\text.txt"
    out.open(buf1,ofstream::out | ofstream::app);
    if(!out)
    {
        cerr<<"�ļ���ʧ��!"<<endl;
    }
    if(!in)
    {
        cerr<<"�ļ���ʧ�ܣ�"<<endl;
    }
    double n,m,s,am=0.0,dm=0.0,allm=0.0;
    string line;
    while(getline(in,line))
    {
        string s;
        stringstream s1(line);
        s1>>s;
        if(isalnum(s[0]))   //���s[0]����ĸ�����֣���Ϊ True��
            break;
    }
    do
    {
        string word;
        stringstream strm(line);
        bool b1=true;
        strm>>word;
        if(!isalnum(word[0]))   //���word[0]����ĸ�����֣���Ϊ True��
        {
            break;
        }
        while(strm>>word)
        {
            if(word=="����")
            {
                word="95";
            }
            if(word=="����")
            {
                word="85";
            }
            if(word=="��")
            {
                word="75";
            }
            if(word=="�ϸ�")
            {
                word="65";
            }
            if(isdigit(word[0]))   //���word[0]������(1~9)����Ϊ true��
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
    cout<<"����ѧ�ڵ���ѧ�ּ��㣺"<<dm<<endl;
    cout<<"��ѧ������ȫ���γ̵���ѧ�֣�"<<allm<<endl;
    cout<<"����ѧ�ڵ�ƽ������Ϊ��"<<am<<endl;
    out<<endl;
    out<<"�𾴵��û����ã�"<<endl;
    out<<"����ѧ�ڵ���ѧ�ּ��㣺"<<dm<<endl;
    out<<"��ѧ������ȫ���γ̵���ѧ�֣�"<<allm<<endl;
    out<<"����ѧ�ڵ�ƽ������Ϊ��"<<am<<endl;
    out.close();
    cout<<"�����Ϣ�ѱ�������Simanzeng'score.txt�ĵ��У�"<<endl;
    system("PAUSE");
    return 0;
}
