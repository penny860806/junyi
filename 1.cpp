#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <math.h>
#include <algorithm>
#include <vector>
#include <list>
#include <stack>
#include <string>
bool isnumber(char c) //�P�_c�O���O�Ʀr
{
    return (c>='0' && c<='9')?true:false;
}
using namespace std;
int main()
{
    char c;
    vector<string> v;
    int counum=0;//�Ψӭp��X�{�L�X�ӼƦr
    while ((c=getchar()) && c!='\n')  //�v�@�r��Ū���A�J���浲��
    {
        if(c=='[') v.push_back("#");//�p�GŪ��}�Y�аO�A�b�}�C���ڴ��J#
        else if(isnumber(c) || c=='-')//�p�GŪ��Ʀr�έt��
        {
            string num;
            num+=c;
            while ((c=getchar()) && c!=',' && c!=']')//�v�@Ū���r���զX�i�r��A�J�r���ε����аO����
            {
                num+=c;
            }
            v.push_back(num);//�N�զX�����Ʀr�r�괡�J�}�C����
            if(c==']')//�p�G��~�Ʀr�᭱�O�����аO�A�b�}�C���ڴ��J$
            {
                v.push_back("$");
            }
            counum++;
        }
        else if(c==']')//�p�GŪ�쵲���аO�A�b�}�C���ڴ��J$
        {
            v.push_back("$");
        }
    }
    for (int i=v.size()-1; i>=0; i--)  //��}�C�˹L�Ӭ�
    {
        if(v[i]=="$") //�J��쥻�������аO�N��X[
        {
            printf("[");
        }
        else if(v[i]=="#") //�J��쥻���}�Y�аO�N��X]
        {
            printf("]");
        }
        else //��ӳ����O���ܴN�O�Ʀr
        {
            cout<<v[i];
            counum--;
            if(i-1>=0 && v[i-1]=="#")//�P�_�Ʀr���᭱�O�Ʀr�٬O����
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
