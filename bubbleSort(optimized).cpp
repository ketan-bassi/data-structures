

#include <iostream>
using namespace std;
class bubble
{
public:
    int a[100];
    void input(int);
    void sort(int);
    void print(int);
};
void bubble::input(int n)
{
    int i;
    for(i=0;i<n;i++)
        cin>>a[i];
}
void bubble::sort(int n)
{
    int i,j,temp=0,flag;
    for (i=0;i<(n-1);i++)
    {
        flag=0;
        for(j=0;j<(n-1-i);j++)
        {
            if(a[j]>a[j+1])
            {
                temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
                flag=1;
            }
        }
    if(flag==0)
        break;
    }
}
void bubble::print(int n)
{
    int i;
    for(i=0;i<n;i++)
        cout<<a[i]<<" ";
}
int main()
{
    bubble obj;
    int n;
    cout<<"enter no of inputs";
    cin>>n;
    obj.input(n);
    obj.sort(n);
    obj.print(n);
}

