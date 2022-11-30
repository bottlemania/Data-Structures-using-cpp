#include<iostream>
using namespace std;
struct datanode{
    char data;
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
    bool pushStack(char dataIn){
        datanode *T=new datanode;
        T->data=dataIn;
        T->link=stackHead->top;
        stackHead->top=T;
        stackHead->count++;
        return true;
    }
    bool popStack(char &dataOut){
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
    bool stackTop(char &dataOut){
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
int priority(char ch){
    if(ch=='^')
    return 3;
    else if(ch=='*'||ch=='/')
    return 2;
    else if(ch=='+'||ch=='-')
    return 1;
    else if(ch=='(')
    return 0;
}
bool isOperator(char ch){
    if(ch=='^'||ch=='*'||ch=='/'||ch=='+'||ch=='-')
    return true;
    else
    return false;
}
void infixToPostfix(string str1,string &str2){
    Stack stack;
    int i=0;
    str2="";
    char token,topToken;
    while(str1[i]!='\0'){
        token=str1[i];
        if(token=='(')
            stack.pushStack(token);
        else if(token==')'){
            stack.popStack(topToken);
            while(!stack.emptyStack()&&topToken!='('){
                str2+=topToken;
                stack.popStack(topToken);
            }
        }
        else if(isOperator(token)){
            stack.stackTop(topToken);
            while(!stack.emptyStack()&&priority(topToken)>=priority(token)){
                stack.popStack(topToken);
                str2+=topToken;
                stack.stackTop(topToken);
            }
            stack.pushStack(token);
        }
        else
            str2+=token;
        i++;
    }
    while(!stack.emptyStack()){
        stack.popStack(token);
        str2+=token;
    }
}
int main(){
    string infix,postfix;
    cout<<"Enter the infix expression:";
    cin>>infix;
    infixToPostfix(infix,postfix);
    cout<<"\nPostfix Expression:"<<postfix;
    return 0;
}