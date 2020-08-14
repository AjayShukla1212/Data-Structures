#include<iostream>
#include<queue>
#include<vector>

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

vector<node<int> *> createLLForEachLevel(BinaryTreeNode<int> *root){
  vector<node<int> *> vect;
  if(root==NULL)
  {
    return vect;
  }
  node<int> *head = NULL;
  node<int> *tail = NULL;
  queue<BinaryTreeNode<int>*> q;
  q.push(root);
  q.push(NULL);
  while(!q.empty()){
    BinaryTreeNode<int> *front = q.front();
    q.pop();
    if(front==NULL){
      if(q.empty()){
        break;
      }
      vect.push_back(head);
      head=NULL;
      tail = NULL;
      q.push(NULL);
      continue;
    }
    else{
      node<int> *temp = new node<int> (front->data);
      if(head==NULL){
        head = temp;
        tail = head;
      }
      else{
        tail->next = temp;
        tail = temp;
      }
    }
    if(front->left!=NULL){
      q.push(front->left);
    }
    if(front->right!=NULL){
      q.push(front->right);
    }
  }
  return vect;
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

void print(node<int> *head){
  node<int> *temp = head;
  while(temp!=NULL){
    cout <<temp->data <<" ";
    temp = temp->next;
  }
  cout <<endl;
}

int main() {
BinaryTreeNode<int>* root = takeInput();
vector<node<int>*> ans = createLLForEachLevel(root);
for(int i=0;i<ans.size;i++)
  {
    print(ans[i]);
  }
}
