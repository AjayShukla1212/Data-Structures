#include<iostream>
#include<queue>
#include<stack>
template<typename T>
class node{
public:
  T data;
  node<T> *next;
  node(T data){
    this->data = data;
    this->next = NULL;
  }
};

template<typename T>
class  BinaryTreeNode{
public:
  T data;
  BinaryTreeNode<T> *left;
  BinaryTreeNode<T> *right;
  BinaryTreeNode(T data){
    this ->data = data;
    left = NULL;
    right = NULL;
  }
};

using namespace std;

// void zigZagOrder(BinaryTreeNode<int>* root){
//   stack<BinaryTreeNode<int>*> s1;                    //s1 = R->L
//   stack<BinaryTreeNode<int>*> s2;                    //s2 = L->R
//   s1.push(root);
//   LOOP: while(!s1.empty()){
//     BinaryTreeNode<int> *front = s1.top();
//     s1.pop();
//     cout <<front->data<<" ";
//     if(front->left!=NULL){
//       s2.push(front->left);
//     }
//     if(front->right!=NULL){
//       s2.push(front->right);
//     }
//
//   }
//   cout <<endl;
//   while(!s2.empty())
//   {
//     BinaryTreeNode<int> *curr = s2.top();
//     s1.pop();
//     cout <<curr->data<<" ";
//     if(curr->right!=NULL){
//       s1.push(curr->right);
//     }
//     if(curr->left!=NULL){
//       s1.push(curr->left);
//     }
//   }
//   cout <<endl;
//     if(!s1.empty()){
//       goto LOOP;
//     }
// }

void zigZagOrder(BinaryTreeNode<int>* root){
  if(!root){
    return;
  }
    stack<BinaryTreeNode<int>*> currlevel;
    stack<BinaryTreeNode<int>*> nextlevel;
    bool LtoR = true;
    currlevel.push(root);
    while(!currlevel.empty())
    {
      BinaryTreeNode<int> *front = currlevel.top();
      currlevel.pop();
      if(front!=NULL)
      {
        cout <<front->data <<" ";

        if(LtoR)
        {
          if(front->left!=NULL)
          {
            nextlevel.push(front->left);
          }
          if(front->right!=NULL)
          {
            nextlevel.push(front->right);
          }

        }
        else
        {
          if(front->right!=NULL){
            nextlevel.push(front->right);
          }
          if(front->left!=NULL){
            nextlevel.push(front->left);
          }
        }
      }
      if(currlevel.empty())
      {
        LtoR = !LtoR;
        swap(currlevel,nextlevel);
        cout <<endl;
      }
    }
}



BinaryTreeNode<int> *takeInput(){
  int rootdata;
  cin >>rootdata;
  if(rootdata==-1)
  {
    return NULL;
  }
  BinaryTreeNode<int> *root = new BinaryTreeNode<int> (rootdata);
  queue<BinaryTreeNode<int>*> q;
  q.push(root);
  while(!q.empty())
  {
    BinaryTreeNode<int> *curr = q.front();
    q.pop();
    int leftChild, rightChild;
    //cout << "Enter left child of " << currentNode -> data << " : ";
    cin >> leftChild;
    if(leftChild != -1) {
        BinaryTreeNode<int>* leftNode = new BinaryTreeNode<int>(leftChild);
        curr -> left =leftNode;
        q.push(leftNode);
    }
    //cout << "Enter right child of " << currentNode -> data << " : ";
    cin >> rightChild;
    if(rightChild != -1) {
        BinaryTreeNode<int>* rightNode = new BinaryTreeNode<int>(rightChild);
        curr -> right =rightNode;
        q.push(rightNode);
    }
}
return root;
}


int main() {
BinaryTreeNode<int>* root = takeInput();
zigZagOrder(root);
}
