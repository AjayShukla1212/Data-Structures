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
};

using namespace std;

BinaryTreeNode<int>* BST(int *input,int n,int si,int ei){
  if(n==0)
  {
    return NULL;
  }
  int mid = (ei+si+1)/2;
  BinaryTreeNode<int>* root = new BinaryTreeNode<int> (input[mid]);
  BinaryTreeNode<int>* left = BST(input,mid-si,si,mid-1);
  BinaryTreeNode<int>* right = BST(input,ei-si,mid+1,ei);
  root->left = left;
  root->right = right;
  return root;
}

BinaryTreeNode<int>* constructTree(int *input,int n)
{
  return BST(input,n,0,n-1);
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

void preOrder(BinaryTreeNode<int>* root) {
    if(root == NULL) {
        return;
    }
    cout << root -> data << " ";
    preOrder(root -> left);
    preOrder(root -> right);
}

int main() {
    int size;
    cout <<"Enter The Size Of Array : ";
    cin>>size;
    cout <<"Enter The Elements Of The Array : ";
    int *input=new int[1+size];

    for(int i=0;i<size;i++)
        cin>>input[i];

    BinaryTreeNode<int>* root = constructTree(input, size);
    cout <<"Here's The BST : ";
    preOrder(root);

}
