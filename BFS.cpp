#include<iostream>
using namespace std;
#define MAXSIZE 100
struct adjlist{
	int ver;
	adjlist *next;
};
struct vertex{
	string name;
	bool processed;
	adjlist *first;
};
class Queue{
	private:
		int queue[MAXSIZE];
		int front,rear;
	public:
		Queue(){
			rear=front=-1;
		}
		bool enqueue(int dataIn){
			bool success=false;
			if(!fullQueue()){
				rear++;
				queue[rear]=dataIn;
				if(front==-1)
					front=0;
				success=true;
			}
			return success;
		}
		bool dequeue(int &dataOut){
			if(front==-1)
				return false;
			dataOut=queue[front];
			if(front==rear)
				front=rear=-1;
			else
				front++;
			return true;
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
};

class Graph{
	vertex G[10];
	int n;
	public:
		void createGraph(){
			cout<<"Enter the number of vertices:";
			cin>>n;
			for(int i=0;i<n;i++){
				int m,ind;
				cout<<"Enter name of the vertex:";
				cin>>G[i].name;
				cout<<"Enter the number of adjacent vertices to "<<G[i].name<<" :";
				cin>>m;
				G[i].first=NULL;
				for(int j=0;j<m;j++){
					cout<<"Enter the index of adjacent vertex-"<<j+1<<": ";
					cin>>ind;
					adjlist *T=new adjlist;
					T->ver=ind;
					T->next=G[i].first;
					G[i].first=T;
				}
			}
		}
		void BFS(int s){
			for(int i=0;i<n;i++){
				G[i].processed=false;
			}
			Queue Q;
			Q.enqueue(s);
			G[s].processed=true;
			while(!Q.emptyQueue()){
				int u;
				Q.dequeue(u);
				cout<<G[u].name<<", ";
				adjlist *t=G[u].first;
				while(t!=NULL){
					if(!G[t->ver].processed){
						Q.enqueue(t->ver);
						G[t->ver].processed=true;
					}
					t=t->next;
				}
			}
		}
		void display(){
			cout<<"\nGraph: "<<endl;
			for(int i=0;i<n;i++){
				cout<<G[i].name;
				adjlist *t=G[i].first;
				while(t!=NULL){
					cout<<" -->"<<t->ver;
					t=t->next;
				}
				cout<<endl;
			}
		}
};
int main(){
	Graph graph;
	int s;
	graph.createGraph();
	cout<<"Enter the start vertex index:";cin>>s;
	graph.BFS(s);
	graph.display();
	return 0;
}