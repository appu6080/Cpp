//
// Created by krish on 26-7-25.
//
#include <iostream>
#include <cstdlib>

using std::cout,std::cin;

class node {
private:
public:
    int data;
    node*next;

    node(int val){
        data=val;
        next=NULL;
    }
};

class LinkedList {
private:
    node*head=NULL;
public:
    int val;
    int GetValue() {
        cout<<"\nEnter The Value..";
        cin>>val;
        return val;
    }
    bool isEmpty() {
        bool temp=false;
        if (head==NULL) {
            cout<<"\nList is Empty...";
            temp=true;
        }
        return (temp);
    }
    void InsertAtEnd () {
        node*Ptr=new node(this->GetValue());
        if (head==NULL) {
            head=Ptr;
        }
        else {
            node*temp=head;
            while (temp->next!=NULL) {
                temp=temp->next;
            }
            temp->next=Ptr;
        }
    }
    void InsertAtBegening() {
       // node*Temp=head;
        node*NewPtr=new node(this->GetValue());
        if (head==NULL) {
            head=NewPtr;
        }
        else {
            NewPtr->next=head;
            head=NewPtr;
        }
    }
    void DeleteFromBegening() {
        if (!isEmpty()) {
            node*Temp=head;
            head=head->next;
            delete Temp;
        }
    }
    void DeleteAtEnd() {

    }
    void Display() {
        node*Ptr=head;
        if (!isEmpty()) {
            while (Ptr!=NULL) {
                cout<<Ptr->data<<"->";
                Ptr=Ptr->next;
            }cout<<"NULL";
        }
    }
};

int main() {
    LinkedList obj;
    while (true) {
        int choice=0;
        cout<<"\n1.For Insert\t2.For Delete\t3.Exit\t4.Display";
        cout<<"\nEnter Your Choice...";
        cin>>choice;
        switch (choice) {
            case 1: {
                //push
                obj.InsertAtEnd();
                obj.Display();
                break;
            }
            case 2: {
                //POP
                obj.InsertAtBegening();
                break;
            }
            case 3: {
                exit(0);
            }default: {
                cout<<"\nChoose Correct option...";
                break;;
            }
            case 4: {
                obj.Display();
                break;
            }
            case 5: {
                obj.DeleteFromBegening();
                obj.Display();
                break;
            }
            case 6: {
                obj.isEmpty();
                break;
            }
        }
    }
    return 0;
}