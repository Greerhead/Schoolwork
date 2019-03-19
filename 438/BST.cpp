#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <algorithm>

using namespace std;

class BinarySearchTree{
private:


    struct node{
        string key;
        node* left;
        node* right;
        int dupe;
     };//end struct

    node* root;
//create a determine if the new leaf needs to be added to the left or right and create it.
    void newLeaf(string key, node* ptr){

        if (root == NULL){
            root = createLeaf(key);
            currentNode++;

        }//end if
        else if(key == ptr->key){
            dupe[currentNode]++;
            cout << "The key " << key <<  " key has been added already " << dupe[currentNode]<< " time(s)" << endl;
        }//end duplicate node case
        else if (key < ptr->key){
            if (ptr->left !=NULL){
                newLeaf(key, ptr->left);
            }//end if
            else{
                ptr->left = createLeaf(key);
                currentNode++;
            }//end else
        }//end left node case
        else if (key > ptr->key){
            if (ptr->right !=NULL){
                newLeaf(key, ptr->right);
            }//end if
            else{
                ptr->right = createLeaf(key);
                currentNode++;
            }//end else
        }//end right node case
        else{
            cout << "The key " << key << " already exists in the tree" << endl;
        }//end else
    }//end newLeaf
    void print(node* ptr){
        if (root !=NULL){
            if (ptr->left != NULL){
                print(ptr->left);
            }//end print left
            txtfile.setf(ios::left);
            txtfile.width(10);
            txtfile<< ptr->key << " "<< dupe[printNode] << printNode << endl;
            printNode++;
            if (ptr->right != NULL){
                print(ptr->right);
            }//end print right
        }
        else{
            txtfile << "The tree is Null" << endl;
        }//end else
    }//end print
public:
    int dupe[30] = {0};
    ofstream txtfile;
    int currentNode = 0;
    int printNode = 0;
    BinarySearchTree(){
        root = NULL;
    }//end init bst

    node* createLeaf(string key){
        node* n = new node;
        n->key = key;
        n->left = NULL;
        n->right = NULL;

        return n;
    }
    void newLeafGet(string key){
        newLeaf(key, root);
    }//end new leaf getter

    void printGet(){
        txtfile.open("output.txt", ios::app);
        print(root);
        txtfile.close();
    }//end print getter
};//end class def

int main(){
    string input;
    ifstream inputFile;
    inputFile.open("input.txt");

    string tree[30] = {};
    char punc[3] = { ',', '.', '#' };
    for (int k = 0; k < 30; k++){
        inputFile >> input;
        if (input.length() >= 10){
            input.erase(10);
        }
        for (int i = 0; i < 3; i++)
		{
			input.erase(remove(input.begin(), input.end(), punc[i]), input.end());
		}
		tree[k] = input;
    }
    inputFile.close();
    BinarySearchTree T;

    for (int i = 0; i < 30; i++)
	{
		if (tree[i] != "")
			{
			 T.newLeafGet(tree[i]);
			}//end if
	}//end for
	T.printGet();
	return 0;
}//end main
