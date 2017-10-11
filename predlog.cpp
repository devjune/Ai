#include<iostream>
#include<string.h>
using namespace std;
int main()
{
char a[20],b[20];int l;
gets(a);
l=strlen(a);
char *ptr,*ptr1,*ptr2,ptr3;
ptr=strstr(a,"all");
ptr1=strstr(a,"some");
ptr2=strstr(a,"not");
if(ptr && !ptr2)
{
    strncpy(b,"for all x(",10);
    cout<<"\n"<<b<<""<<a[4]<<"(x)->d(x))";

}
else if(ptr1 && !ptr2)
{
    strncpy(b,"there exist some x(",19);
    cout<<"\n"<<b<<a[5]<<"(x)->d(x))";
}
if(ptr && ptr2)
{
    {
    strncpy(b,"for all x(",10);
    cout<<"\n"<<b<<""<<a[4]<<"(x)->";
    }
    cout<<"!";
    cout<<"d(x))";
}
if(ptr1 && ptr2)
{
    //strncpy(b,"for all x(",10);
    strncpy(b,"there exist some x(",19);
    cout<<"\n"<<b<<a[5]<<"(x)->";
    cout<<"!";
    cout<<"d(x))";
}
}
