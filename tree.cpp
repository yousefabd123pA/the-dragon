#include <iostream>
using namespace std;
class node {
public:
	int data;
	node* left;
	node* right;
	node(int valu)
	{
		data = valu;
		left = right = NULL;
	}

};

class BST
{
public:
	node* root;

	BST()
	{
		root = NULL;
	}

	node* insert(node* root, int item)
	{
		node* newnode = new node(item);
		newnode->left = NULL;
		newnode->right = NULL;


		if (root == NULL)
		{
			newnode->data = item;
			root = newnode;
		}

		else if (item< root->data)
		{
			root->left = insert(root->left, item);

		}

		else
		{
			root->right = insert(root->right, item);
		}
		return root; //root which return is the last newnode inserted



	}


	void insert(int item)
	{

		root = insert(root, item);
	};
	                          //preorder         //inorder              //postorder
	void preorder(node* root)//root->left->right---left->root->right---left->right->root
	{
		if (root == NULL)
		{
			return;
		}
		else
			cout << root->data << "\t";
		preorder(root->left);
		preorder(root->right);


	}

	void postorder(node* root)
	{
		if (root == NULL)
		{
			return;
		}
		else
		postorder(root->left);
		postorder(root->right);
		cout << root->data << "\t";


	}
	void inorder(node* root)
	{
		if (root == NULL)
		{
			return;
		}
		else
		inorder(root->left);
		cout << root->data << "\t";

		inorder(root->right);

	}


}


; int main()
{
	//50/30/60/70/52/19/18/16/10
	BST tree;
	tree.insert(50);
	tree.insert(30);
	tree.insert(60);
	tree.insert(70);
	tree.insert(52);
	tree.insert(19);
	tree.insert(18);
	tree.insert(16);
	tree.insert(10);
	cout << "display the array conteints\n";
	    tree.preorder(tree.root);
		cout << "\n......................\n";
		tree.postorder(tree.root);
		cout << "\n......................\n";
		tree.inorder(tree.root);
		cout << "\n......................\n";

}