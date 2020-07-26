#include <iostream>
#include <queue>
#include<bits/stdc++.h>
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

class PairAns {
    public :
    int min;
    int max;
};

using namespace std;


PairAns minMax(BinaryTreeNode<int> *root) {
  PairAns ans;
  ans.max=INT_MIN;
  ans.min=INT_MAX;

  if(root == NULL)
     return ans;

  if(root->left==NULL&&root->right==NULL){
  ans.max=root->data;
  ans.min=root->data;
  return ans;
  }
  PairAns smallans1=minMax(root->left);
  PairAns smallans2=minMax(root->right);

  ans.max=max(max(smallans1.max,smallans2.max),root->data);
  ans.min=min(min(smallans1.min,smallans2.min),root->data);
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
    PairAns ans = minMax(root);
    cout << ans.max << " " << ans.min << endl;
}
