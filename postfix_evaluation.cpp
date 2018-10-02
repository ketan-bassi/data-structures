//
//  main.cpp
//  postfix_exaluation
//
//  Created by KETAN BASSI on 30/08/18.
//  Copyright © 2018 KETAN BASSI. All rights reserved.
//

#include <iostream>
#include <cmath>
using namespace std;
class stack
{
    int a[20];
    int top;
public:
    stack()
    {
        top--;
    }
  void push(int num)
    {
        a[++top]=num;
    }
    int pop()
    {
        return a[top--];
    }
    bool is_empty()
    {
        if(top==-1)
            return true;
        return false;
    }
    void evaluate(char exp[20])
    {
        char *e;
        int n1,n2,n3,num;
        e=exp;
    
    while (*e!=0)
    {
        if(isdigit(*e))
        {
            num =*e -'0';
            push(num);
        }
        else{
            n1=pop();
            n2=pop();
            switch(*e)
            {
                case '+':
                    n3=n1+n2;
                    break;
                case '-':
                    n3=n2-n1;
                    break;
                case '*':
                    n3=n1*n2;
                    break;
                case '/':
                    n3=n2/n1;
                case '^':
                    n3=pow(n2,n1);
            }
            push(n3);
        }
        e++;
        
    }
    cout << "result"<<exp<<endl<<pop()<<endl;
    }
    
};
int main() {
    char exp[20];
    char *e;
    cout<<"Enter postfix expression"<<endl;
    cin>>exp;
    stack s;
    s.evaluate(exp);
    return 0;
    
}
