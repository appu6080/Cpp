#include <cstddef>
#include <cstdlib>
#include <iostream>


using namespace std;

class node
{
public:
    int data;
    node*next;


    node()
    {
        cout<<"\nEnter The Value ";
        cin>>data;
        next=NULL;
    }
};

class linked_list
{
private:
    node*head;
public:

    linked_list()
    {
        head=NULL;
    }

    void insertAtEnd()
    {
        node*temp=head;
        node*temp1=new node();
        if(temp==NULL)
        {
            head=temp1;
        }
        else 
        {
            while (temp->next!=NULL)
            {
                temp=temp->next;
            }
            temp->next=temp1;
        }
    }


    void DeleteAtBeg()
    {
        if (head==NULL)
        {
            cout<<"No Item Avilable";
        }
        else 
        {
            node*temp=head;
            head=head->next;
        }
    }


    void display()
    {
        node*temp=head;
        if(temp==NULL)
        {
            cout<<"\nList Is Empty....";
        }
        else
        {
            while(temp!=NULL)
            {
                cout<<temp->data<<"->";
                temp=temp->next;
            }
            cout<<"NULL";
        }
    }
};


int main()
{
    linked_list obj;
    int choice=0;
    while (1)
    {
        cout<<"\n1.For Insert\t2.For Display\n4.For Exit";
        cout<<"\nChoose a option and press Enter:-";
        cin>>choice;
        switch (choice)
        {
            case 1:
            {
                obj.insertAtEnd();
                break;
            }

            case 2:
            {
                obj.display();
                break;
            }

            case 3:
            {
                obj.DeleteAtBeg();
                break;
            }

            case 4:
            {
                exit(0);
            }
        }
    }
}