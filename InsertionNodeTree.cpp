#include<iostream>      //Inserting nodes in Binary Search Tree
using namespace std;
struct BSTNode{
	BSTNode* left;
	int data;
	BSTNode* right;
};
BSTNode* GetNewNode(int data);
BSTNode* Insert(BSTNode* root, int data);
bool Search(BSTNode *root,int data);
int main()
{

	BSTNode* root=NULL;
	root=Insert(root,15);
	root=Insert(root,10);
	root=Insert(root,20);
	root=Insert(root,25);
	root=Insert(root,8);
	root=Insert(root,12);

	int number;
	cout<<"\nEnter no. to be searched : \n";
	cin>>number;
	if(Search(root,number)==true)
		cout<<"Found\n";
	else
		cout<<"Not Found\n";


return 0;
}

BSTNode* Insert(BSTNode* root, int data)
{
	if(root==NULL)
		root=GetNewNode(data);

	else if(data <= root->data)
		root->left = Insert(root->left, data);

	else
		root->right = Insert(root->right, data);

	return root;
}

BSTNode* GetNewNode(int data)
{
	BSTNode* newNode = new BSTNode();
	newNode->data= data;
	newNode->left=newNode->right=NULL;

	return newNode;
}
bool Search(BSTNode *root,int data)
{
	if(root==NULL)
		return false;
	else if(root->data==data)
		return true;
	else if(data <= root->data)
		return Search(root->left,data);
	else
		return Search(root->right,data);
}