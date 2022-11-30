#include<iostream>
using namespace std;
struct datanode
{
    int data;
    datanode *link;
};
struct headnode
{
    int count;
    datanode *head;
};
class SLL{
    headnode *list;
    bool insertNode(datanode *&pPre,int dataIn){
        datanode *pNew=new datanode;
        pNew->data=dataIn;
        pNew->link=NULL;
        if(pPre==NULL){
            pNew->link=list->head;
            list->head=pNew;
        }
        else{
            pNew->link=pPre->link;
            pPre->link=pNew;
        }
        list->count++;
        return true;
    }
    bool deleteNode(datanode *&pPre,datanode *&pLoc,int dataOut){
        dataOut=pLoc->data;
        if(pPre==NULL)
            list->head=pLoc->link;
        else
            pPre->link=pLoc->link;
        delete pLoc;
        list->count--;
        return true;
    }
    public:
    SLL(){
        list=new headnode;
        list->count=0;
        list->head=NULL;
    }
    bool searchList(datanode *&pPre,datanode *&pLoc,int target){
        bool found;
        pPre=NULL;
        pLoc=list->head;
        while(pLoc!=NULL&&target>pLoc->data){
            pPre=pLoc;
            pLoc=pLoc->link;
        }
        if(pLoc==NULL)
            found=false;
        else{
            if(target==pLoc->data)
                found=true;
            else
                found=false;
        }
        return found;
    }
    bool addNode(int dataIn){
        bool success=false,found;
        datanode *pPre,*pLoc;
        found=searchList(pPre,pLoc,dataIn);
        if(!found)
            success=insertNode(pPre,dataIn);
        return success;
    }
    bool removeNode(int &dataOut){
        bool success=false,found;
        datanode *pPre,*pLoc;
        found=searchList(pPre,pLoc,dataOut);
        if(found)
            success=deleteNode(pPre,pLoc,dataOut);
        return success;
    }
    bool emptyList(){
        if(list->count==0)
            return true;
        else
            return false;
    }
    int listCount(){
        return list->count;
    }
    bool retrieveNode(int &dataOut){
        datanode *pPre,*pLoc;
        bool found=searchList(pPre,pLoc,dataOut);
        if(found)
            dataOut=pLoc->data;
        return found;
    }
    void traverseList(){
        datanode *pWalker;
        if(emptyList())
            cout<<"\nList is empty.";
        else{
            pWalker=list->head;
            while(pWalker!=NULL){
                cout<<pWalker->data<<" ";
                pWalker=pWalker->link;
            }
        }
    }
    ~SLL(){
        datanode *pWalker;
        pWalker=list->head;
        while(pWalker!=NULL){
            pWalker=pWalker->link;
            delete pWalker;
            list->count--;
        }
        delete list;
        cout<<"List destroyed successfully."<<endl;
    }
};
int main()
{
	SLL list;
	int choice,data;
	label:
		cout<<"\nSelect the operation: "<<endl<<endl;
		cout<<"1.addNode\n2.removeNode\n3.retrieveNode\n4.traverseList\n5.emptyList\n6.listCount\n7.CLEAR\n8.destroyList\n0.ShowOptions";
    do{
        cout<<"\n\nEnter Choice:";
		cin>>choice;
		switch(choice)
		{
            case 0:
            goto label;
            break;
			case 1:
				cout<<"Enter the data to insert:";
				cin>>data;
				if(list.addNode(data))
				cout<<"					>>Succesfully inserted."<<endl;
				else
				cout<<"					>>Duplicate element.Cannot insert."<<endl;
				break;
			case 2:
				cout<<"Enter the data to delete:";
				cin>>data;
				if(list.removeNode(data))
				cout<<"					>>Succesfully deleted element "<<data<<endl;
				else	
				cout<<"					>>Element not present in the list.Cannot delete."<<endl;
				break;
			case 3:
				cout<<"Enter the data to be retrieved:"<<endl;
				cin>>data;
				if(list.retrieveNode(data))
				cout<<"					>>Successfully retrieved data "<<data<<endl;
				else
				cout<<"					>>Data not present in the list.Cannot retrieve."<<endl;
				break;
			case 4:
				cout<<"					List: ";list.traverseList();
				cout<<endl;
				break;
			case 5:
				if(list.emptyList())
				cout<<"					>>List is empty."<<endl;
				else
				cout<<"					>>List is not empty."<<endl;
				break;
			case 6:
				cout<<"					>>List Count="<<list.listCount()<<endl;
				break;
            case 7:
                system("CLS");
                break;
            case 8:
                break;
            default:
                cout<<"Choose valid operation!"<<endl;
                goto label;
                break;	
		}
	}
	while(choice!=8);
	return 0;
}