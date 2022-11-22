#include<iostream>
using namespace std;
struct datanode
{
	int data;
	datanode *back;
	datanode *fore;
};
struct headnode
{
	int count;
	datanode *last;
	datanode *first;
};
class CDLL
{
	headnode *cdllhead;
	
	bool insertNode(datanode *&pPre,int dataIn)
	{
		datanode *pNew=new datanode;
		pNew->data=dataIn;
		pNew->back=pNew->fore=NULL;
		if(pPre==NULL)
		{
			if(emptyCDLL())
				cdllhead->first=cdllhead->last=pNew;
			else
				cdllhead->first->back=cdllhead->last->fore=pNew;
			pNew->fore=cdllhead->first;
			pNew->back=cdllhead->last;
			cdllhead->first=pNew;
		}
		else
		{
			if(pPre->fore==cdllhead->first)
				cdllhead->last=cdllhead->first->back=pNew;
			else
				pPre->fore->back=pNew;
			pNew->fore=pPre->fore;
			pNew->back=pPre;
			pPre->fore=pNew;
		}
		cdllhead->count++;
		return true;
	}
	
	bool deleteNode(datanode *&pPre,datanode *&pLoc,int &dataOut)
	{
		if(cdllhead->count==1)
			cdllhead->first=cdllhead->last=NULL;
		else if(pPre==NULL)
		{
			cdllhead->first=pLoc->fore;
			pLoc->fore->back=pLoc->back;
			cdllhead->last->fore=pLoc->fore;
		}
		else
		{
			pPre->fore=pLoc->fore;
			pLoc->fore->back=pPre;
			if(pLoc==cdllhead->last)
				cdllhead->last=pPre;
		}
		delete pLoc;
		cdllhead->count--;
		return true;
	}
	
	public:
		CDLL()
		{
			cdllhead=new headnode;
			cdllhead->count=0;
			cdllhead->first=cdllhead->last=NULL;
		}
		
		bool searchList(datanode *&pPre,datanode *&pLoc,int target,int &pos)
		{
			bool found;
			pPre=NULL;
			pLoc=cdllhead->first;
			pos=1;
			if(emptyCDLL())
			{
				pos=-1;
				return false;
			}
			else if(pLoc->data==target)
				return true;
			else if(target<pLoc->data)
			{
				pos=-1;
				return false;
			}
			pPre=pLoc;
			pLoc=pLoc->fore;
			pos++;
			while(pLoc!=cdllhead->first&&target>pLoc->data)
			{
				pPre=pLoc;
				pLoc=pLoc->fore;
				pos++;
			}
			if(pLoc==cdllhead->first)
			{
				pos=-1;
				return false;
			}
			else if(target==pLoc->data)
				found=true;
			else
			{
				pos=-1;
				return false;
			}
			return found;
		}
		
		bool addNode(int dataIn)
		{
			bool success=false,found;
			datanode *pPre,*pLoc;
			int pos;
			found=searchList(pPre,pLoc,dataIn,pos);
			if(!found)
				success=insertNode(pPre,dataIn);
			return success;
		}
		
		bool removeNode(int &dataOut)
		{
			bool success=false,found;
			datanode *pPre,*pLoc;
			int pos;
			found=searchList(pPre,pLoc,dataOut,pos);
			if(found)
				success=deleteNode(pPre,pLoc,dataOut);
			return success;
		}
		
		bool emptyCDLL()
		{
			if(cdllhead->count==0)
				return true;
			else
				return false;
		}
		bool fullCDLL()
		{
			datanode *temp;
			if(temp==NULL)
				return true;
			else
				return false;
		}
		
		int cdllCount()
		{
			return cdllhead->count;
		}
				
		void displayHeadToRear()
		{
			datanode *pWalker=new datanode;
			pWalker=cdllhead->first;
			if(pWalker!=NULL)
			{
				cout<<pWalker->data<<" ";
				pWalker=pWalker->fore;				
			}
			while(pWalker!=cdllhead->first)
			{
				cout<<pWalker->data<<" ";
				pWalker=pWalker->fore;
			}
		}

		void displayRearToHead()
		{
			datanode *pWalker=new datanode;
			pWalker=cdllhead->last;
			if(pWalker!=NULL)
			{
				cout<<pWalker->data<<" ";
				pWalker=pWalker->back;				
			}
			while(pWalker!=cdllhead->last)
			{
				cout<<pWalker->data<<" ";
				pWalker=pWalker->back;
			}
		}
		
		int searchCDLLFromHead(int target)
		{
			int pos;
			datanode *pPre,*pLoc;
			searchList(pPre,pLoc,target,pos);
			return pos;
		}
		
		int searchCDLLFromRear(int target)
		{
			int pos;
			datanode *pPre,*pLoc;
			searchList(pPre,pLoc,target,pos);
			if(pos==-1)
				return pos;
			else
				return cdllhead->count-pos+1;
		}
	
		~CDLL()
		{
			datanode *pWalker,*pLoc;
			pLoc=cdllhead->first;
			pWalker=NULL;
			if(!emptyCDLL())
			{
				pWalker=pLoc;
				pLoc=pLoc->fore;
				delete pWalker;
				while(pLoc!=cdllhead->first)
				{
					pLoc=pLoc->fore;
					delete pWalker;	
				}
			}
			cdllhead->first=cdllhead->last=NULL;
			cdllhead->count=0;
			delete cdllhead;
		}
};

int main()
{
	CDLL cdll;
	int choice,data;
	do
	{
		cout<<endl<<"Select the operation:"<<endl<<endl;
		cout<<"\n1.Insert\n2.Delete\n3.emptyCDLL\n4.fullCDLL\n5.nodeCount\n6.displayHTR\n7.displayRTH\n8.searchFromHead\n9.searchFromRear\n10.destroyCDLL"<<endl<<endl;
		cin>>choice;
		switch(choice)
		{
			case 1:
				cout<<"Enter the element to be inserted:";cin>>data;
				if(cdll.addNode(data))
					cout<<"					>> Element inserted successfully"<<endl;
				else
					cout<<"					>> Duplicate element.Cannot insert."<<endl;
				break;
			case 2:
				cout<<"Enter the element to be deleted:";cin>>data;
				if(cdll.removeNode(data))
					cout<<"					>> Element deleted successfully"<<endl;
				else
					cout<<"					>> Element not found"<<endl;
				break;
			case 3:
				if(cdll.emptyCDLL())
					cout<<"					>> List is empty"<<endl;
				else
					cout<<"					>> List is not empty"<<endl;
				break;
			case 4:
				if(cdll.fullCDLL())
					cout<<"					>> List is full."<<endl;
				else
					cout<<"					>> List is not full."<<endl;
				break;
			case 5:
				cout<<"					>> NodeCount:"<<cdll.cdllCount()<<endl;
				break;
			case 6:
				cout<<"					>> ";
				cdll.displayHeadToRear();
				break;
			case 7:
				cout<<"					>> ";
				cdll.displayRearToHead();
				break;
			case 8:
				cout<<"Enter the element to search from Head:";cin>>data;
				if(cdll.searchCDLLFromHead(data)==-1)
					cout<<"					>> Element not present"<<endl;
				else
					cout<<"					>> Element is present at "<<cdll.searchCDLLFromHead(data)<<endl;
				break;
			case 9:
				cout<<"Enter the element to search from Rear:";cin>>data;
				if(cdll.searchCDLLFromRear(data)==-1)
					cout<<"					>> Element not present"<<endl;
				else				
					cout<<"					>> Element is present at "<<cdll.searchCDLLFromRear(data)<<endl;
				break;
			default:
				cout<<"					>> Destroyed successfully"<<endl;
				break;				
		}
	}
	while(choice<10);
	return 0;
}












