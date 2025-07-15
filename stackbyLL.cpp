#include <iostream>


using namespace std;

int noOfNodes=0;

class node
{
    public:
    int data;
    node* next;
    node()
    {
//using Constructor For Assigning Value In The Node
        cout<<"\nEnter The Value:-";
        cin>>data;
        cout<<"\n";
        next=NULL;
    }
};

class LinkedList_functions
{
    private:
    node*head=NULL;

    public:

    void insertAtBegening()
    {
        node*temp=new node();
        if(head==NULL)
        {
            head=temp;
            noOfNodes++;
        }
        else
        {
            node*ptr=head;
            head=temp;
            temp->next=ptr;
            noOfNodes++;
        }
    }


    void insertAtEnd()
    {
        node*temp=new node();
        if(head==NULL)
        {
            head=temp;
            noOfNodes++;
        }
        else
        {
            node*travptr=head;
            while(travptr->next!=NULL)
            {
                travptr=travptr->next;
            }
            travptr->next=temp;
            noOfNodes++;
        }
    }


    void display()
    {
        node*travptr=head;
        cout <<"\n";
        if(travptr==NULL)
        {
            cout<<"\nNo item to Display.\nList is Empty\n\n";
            return;
        }
        else
        {
            while(travptr!=NULL)
            {
                cout<<travptr->data <<"->";
                travptr=travptr->next;
            }cout<<"NULL\n";
        }
    }

    void delFromEnd()
    {
        node*ptr=head;
        if(head==NULL)
        {
            cout<<"\nNo Item Avilable For Delete\n";
            return;
        }
        else
        {
            if (ptr->next==NULL)
            {
                head=NULL;
                delete ptr;
            }
            else
            {
                while ((ptr->next)->next!=NULL)
                {
                    ptr=ptr->next;
                }
                node*ptr1=ptr->next;
                //cout<<ptr->data<<"\n"<<ptr1->data;
                ptr->next=NULL;
                delete ptr1;
            }
        }
    }
};


int main ()
{
    LinkedList_functions obj;
    int choice=0;
    while (1)
    {
        cout<<"\n1.PUSH \t2.POP\t3.Display\t4.Exit";
        cout<<"\nChoose a Option from Above:-";
        cin>>choice;
        
        switch (choice) 
        {
        default:
        {
            cout<<"Option Doesn't Exist...\n";
            break;
        }
        case 1:
        {
            obj.insertAtEnd();
            obj.display();
            break;
        }
        case 2:
        {
            obj.delFromEnd();
            obj.display();
            break;
        }
        case 3:
            {
                obj.display();
                break;
            }
        case 4:
            {
                exit(0);
            }
        }
    }
    return 0;
}