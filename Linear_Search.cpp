//
// Created by krish on 31-08-2025.
//

#include<iostream>

using namespace std;
class arr
{
public:
    int A[100] = {
        45, 12, 89, 33, 27,
        67, 5, 90, 54, 38,
        72, 18, 61, 3, 81,
        29, 47, 10, 95, 6
    };

    int AddItem(){
        int A;
        cout<<"\nEnter The Item:-";
        cin>>A;
        return A;
    }
    void addArr() {
        cout<<"\nEnter The index position:";
        int index;
        cin>>index;
        int N=sizeof(A)/sizeof(A[0]);
        if (index>N-1||index<0) {
            cout<<"\nInvalid Index...";
        }else {
            A[index]=AddItem();
        }
    }
    int sizeof_arr()
    {
        return sizeof(A)/sizeof(A[0]);
    }
};

class linear_Search {
public:
    arr obj;
    int get_item(){
        cout<<"\nEnter The Number Which You Want To Search:-";
        int item;
        cin>>item;
        return (item);
    }

    void DisplayArr() {
        cout<<"\n";
        int N=obj.sizeof_arr();
        for (int i=0;i<N;i++) {
            cout<<obj.A[i]<<",";
        }
    }

    void get_position(){
        bool flag=0;
        int key=get_item();
        int i=0,N=obj.sizeof_arr();
        for (i=0;i<N;i++){
            if (obj.A[i]==key){
                cout<<"\nAvilable at the index="<<i;
                flag=true;
                break;
            }
        }
        if (!flag) {
            cout<<"\nitem Is Not Avilable ";
        }
    }

    void get_positonByidex() {
        cout<<"\nEnter The Position:-";
        int key;cin>>key;
        int N= obj.sizeof_arr();

        if (key>N-1||key<0) {
            cout<<"\ninvalid Index...";
        }else{
            cout<<"\nThe item is "<<obj.A[key];
        }
    }

    void BubbleSort() {
    int temp=0;
    int N=obj.sizeof_arr();
    for (int i=0;i<N;i++) {
           for (int j=0;j<N-i-1;j++) {
                if (obj.A[j]>obj.A[1+j]) {
                    temp=obj.A[j];
                    obj.A[j]=obj.A[j+1];
                    obj.A[j+1]=temp;
                }
            }
        }
    }

    void bin_Search() {
        bool flag=false;
        int key=obj.AddItem();
        int low=0,mid;
        int high=obj.sizeof_arr()-1;
        while (low<=high) {
            mid=low+(high-low)/2;
            if (obj.A[mid]==key) {
                flag=true;
                break;
            }
            if (obj.A[mid]>key) {
                high=mid-1;
            }
            else {
                low=mid+1;
            }
        }
        if (!flag) {
            cout<<"Item Not Found..";
        }else {
            cout<<"\nThe Index is "<<mid;
        }
    }
};

int main (){
    int choice;
    linear_Search obj;
    while (true){
        cout<<"\n1.For Search\t2.For Search By index\t3.For Exit\t4.For Add Element In Array\n5.For Bubble Sort";
        cout<<"\n6.For Display";
        cout<<"\nEnter Your Choice-";
        cin>>choice;
        switch (choice)
        {
            case 1:
            {
                obj.get_position();
                break;
            }
            case 2:
            {
                obj.get_positonByidex();
                break;
            }
            case 3:
            {
                exit(0);
            }
            case 4:
            {
                obj.obj.addArr();
                break;
            }
            case 5: {
                obj.BubbleSort();
                break;
            }
            case 6: {
                obj.DisplayArr();
                break;
            }
            default:
            {
                cout<<"\nWrong Choice...";
                break;
            }
        }
    }
}