

#include <iostream>
#include <stdlib.h>
using namespace std;
struct list
{
    int info;
    struct list *next;
    struct list *prev;
};
struct list *start=NULL;
struct list *End=NULL;
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
         End=ptr;
        ptr->next=NULL;
        ptr->prev=NULL;
    }
    else
    {
        ptr->info=item;
        ptr->next=start;
        start->prev=ptr;
        start=ptr;
        start->prev=NULL;
        
    }
}
void linked_list::insertend(int item)
{
    struct list *ptr;
    ptr=new list;
    
    if(start==NULL)
    {
        start=ptr;
        ptr->info=item;
        End=ptr;
        ptr->next=NULL;
        ptr->prev=NULL;
    }
    else
    {
        ptr->info=item;
        ptr->prev=End;
        End->next=ptr;
        End=ptr;
        ptr->next=NULL;
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
        while(temp->next!=NULL)
        {
            cout<<temp->info<<" ";
            temp=temp->next;
        }
        cout<<temp->info;
    }
}
void linked_list::deletebeg()
{
    struct list *temp;
    if(start==NULL)
    {
        cout<<"underflow";
    }
    else if(start==End)
    {
        temp=start;
        start=NULL;
        End=NULL;
        delete temp;
    }
    else
    {
        temp=start;
        start=temp->next;
        start->prev=NULL;
        delete temp;
    }
}
void linked_list::deleteend()
{
    struct list *temp;
    if(End==NULL)
    {
        cout<<"underflow";
    }
    else if(start==End)
    {
        temp=End;
        start=NULL;
        End=NULL;
        delete temp;
    }
    else
    {
        temp=End;
        End=temp->prev;
        End->next=NULL;
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



