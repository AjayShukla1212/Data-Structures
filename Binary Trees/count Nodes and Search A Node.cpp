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

void print(BTN<int>* root){
  if(root==NULL){
    return ;
  }
  queue<BTN<int>*> pendingNode;
  pendingNode.push(root);
  while(!pendingNode.empty())
  {
    BTN<int>* front = pendingNode.front();
    pendingNode.pop();
    cout <<front->data <<": ";
    if(front->left!=NULL)
    {
      cout <<"L"<<front->left->data;
      pendingNode.push(front->left);
    }
    if(front->right!=NULL)
    {
      cout <<" R"<<front->right->data;
      pendingNode.push(front->right);
    }
    cout<<endl;
  }
}
 /* Counting Nodes */
 int count(BTN<int>* root)
 {
   if(root==NULL)
   {
     return 0;
   }
   return 1 + count(root->left) + count(root->right);
 }

bool isNodePresent(BTN<int>* root, int x){
  if(root==NULL)
  {
    return false;
  }
  if(root->data==x)
  {
    return true;
  }
  if(root->left!=NULL){
    bool ans1 = isNodePresent(root->left,x);
    if(ans1==true)
    {
      return true;
    }
  }
  if(root->right!=NULL){
    bool ans2 = isNodePresent(root->left,x);
    if(ans2==true)
    {
      return true;
    }
  }

}


int main(){
    BTN<int>* root = takeInput();
    print(root);
    cout <<"The Number Of Nodes Present In Tree : "<<count(root)<<endl;
    int n;
    cout <<"Enter The Element YOu want To Search : ";
    cin >>n;
    cout <<isNodePresent(root,n);
    delete root;
}
