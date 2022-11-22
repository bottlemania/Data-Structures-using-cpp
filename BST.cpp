#include<iostream>
using namespace std;
struct treenode
{
	int data;
	treenode *left,*right;
};
struct headnode
{
	int count;
	treenode *root;
};
class BST
{
	headnode *treehead;
	public:
		BST()
		{
			treehead=new headnode;
			treehead->count=0;
			treehead->root=NULL;
		}
		treenode* RInsert(treenode *T,int key,bool &success)
		{
			if(T==NULL)
			{
				treenode *X=new treenode;
				X->data=key;
				X->left=X->right=NULL;
				success=true;
			return X;
			}
			else if(key<T->data)	T->left=RInsert(T->left,key,success);
			else if(key>T->data)	T->right=RInsert(T->right,key,success);
			else if(key==T->data)	success=false;
		}
		treenode* RDelete(treenode *T,int dltkey,bool &success)
		{
			if(T==NULL)
			{
				success=false;
				return T;
			}
			else 
			{
				if(T->data<dltkey)		T->right=RDelete(T->right,dltkey,success);
				else if(T->data>dltkey)	T->left=RDelete(T->left,dltkey,success);
				else if(T->data==dltkey)
				{
					if(T->left==NULL)
					{
						treenode *temp=T->right;
						delete T;
						success=true;
						return temp;
					}
					else if(T->right==NULL)
					{
						treenode *temp=T->left;
						delete T;
						success=true;
						return temp;
					}
					else if(T->left!=NULL&&T->right!=NULL)
					{
						treenode *temp=SmallestBST(T->right);
						T->data=temp->data;
						T->right=RDelete(T->right,temp->data,success);
					}
				}
				else	success=false;
			}
			return T;
		}
		
		bool RSearch(treenode *T,int target)
		{
			bool success;
			if(T==NULL)					success=false;
			else if(T->data>target)		success=RSearch(T->left,target);
			else if(T->data<target)		success=RSearch(T->right,target);
			else if(T->data==target)	success=true;
			return success;
		}
		
		bool addBST(int dataIn)
		{
			bool success;
			treehead->root=RInsert(treehead->root,dataIn,success);
			if(success)	treehead->count++;
			return success;
		}
		bool deleteBST(int dltkey)
		{
			bool success;
			treehead->root=RDelete(treehead->root,dltkey,success);
			if(success)	treehead->count--;
			return success;
		}
		bool retrieveBST(int target)
		{
			bool success;
			success=RSearch(treehead->root,target);
			return success;
		}
		
	int BSTCount()
	{
		return treehead->count;
	}
	treenode* BSTRoot()
	{
		return treehead->root;
	}
	bool emptyBST()
	{
		if(treehead->count==0)	return true;
		else	return false;
	}
	
	treenode* LargestBST(treenode *T)
	{
		treenode *current=T;
		while(current->right!=NULL)	current=current->right;
		return current;
	}
	treenode* SmallestBST(treenode *T)
	{
		treenode *current=T;
		while(current->left!=NULL)	current=current->left;
		return current;
	}	
	void traversal(int order)
	{
		if(order==1)	inorder(treehead->root);
		else if(order==2)	preorder(treehead->root);
		else if(order==3)	postorder(treehead->root);
	}	
	void preorder(treenode *T)
	{
		if(T!=NULL)
		{
			cout<<T->data<<", ";
			preorder(T->left);
			preorder(T->right);
		}
	}
	void inorder(treenode *T)
	{
		if(T!=NULL)
		{
			inorder(T->left);
			cout<<T->data<<", ";
			inorder(T->right);
		}
	}
	void postorder(treenode *T)
	{
		if(T!=NULL)
		{
			postorder(T->left);
			postorder(T->right);
			cout<<T->data<<", ";
		}
	}	
		
};
int main(){
	BST bst;
	int choice=0,data;
	label:
	cout<<"\nSelect the operation:"<<endl;
	cout<<"\n0.Show options\n1.Insert\n2.Delete\n3.Traversal\n4.EmptyBST\n5.Retrieve"
	<<"\n6.Count\n7.findSmallest\n8.findLargest\n9.DestroyBST\n10.CLEAR"<<endl<<endl;
	do{
		cout<<"Enter Choice:";cin>>choice;
		switch(choice){
			case 0:
				goto label;
			case 1:
				cout<<"Enter the element to be inserted:";cin>>data;
				if(bst.addBST(data))
					cout<<"					>> Element inserted successfully."<<endl;
				else
					cout<<"					>> Duplicate element.Cannot Insert."<<endl;
				break;
			case 2:
				cout<<"Enter the element to be deleted:";cin>>data;
				if(bst.deleteBST(data))
					cout<<"					>> Element deleted successfully."<<endl;
				else
					cout<<"					>> Element not found."<<endl;
				break;
			case 3:
				cout<<"Select:\n1-Inorder\t2-Preorder\t3-Postorder"<<endl;
				cin>>data;
				cout<<endl<<"					>> ";
				bst.traversal(data);cout<<endl;
				break;
			case 4:
				if(bst.emptyBST())
					cout<<"					>> BST is empty."<<endl;
				else
					cout<<"					>> BST is not empty."<<endl;
				break;
			case 5:
				cout<<"Enter the element to be retrieved:";cin>>data;
				if(bst.retrieveBST(data))
					cout<<"					>> Element found."<<endl;
				else
					cout<<"					>> Element not found."<<endl;
				break;
			case 6:
				cout<<"					>> Number of nodes in BST:"<<bst.BSTCount()<<endl;
				break;
			case 7:
				cout<<"					>> Smallest element in BST:"<<bst.SmallestBST(bst.BSTRoot())->data<<endl;
				break;
			case 8:
				cout<<"					>> Largest element in BST:"<<bst.LargestBST(bst.BSTRoot())->data<<endl;
				break;
			case 9:
				cout<<"					>> Destroyed successfully."<<endl;
				break;
			case 10:
				system("CLS");
				break;
			default:
				cout<<"					>> Select valid operation."<<endl;
				break;
		}
	}
	while(choice!=9);
	return 0;
}
