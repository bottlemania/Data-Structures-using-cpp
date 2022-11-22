#include<iostream>
using namespace std;
struct datanode
{
	datanode *back;
	int data;
	datanode *fore;
};
struct headnode
{
	int count;
	datanode *last;
	datanode *first;
};
class DLL
{
	headnode *dllhead;
	bool insertNode(datanode *pPre,int dataIn)
	{
		datanode *pNew=new datanode;
		pNew->data=dataIn;
		pNew->back=pNew->fore=NULL;
		if(pPre==NULL)
		{
			if(emptyDLL())
				dllhead->last=pNew;
			else
				dllhead->first->back=pNew;
			pNew->fore=dllhead->first;				
			dllhead->first=pNew;
		}
		else
		{
			pNew->back=pPre;
			pNew->fore=pPre->fore;
			if(pPre->fore!=NULL)
				pPre->fore->back=pNew;
			else
				dllhead->last=pNew;
			pPre->fore=pNew;
		}
		dllhead->count++;
		return true;
	}
	bool deleteNode(datanode *&pLoc,int &dataOut)
	{
		dataOut=pLoc->data;
		if(pLoc->back==NULL)
			dllhead->first=pLoc->fore;
		else
			pLoc->back->fore=pLoc->fore;
		if(pLoc->fore==NULL)
			dllhead->last=pLoc->back;
		else
			pLoc->fore->back=pLoc->back;
		dllhead->count--;
		delete pLoc;
		return true;
	}
	
	public:
		DLL()
		{
			dllhead=new headnode;
			dllhead->count=0;
			dllhead->first=dllhead->last=NULL;
		}
	
		bool emptyDLL()
		{
			if(dllhead->count==0)
				return true;
			else
				return false;
		}
		int nodeCount()
		{  
			return dllhead->count;
		}
		bool searchList(datanode *&pPre,datanode *&pLoc,int target,int &pos)
		{
			bool found;
			pPre=NULL;
			pLoc=dllhead->first;
			pos=1;
			while((pLoc!=NULL)&&(target>pLoc->data))
			{
				pPre=pLoc;
				pLoc=pLoc->fore;
				pos++;
			}
			if(pLoc==NULL)
				found=false;	
			else if(target==pLoc->data)
				found=true;
			else
				found=false;
			return found;
		}
		bool addDLL(int dataIn)
		{
			bool found,success=false;
			datanode *pPre,*pLoc;
			int pos;
			found=searchList(pPre,pLoc,dataIn,pos);
			if(!found)
				success=insertNode(pPre,dataIn);
			return success;
		}
		bool removeDLL(int &dataOut)
		{
			bool found,success=false;
			datanode *pPre,*pLoc;
			int pos;
			found=searchList(pPre,pLoc,dataOut,pos);
			if(found)
				success=deleteNode(pLoc,dataOut);
			return success;
		}
		void displayHeadToRear()
		{
			datanode *pWalker=new datanode;
			pWalker=dllhead->first;
			while(pWalker!=NULL){
				cout<<pWalker->data<<",";
				pWalker=pWalker->fore;
			}
			delete(pWalker);
			cout<<endl;
		}
		void displayRearToHead()
		{
			datanode *pWalker=new datanode;
			pWalker=dllhead->last;
			while(pWalker!=NULL)
			{
				cout<<pWalker->data<<",";
				pWalker=pWalker->back;
			}
			delete(pWalker);
			cout<<endl;
		}
		int searchDLLFromHead(int target)
		{
			int pos;
			datanode *pPre,*pLoc;
			if(searchList(pPre,pLoc,target,pos))
				return pos;
			else
				cout<<"					>> Element not Found"<<endl;
			return -1;		
		}
		int searchDLLFromRear(int target)
		{
			int pos;
			datanode *pPre,*pLoc;
			if(searchList(pPre,pLoc,target,pos))
				return dllhead->count-pos+1;
			else
				cout<<"					>> Element not Found"<<endl;		
			return -1;
		}
		~DLL()
		{
			datanode *pWalker,*pLoc;
			pLoc=dllhead->first;
			pWalker=NULL;
			while(pLoc!=dllhead->first&&!emptyDLL())
			{
				pWalker=pLoc;
				pLoc=pLoc->fore;
				delete pWalker;
			}
			dllhead->count=0;
			dllhead->first=dllhead->last=NULL;
			delete dllhead;
		}
};
int main()
{
	DLL dll;
	int choice,data;
	do
	{
		cout<<endl<<"Select the operation:"<<endl<<endl;
		cout<<"\n1.Insert\n2.Delete\n3.emptyDLL\n4.nodeCount\n5.displayHTR\n6.displayRTH\n7.searchFromHead\n8.searchFromRear\n9.destroyDLL"<<endl<<endl;
		cin>>choice;
		switch(choice)
		{
			case 1:
				cout<<"Enter the element to be inserted:";cin>>data;
				if(dll.addDLL(data))
					cout<<"					>> Element inserted successfully"<<endl; 
				else
					cout<<"					>> Duplicate element.Cannot insert."<<endl;
				break;
			case 2:
				cout<<"Enter the element to be deleted:";cin>>data;
				if(dll.removeDLL(data))
					cout<<"					>> Element deleted successfully"<<endl;
				else
					cout<<"					>> Element not found"<<endl;
				break;
			case 3:
				if(dll.emptyDLL())
					cout<<"					>> List is empty"<<endl;
				else
					cout<<"					>> List is not empty"<<endl;
				break;
			case 4:
				cout<<"					>> NodeCount:"<<dll.nodeCount()<<endl;
				break;
			case 5:
				cout<<"					>> ";
				dll.displayHeadToRear();
				break;
			case 6:
				cout<<"					>> ";
				dll.displayRearToHead();
				break;
			case 7:
				cout<<"Enter the element to search from Head:";cin>>data;
				if(dll.searchDLLFromHead(data)!=-1)			
					cout<<"					>> Element is present at "<<dll.searchDLLFromHead(data)<<endl;
				break;
			case 8:
				cout<<"Enter the element to search from Rear:";cin>>data;
				if(dll.searchDLLFromRear(data)!=-1)			
					cout<<"					>> Element is present at "<<dll.searchDLLFromRear(data)<<endl;
				break;
			default:
				cout<<"					>> Destroyed successfully"<<endl;
				break;				
		}
	}
	while(choice<9);
	return 0;
}
