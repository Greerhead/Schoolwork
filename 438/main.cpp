#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>
#include <iomanip>
#include <stdio.h>
#include <algorithm>
#include <array>

using namespace std;

class BST
{
private:

	

	struct node
	{
		string key;
		node* left;
		node* right;
		int duplicates;

	};

	node* root;

	void newLeafPrivate(string key, node* Ptr)
	{
		if (root == NULL)
		{
			root = createLeaf(key);
			currentNode++;
		}
		else if (key == Ptr->key)
		{
			duplicates[currentNode]++;
			cout << "This key " << key << " has been added already " << duplicates[currentNode] << " times!" << endl;
			
		}
		else if (key < Ptr->key)
		{
			if (Ptr->left != NULL)
			{
				newLeafPrivate(key, Ptr->left);
			}
			else
			{
				Ptr->left = createLeaf(key);
				currentNode++;
			}
		}
		else if (key > Ptr->key)
		{
			if (Ptr->right != NULL)
			{
				newLeafPrivate(key, Ptr->right);
			}
			else
			{
				Ptr->right = createLeaf(key);
				currentNode++;
			}
		}
		else
		{
			cout << "The key " << key << " has already been added to the tree\n";
		}
	}

	void printPrivate(node* Ptr)
	{
		
		if (root != NULL)
		{
			if (Ptr->left != NULL)
			{
				printPrivate(Ptr->left);
			}
			txtfile.setf(ios::left);
			txtfile.width(10);
			txtfile << Ptr->key << " " << duplicates[printNode] << printNode << endl;
			printNode++;
			if (Ptr->right != NULL)
			{
				printPrivate(Ptr->right);
			}
		}
		else
		{
			txtfile << "The tree is empty" << endl;
		}
		
	}


public:
	int duplicates[30];
	ofstream txtfile;
	int currentNode=0;
	int printNode = 0;
	BST()
	{
		
		root = NULL;

		for(int i = 0; i < 30; i++)
			{
				duplicates[i] = 0;
			}
	}
	
	
	
	node* createLeaf(string key)
	{
		node* n = new node;
		n->key = key;
		n->left = NULL;
		n->right = NULL;

		return n;
	}

	void newLeaf(string key)
	{
		newLeafPrivate(key, root);
	}


	void print()
	{
		txtfile.open("output.txt", ios::app);
		printPrivate(root);
		txtfile.close();
	}
};

int main()
{
	string input;
	ifstream inputFile;
	inputFile.open("input.txt");

	string tree[30] = {};
	char punc[3] = { ',', '.', '#' };
	for (int k = 0; k < 30; k++)
	{
		inputFile >> input;
		if (input.length() >= 10)
		{
			input.erase(10);
		}
		for (int i = 0; i < 3; i++)
		{
			input.erase(remove(input.begin(), input.end(), punc[i]), input.end());
		}
		tree[k] = input;
	}

	inputFile.close();
	BST myTree;

	for (int i = 0; i < 30; i++)
	{
		if (tree[i] != "")
			{
			 myTree.newLeaf(tree[i]);
			}
	}

	myTree.print();
	system("pause");
	return 0;
}