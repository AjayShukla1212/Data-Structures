#include<iostream>
#include<queue>
using namespace std;
#include"Binary Tree Class.h"

BTN<int>* takeInput()
{
  int rootdata;
  cout <<"Enter The Data "<<endl;
  cin >>rootdata;
  if(rootdata==-1){
    return 0;
  }
  BTN<int>* root = new BTN<int> (rootdata);
  queue<BTN<int>*> pendingNode;
  pendingNode.push(root);


  while(!pendingNode.empty())
  {
    BTN<int>* front = pendingNode.front();
    pendingNode.pop();

    int leftchildData;
    cout <<"Enter The Left Child of " <<front->data<<endl;
    cin >>leftchildData;
    if(leftchildData!=-1)
    {
      BTN<int>* child = new BTN<int> (leftchildData);
      front->left = child;
      pendingNode.push(child);
    }
    int rightchildData;
    cout <<"Enter The Right Child "<<front->data<<endl;
    cin >>rightchildData;
    if(rightchildData!=-1)
    {
      BTN<int>* child = new BTN<int> (rightchildData);
      front->right = child;
      pendingNode.push(child);
    }
  }

  return root;
}

/*

print your tree like this : left:->root:->right

*/

void inorder(BTN<int>* root){
  if(root==NULL){
    return ;
  }
  inorder(root->left);
  cout <<root->data<<" ";
  inorder(root->right);
}

int main(){
    BTN<int>* root = takeInput();
    inorder(root);
    delete root;
}
