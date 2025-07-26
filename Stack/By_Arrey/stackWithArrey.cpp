//25 JUL 2025

#include <iostream>
#define SIZE 100

using std::cout,std::cin;

class Stack {
private:
    int top=0;
    int Arr[SIZE];
public:
    int val=0;

    bool IsFull() {
        return (top==SIZE-1);
    }
    bool isEmpty() {
        return (top==-1);
    }

    int getItem() {
        if (IsFull()) {
            cout<<"\nStack is Full.";
        }else {
            cout<<"\nEnter The Value:-";
            cin>>val;
        }
        return val;
    }
    void push(int val) {
        if (!IsFull()) {
            Arr[top]=val;
            top++;
        }
    }

    void pop() {
        if (isEmpty()) {
            cout<<"\nStack is Empty...";
        }else {
            top--;
        }
    }
    void ShowArr() {
        if (isEmpty()) {
            cout<<"\nStack is Empty...";
        }else {
            for (int i=0;i<top;i++) {
                cout<<Arr[i]<<"\n";
            }
        }
    }

};

int main() {
    Stack obj;
    while (true) {
        int choice=0;
        cout<<"\n1.For PUSH\t2.For POP\t3.Exit\t4.Show Arr";
        cout<<"\nEnter Your Choice...";
        cin>>choice;
        switch (choice) {
            case 1: {
                //push
                obj.push(obj.getItem());
                obj.ShowArr();
                break;
            }
            case 2: {
                //POP
                obj.pop();
                obj.ShowArr();
                break;
            }
            case 3: {
                exit(0);
            }default: {
                cout<<"\nChoose Correct option...";
                break;;
            }
            case 4: {
                obj.ShowArr();
                break;
            }
        }
    }
    return 0;
}