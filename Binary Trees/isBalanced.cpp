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

class balance{
public:
  int height;
  bool isBalance;
};

balance* HeightIsBalanced(BTN<int>* root)
{
  if(root==NULL)
  {
    balance *ans = new balance();
    ans ->height = 0;
    ans ->isBalance = true;
    return ans;
  }
  balance *leftAns = HeightIsBalanced(root->left);
  balance *rightAns = HeightIsBalanced(root->right);
  bool flag;
  if(!leftAns->isBalance || !rightAns->isBalance || abs(leftAns->height - rightAns->height)>1)
  {
    flag = false;
  }
  else{
    flag = true;
  }
  balance *output = new balance();
  output->height = 1 + max(leftAns->height,rightAns->height);
  output->isBalance = flag;
  return output;
}


bool isBalanced(BTN<int>* root)
{
  balance *finalAns = HeightIsBalanced(root);
  return finalAns->isBalance ;
}


int main(){
    BTN<int>* root = takeInput();
    print(root);
    cout <<"The Tree isBalanced is : "<<isBalanced(root);
    delete root;
}
