#include<iostream>
using namespace std;
struct datanode{
    int data;
    datanode *link;
};
struct headnode{
    int count;
    datanode *top;
};
class Stack{
    headnode *stackHead;
    public:
    Stack(){
        stackHead=new headnode;
        stackHead->count=0;
        stackHead->top=NULL;
    }
    bool pushStack(int dataIn){
        datanode *T=new datanode;
        T->data=dataIn;
        T->link=stackHead->top;
        stackHead->top=T;
        stackHead->count++;
        return true;
    }
    bool popStack(int &dataOut){
        bool success=false;
        if(!emptyStack()){
            datanode *T=new datanode;
            T=stackHead->top;
            dataOut=T->data;
            stackHead->top=T->link;
            delete T;
            stackHead->count--;
            success=true;
        }
        return success;
    }
    bool stackTop(int &dataOut){
        bool success=false;
        if(!emptyStack()){
            dataOut=stackHead->top->data;
            success=true;
        }
        return success;
    }
    bool emptyStack(){
        if(stackHead->count==0)     return true;
        else                        return false;
    }
    int stackCount(){
        return stackHead->count;
    }
    void displayStack(){
        datanode *T=new datanode;
        T=stackHead->top;
        while(T!=NULL){
            cout<<T->data<<" ";
            T=T->link;
        }
    }
    ~Stack(){
        while(stackHead->top!=NULL){
            datanode *T=new datanode;
            T=stackHead->top;
            stackHead->top=T->link;
            delete T;
            stackHead->count--;
        }
        delete stackHead;
    }
};
int main(){
    Stack stack;
    int choice,data;
    label:
    cout<<"\nSelect the operation:"<<endl;
    cout<<"1.pushStack\n2.popStack\n3.stackTop\n4.emptyStack\n5.stackCount\n6displayStack\n7.CLEAR\n8.EXIT\n0.ShowOptions";
    do{
        cout<<"\n\nEnter choice:";cin>>choice;
        switch(choice)
        {
            case 0:
            goto label;
            break;
            case 1:
            cout<<"\nEnter the element to be pushed:";
            cin>>data;
            if(stack.pushStack(data))
                cout<<"\nElement pushed successfully!";
            else
                cout<<"\nStack full.Cannot Insert.";
            break;
            case 2:
            if(stack.popStack(data))
                cout<<"\nElement popped is "<<data;
            else
                cout<<"\nStack empty.Cannot pop.";
            break;
            case 3:
            if(stack.stackTop(data))
                cout<<"\nStackTop is "<<data;
            else
                cout<<"\nStack empty.Cannot find StackTop.";
            break;
            case 4:
            if(stack.emptyStack())
                cout<<"\nStack is empty.";
            else 
                cout<<"\nStack is not empty.";
            break;
            case 5:
            cout<<"StackCount is "<<stack.stackCount();
            break;
            case 6:
            stack.displayStack();
            break;
            case 7:
            system("CLS");
            break;
            case 8:
            break;
            default:
            cout<<"\nChoose valid operation!"<<endl;
            break;
        }
    }
    while(choice!=8);
    return 0;
}    