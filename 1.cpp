#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <math.h>
#include <algorithm>
#include <vector>
#include <list>
#include <stack>
#include <string>
bool isnumber(char c) //判斷c是不是數字
{
    return (c>='0' && c<='9')?true:false;
}
using namespace std;
int main()
{
    char c;
    vector<string> v;
    int counum=0;//用來計算出現過幾個數字
    while ((c=getchar()) && c!='\n')  //逐一字元讀取，遇換行結束
    {
        if(c=='[') v.push_back("#");//如果讀到開頭標記，在陣列尾巴插入#
        else if(isnumber(c) || c=='-')//如果讀到數字或負號
        {
            string num;
            num+=c;
            while ((c=getchar()) && c!=',' && c!=']')//逐一讀取字元組合進字串，遇逗號或結束標記停止
            {
                num+=c;
            }
            v.push_back(num);//將組合完的數字字串插入陣列尾巴
            if(c==']')//如果剛才數字後面是結束標記，在陣列尾巴插入$
            {
                v.push_back("$");
            }
            counum++;
        }
        else if(c==']')//如果讀到結束標記，在陣列尾巴插入$
        {
            v.push_back("$");
        }
    }
    for (int i=v.size()-1; i>=0; i--)  //把陣列倒過來看
    {
        if(v[i]=="$") //遇到原本的結束標記就輸出[
        {
            printf("[");
        }
        else if(v[i]=="#") //遇到原本的開頭標記就輸出]
        {
            printf("]");
        }
        else //兩個都不是的話就是數字
        {
            cout<<v[i];
            counum--;
            if(i-1>=0 && v[i-1]=="#")//判斷數字的後面是數字還是結束
            {
                printf("]");
                i--;
            }
            if(counum!=0) printf(", ");
        }
    }
    printf("\n");
    return 0;
}
