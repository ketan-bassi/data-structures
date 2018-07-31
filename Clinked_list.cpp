

#include <iostream>
#include <stdlib.h>
using namespace std;
struct list
{
    int info;
    struct list *next;
};
struct list *start=NULL;
class linked_list
{
public:
    void insertbeg(int item);
    void insertend(int item);
    void traverse();
    void deletebeg();
    void deleteend();
};
void linked_list::insertbeg(int item)
{
    struct list *ptr,*temp;
    ptr=new list;
    
    if(start==NULL)
    {
        start=ptr;
        ptr->info=item;
        ptr->next=start;
    }
    else
    {
        ptr->info=item;
        ptr->next=start;
        temp=start;
        while(temp->next!=start)
        {
            temp=temp->next;
        }
        temp->next=ptr;
        start=ptr;
    }
}
void linked_list::insertend(int item)
{
    struct list *ptr,*temp;
    ptr=new list;
    
    if(start==NULL)
    {
        start=ptr;
        ptr->info=item;
        ptr->next=start;
    }
    else
    {
        ptr->info=item;
        temp=start;
        while(temp->next!=start)
        {
            temp=temp->next;
        }
        temp->next=ptr;
        ptr->next=start;
    }
}
void linked_list::traverse()
{
    struct list *temp;
    if(start==NULL)
    {
        cout<<"list is empty";
    }
    else
    {
        temp=start;
        while(temp->next!=start)
        {
            cout<<temp->info<<" ";
            temp=temp->next;
        }
        cout<<temp->info;
    }
}
void linked_list::deletebeg()
{
    struct list *temp,*temp1;
    if(start==NULL)
    {
        cout<<"underflow";
    }
    else
    {
        temp=start;
        
        while(temp->next!=start)
        {
            temp=temp->next;
        }
        temp1=start;
        start=start->next;
        temp->next=start;
        delete temp1;
        
    }
}
void linked_list::deleteend()
{
    struct list *temp,*temp1;
    if(start==NULL)
    {
        cout<<"underflow";
    }
    else if(start->next==start)
    {
        temp=start;
        start=NULL;
        delete temp;
    }
    else
    {
        temp=start;
        while(temp->next!=start)
        {
            temp1=temp;
            temp=temp->next;
        }
        temp1->next=start;
        delete temp;
    }
}
int main()
{
    linked_list obj;
    int n,item;
    while (1)
    {
        cout<<"enter the choice";
        cin>>n;
        switch(n)
        {
            case 1:
                cout<<"enter an item";
                cin>>item;
                obj.insertbeg(item);
                break;
            case 2:
                cout<<"enter an item";
                cin>>item;
                obj.insertend(item);
                break;
            case 3:
                obj.traverse();
                break;
            case 4:
                obj.deletebeg();
                break;
            case 5:
                obj.deleteend();
                break;
            default:
                exit(0);
                
                
        }
        
        
    }
}


