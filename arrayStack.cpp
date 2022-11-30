#include<iostream>
#define MAXSIZE 100
using namespace std;
class Stack{
    private:
    int stack[MAXSIZE],top;
    public:
    Stack(){
        top=-1;
    }
    bool pushStack(int dataIn){
        bool success=false;
        if(!fullStack()){
            stack[++top]=dataIn;
            success=true;
        }
        return success;
    }
    bool popStack(int &dataOut){
        bool success=false;
        if(!emptyStack()){
            dataOut=stack[top--];
            success=true;
        }
        return success;
    }
    bool stackTop(int &dataOut){
        bool success=false;
        if(!emptyStack()){
            dataOut=stack[top];
            success=true;
        }
        return success;
    }
    bool emptyStack(){
        if(top==-1)
            return true;
        else
            return false;
    }
    bool fullStack(){
        if(top==MAXSIZE)
            return true;
        else
            return false;
    }
    bool displayStack(){
        cout<<"\nStack:  "<<endl;
        for(int i=0;i<top;i++)
            cout<<stack[i]<<endl;
    }
};
int main(){
    Stack stack;
    int choice,data;
    label:
    cout<<"\nSelect the operation:"<<endl;
    cout<<"0.ShowOptions\n1.pushStack\n2.popStack\n3.stackTop\n4.emptyStack\n5.fullStack\n6.displayStack\n7.CLEAR\n8.EXIT";
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
            if(stack.fullStack())
            cout<<"\nStack is full";
            else
            cout<<"\nStack is not full";
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