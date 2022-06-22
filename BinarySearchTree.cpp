#include<bits/stdc++.h>
using namespace std;
struct node{
	int info;
	node *right;
	node *left;
};
struct node *GetNewNode(int val){
	node *NewNode=new node();
	NewNode->info=val;
	NewNode->right=NULL;
	NewNode->left=NULL;
		return NewNode;
}
struct node *Insert(node *root,int val){
	if(root==NULL)
		root=GetNewNode(val);
	else if(val<root->info)
		root->left=Insert(root->left,val);
	else if(val>root->info)
		root->right=Insert(root->right,val);
	else
		cout<<"Duplicate Key\n";
	return root;				
}
void LevelOrderTraversal(node *root){
	if(root==NULL)
		return;
	queue<node*> q;
	q.push(root);
	while(!q.empty()){
		node *current=q.front();
		cout<<current->info<<" ";
		if(current->left!=NULL)
			q.push(current->left);
		if(current->right!=NULL)
			q.push(current->right);	
		q.pop();	
	}
	cout<<endl;
}
int FindMax(node *root){
	if(root==NULL){
		cout<<"Tree is Empty\n";
		return 0;
		}
		node *current=root;
		while(current->right!=NULL)
			current=current->right;
		cout<<"Maximum Number is "<<current->info<<endl;	
		
}
void FindMin(node *root){
	if(root==NULL){
		cout<<"Tree is empty\n";
		return;
	}
	node *current=root;
	while(current->left!=NULL)
			current=current->left;
	cout<<"Minumn value is "<<current->info<<endl;		
	}
struct node *Search(node *root,int val){
	if(root==NULL){
		cout<<"Not found\n";
		return NULL;
	}
	else if(val<root->left->info)
		return Search(root->left,val);
	else if(val>root->right->info)
		return Search(root->right,val);
	else 
	return root;	
}
node *findmaxad(node *root)
{
	while(root->right!=NULL)
	root=root->right;
	return root;
}
node *deletenode(node *root,int val)
{
	node *temp;
	if(root==NULL)
		return NULL;
	
	else if(val>root->info)
		root->right=deletenode(root->right,val);
		
	else if(val<root->info)
		root->left=deletenode(root->left,val);	
		
	else
	{
		//CASE 1: 2 CHILDREN
		if(root->right&&root->right)
		{
			temp=findmaxad(root->left);
			root->info=temp->info;
			root->left=deletenode(root->left,root->info);
		}
		//CASE 2: 1 CHILDREN
		else if(root->left==NULL)
		{
			temp=root;
			root=root->right;
			delete temp;		
		}
		else if(root->right==NULL)
		{
			temp=root;
			root=root->left;
			delete temp;
		}
		//CASE 3: NO CHiLDREN
		else
		{
			delete root;
			root=NULL;
		}
	}	
	return root;
}

int main()
{
	node *root;
	root=NULL;
	int val,choice;
	while(1){
		cout<<"1=Insert Value\n";
		cout<<"2=Level Order Traversal\n";
		cout<<"3=Find Maxmum\n";
		cout<<"4=Find Minimum\n";
		cout<<"5=Search\n";
		cout<<"6=Delete\n";
		cout<<"Enter your choice\n";
		cin>>choice;
		
		switch(choice){
			case 1:
				cout<<"Enter the val to be inserted\n";
				cin>>val;
				root=Insert(root,val);
				break;
				
			case 2:
				LevelOrderTraversal(root);
				break;
			
			case 3:
				FindMax(root);
				break;	
			
			case 4:
					FindMin(root);
					break;
			
			case 5:
					cout<<"Enter the number to be searched\n";
					cin>>val;
					root=Search(root,val);
					if(root==NULL)
						cout<<"Number is not present\n";
					else
						cout<<"Number is presnt\n";	
						break;
			
			case 6:
				cout<<"Enter the number to be deleted\n";
				cin>>val;
				root=deletenode(root,val);
				break;						
		}	
	}
	return 0;
}
