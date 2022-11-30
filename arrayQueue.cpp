#include<iostream>
#define MAXSIZE 100
using namespace std;
class Queue{
    private:
    int queue[MAXSIZE],front,rear;
    public:
    Queue(){
        front=rear=-1;
    }
    bool enqueue(int dataIn){
        bool success=false;
        if(!fullQueue()){
            queue[++rear]=dataIn;
            if(front==-1)   front=0;
            success=true;
        }
        return success;
    }
    bool dequeue(int &dataOut){
        bool success=false;
        if(!emptyQueue()){
            dataOut=queue[front++];
            if(front>rear) rear=front=-1;
            success=true;
        }
        return success;
    }
    bool queueFront(int &dataOut){
        bool success=false;
        if(!emptyQueue()){
            dataOut=queue[front];
            success=true;
        }
        return success;
    }
    bool queueRear(int &dataOut){
        bool success=false;
        if(!emptyQueue()){
            dataOut=queue[rear];
            success=true;
        }
        return success;
    }
    bool emptyQueue(){
        if(front==-1)
            return true;
        else
            return false;
    }
    bool fullQueue(){
        if(rear==MAXSIZE-1)
            return true;
        else
            return false;
    }
    bool displayQueue(){
        cout<<"\nQueue:  ";
        for(int i=front;i<=rear;i++)
            cout<<queue[i]<<" ";
    }
    int queueCount(){
        return rear-front+1;
    }
};
int main(){
    Queue queue;
    int choice,data;
    label:
    cout<<"\nSelect the operation:"<<endl;
    cout<<"1.enqueue\n2.dequeue\n3.queueFront\n4.queueRear\n5.emptyQueue\n6.fullQueue\n7.queueCount\n8.displayQueue\n9.CLEAR\n10.EXIT\n0.ShowOptions";
    do{
        cout<<"\n\nEnter choice:";cin>>choice;
        switch(choice)
        {
            case 0:
            goto label;
            break;
            case 1:
            cout<<"\nEnter the element to be inserted:";
            cin>>data;
            if(queue.enqueue(data))
                cout<<"\nElement inserted successfully!";
            else
                cout<<"\nQueue full.Cannot Insert.";
            break;
            case 2:
            if(queue.dequeue(data))
                cout<<"\nElement removed is "<<data;
            else
                cout<<"\nQueue empty.Cannot dequeue.";
            break;
            case 3:
            if(queue.queueFront(data))
                cout<<"\nQueueFront is "<<data;
            else
                cout<<"\nQueue empty.Cannot find QueueFront.";
            break;
            case 4:
            if(queue.queueRear(data))
                cout<<"\nQueueRear is "<<data;
            else
                cout<<"\nQueue empty.Cannot find QueueRear.";
            break;            
            case 5:
            if(queue.emptyQueue())
                cout<<"\nQueue is empty.";
            else 
                cout<<"\nQueue is not empty.";
            break;
            case 6:
            if(queue.fullQueue())
            cout<<"\nQueue is full";
            else
            cout<<"\nQueue is not full";
            break;
            case 7:
            cout<<"\nQueue count is "<<queue.queueCount();
            break;
            case 8:
            queue.displayQueue();
            break;
            case 9:
            system("CLS");
            break;
            case 10:
            break;
            default:
            cout<<"\nChoose valid operation!"<<endl;
            break;
        }
    }
    while(choice!=10);
    return 0;
}