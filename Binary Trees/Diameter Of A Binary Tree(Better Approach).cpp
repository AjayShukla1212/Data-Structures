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

pair<int,int> heightDiameter(BTN<int>* root)
{
  if(root==NULL)
  {
    pair<int,int> p;
    p.first = 0;
    p.second = 0;
    return p;
  }
  pair<int,int> leftAns = heightDiameter(root->left);
  pair<int,int> rightAns = heightDiameter(root->right);
  int lh = leftAns.first;
  int rh = rightAns.first;
  int ld = leftAns.second;
  int rd = rightAns.second;
  int height = 1 + max(lh,rh);
  int diameter = max(lh+rh,max(ld,rd));

  pair<int,int> p;
  p.first = height;
  p.second = diameter;
  return p;
}

int Diameter(BTN<int>* root)
{
    pair<int,int> Ans = heightDiameter(root);
    return Ans.second;
}


int main(){
    BTN<int>* root = takeInput();
    print(root);
    cout <<"Diameter of A Binary Tree Is : "<<Diameter(root);
    delete root;
}
