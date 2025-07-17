#include <cstddef>
#include <iostream>


using namespace std;


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

class LinkedList
{
    private:
    node*head=NULL;

    public:
    int noOfNodes=0;

//Using Destructor for Mermory Leakage.
    ~LinkedList()
    {
        node*current=head;
        while (current!=NULL)
        {
            node*newnode=current->next;
            delete current;
            current=newnode;
        }
    }


    void InsertAtBeginning()
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
        }
        else
        {
            node*travptr=head;
            while(travptr->next!=NULL)
            {
                travptr=travptr->next;
            }
            travptr->next=temp;
        }
        noOfNodes++;
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
            noOfNodes--;
        }
    }
};


int main ()
{
    LinkedList obj;
    int choice=0;
    while (1)
    {
        cout<<"\n1.PUSH \t2.POP\t3.Display\t4.Exit\t5.Show The Number Of Nodes";
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
            case 5:
                {
                    cout<<"\nThe Total Number Of Nodes In the Stack is "<<obj.noOfNodes<<"\n";
                }
        }
    }
    return 0;
}