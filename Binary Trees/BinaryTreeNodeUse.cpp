#include<iostream>
using namespace std;
#include "Binary Tree Class.h"

void print(BTN<int>* root){
  if(root==NULL)
  {
    return ;
  }
  cout <<root->data<<":";
  if(root->left!=NULL){
    cout <<"L"<<root->left->data;
  }
  if(root->right!=NULL){
    cout <<"R"<<root->right->data;
  }

  cout <<endl;
  print(root->left);
  print(root->right);
}

BTN<int>* takeInput(){
  int rootdata;
  cout <<"Enter The Data : ";
  cin >>rootdata;
  if(rootdata==-1)
  {
    return 0;
  }
  BTN<int>* root = new BTN<int> (rootdata);
  BTN<int>* leftchild = takeInput();
  BTN<int>* rightchild = takeInput();
  root->left = leftchild;
  root->right = rightchild;
  return root;
}

int main()
{/*
  BTN<int>* root = new BTN<int> (1);
  BTN<int>* n1 = new BTN<int> (2);
  BTN<int>* n2 = new BTN<int> (3);
  root->left = n1;
  root->right = n2;
*/
  BTN<int>* root = takeInput();
  print(root);
}
