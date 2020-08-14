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
#include <vector>

vector<int>* findPath(BinaryTreeNode<int>* root,int data)
{
  if(root==NULL)
  {
    return NULL;
  }
  if(root->data==data)
  {
    vector<int>* output = new vector<int> ();
    output->push_back(root->data);
    return output;
  }
  if(root->data > data)
  {
    vector<int>* left = findPath(root->left,data);
    if(left!=NULL)
    {
      left->push_back(root->data);
      return left;
    }
    else{
      return NULL;
    }
  }
  if(root->data < data)
  {
    vector<int>* right = findPath(root->right,data);
    if(right!=NULL)
    {
      right->push_back(root->data);
      return right;
    }
    else{
      return NULL;
    }
  }
}

BinaryTreeNode<int>* takeInput() {
    int rootData;
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
        cin >> leftChild;
        if(leftChild != -1) {
            BinaryTreeNode<int>* leftNode = new BinaryTreeNode<int>(leftChild);
            currentNode -> left =leftNode;
            q.push(leftNode);
        }
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
    int k;
    cin >> k;
    vector<int> *output = findPath(root, k);
    if(output != NULL) {
        for(int i = 0; i < output -> size(); i++) {
            cout << output -> at(i) << endl;
        }
    }
    delete root;
}
