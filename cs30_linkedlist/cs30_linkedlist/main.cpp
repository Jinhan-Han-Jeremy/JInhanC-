#include <iostream>      /* printf, scanf, NULL */
#include <string>     /* malloc, free, rand */
using namespace std;

struct node
{
    int data;
    node *next;
};

class list
{
private:
    node *head, *tail;
public:
    list()
    {
        head=NULL;
        tail=NULL;
    }
    void createnode(int value)
    {
        node *temp=new node;
        temp->data=value;
        temp->next=NULL;
        if(head==NULL)
        {
            head=temp;
            tail=temp;
            temp=NULL;
        }
        else
        {
            tail->next=temp;
            tail=temp;
        }
    }
    void display()
    {
        node *temp=new node;
        temp=head;
        
        while(temp!=NULL)
        {
            cout<<temp->data<<"\t";
            temp=temp->next;
        }
    }
    void insert_start(int value)
    {
        node *temp=new node;
        temp->data=value;
        temp->next=head;
        head=temp;
    }

    void insert_position(int pos, int value)
    {
        node *pre=new node;
        node *cur=new node;
        node *temp=new node;
        cur=head;
        for(int i=1;i<pos;i++)
        {
            pre=cur;
            cur=cur->next;
        }
        temp->data=value;
        pre->next=temp;
        temp->next=cur;
    }
    
    void delete_first()
    {
        node *temp=new node;
        temp=head;
        head=head->next;
        delete temp;
    }
    
    void delete_last()
    {
        node *current=new node;
        node *previous=new node;
        current=head;
        while(current->next!=NULL)
        {
            previous=current;
            current=current->next;
        }
        tail=previous;
        previous->next=NULL;
        delete current;
    }
    
    void delete_position(int pos)
    {
        node *current=new node;
        node *previous=new node;
        current=head;
        for(int i=1;i<pos;i++)
        {
            previous=current;
            current=current->next;
        }
        previous->next=current->next;
    }
};

int main ()
{
    list *li = new list(); // list included *ptr must be ptr type
    int a, b, c;
    
    do
    {
        cout << " 1 createnode 2 insert_start\n 3 insert_position  4 delete_first\n 5 delete_last 6 delete_position\n 0 display exit\n " <<endl;
        cout << "enter number please : " << endl;
        cin >> b;
    
        if(b==1)
    {
        cout << "enter 1 number please : " << endl;
        cin >> a;
        li->createnode(a);
    }
    else if(b==2)
    {
        cout << "enter 2 number please : " << endl;
        cin >> a;
        li->insert_start(a);
    }
    else if(b==3)
    {
        cout << "enter 3 number please : " << endl;
        cin >> a;
        cout << "enter 3 number of position please : " << endl;
        cin >> c;
        li->insert_position(c, a);
    }
    else if(b==4)
    {
        li->delete_first();
    }
    else if(b==5)
    {
        li->delete_last();
    }
    else if(b==6)
    {
        cout << "enter 6 number please : " << endl;
        cin >> a;
        
        li->delete_position(a);
    }
    }while(b!= 0);
    li->display();
    
    return 0;
}
