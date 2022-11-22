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
class Stack{
    int stack[MAXSIZE];
    int top;
    public:
    Stack(){
        top=-1;
    }
    bool pushStack(int dataIn){
        bool success=false;
        if(top!=MAXSIZE){
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
    bool emptyStack(){
        if(top==-1)
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

		void DFS(){
			for(int i=0;i<n;i++){
				G[i].processed=false;
			}
			Stack S;
            for(int i=0;i<n;i++){
                if(G[i].processed==false){
                    S.pushStack(i);
			    while(!S.emptyStack()){
                    int u;
                    S.popStack(u);
                    if(G[u].processed==false){
                        cout<<G[u].name<<", ";
                        G[u].processed=true;
                        adjlist *t=G[u].first;
                        while(t!=NULL){
                            int v=t->ver;
                            S.pushStack(v);
                            t=t->next;
                        }
                    }   
                    }
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
	graph.createGraph();
	graph.DFS();
	graph.display();
	return 0;
}
