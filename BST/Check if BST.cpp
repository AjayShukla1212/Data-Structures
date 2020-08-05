#include <iostream>
#include <queue>

template <typename T>
class BinaryTreeNode {
    public :
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;

    BinaryTreeNode(T data) {
        this -> data = data;
        left = NULL;
        right = NULL;
    }
    ~BinaryTreeNode() {
    	if(left)
       		delete left;
    	if(right)
       		delete right;
    }
};

using namespace std;

#include<climits>
int minimum(BinaryTreeNode<int>* root)
{
    if(root==NULL)
    {
        return INT_MAX;
    }
    return min(root->data,min(minimum(root->left),minimum(root->right)));
}

int maximum(BinaryTreeNode<int>* root)
{
    if(root==NULL)
    {
        return INT_MIN;
    }
    return max(root->data,max(maximum(root->left),maximum(root->right)));
}


bool isBST(BinaryTreeNode<int> *root){

    if(root==NULL)
    {
        return true;
    }

    int rightmin = minimum(root->right);
    int leftmax = maximum(root->left);
    bool ans = (root->data > leftmax) && (root->data <= rightmin) && isBST(root->left) && isBST(root->right);
    return ans;
}

BinaryTreeNode<int>* takeInput() {
    int rootData;
    //cout << "Enter root data : ";
    cin >> rootData;
    if(rootData == -1) {
        return NULL;
    }
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootData);
    queue<BinaryTreeNode<int>*> q;
    q.push(root);
    while(!q.empty()) {
        BinaryTreeNode<int> *currentNode = q.front();
	q.pop();
        int leftChild, rightChild;
        //cout << "Enter left child of " << currentNode -> data << " : ";
        cin >> leftChild;
        if(leftChild != -1) {
            BinaryTreeNode<int>* leftNode = new BinaryTreeNode<int>(leftChild);
            currentNode -> left =leftNode;
            q.push(leftNode);
        }
        //cout << "Enter right child of " << currentNode -> data << " : ";
        cin >> rightChild;
        if(rightChild != -1) {
            BinaryTreeNode<int>* rightNode = new BinaryTreeNode<int>(rightChild);
            currentNode -> right =rightNode;
            q.push(rightNode);
        }
    }
    return root;
}

int main() {
    BinaryTreeNode<int>* root = takeInput();
    if(isBST(root)) {
        cout << "true" << endl;
    }
    else {
        cout << "false" << endl;
    }
    delete root;
}
 
