#include<iostream>
using namespace std;
#include "Tree_class.h"
#include<queue>
using namespace std;

TreeNode<int>* TakeInput()
{
  int rootData;
  cout <<"Enter The Root Data ";
  cin >>rootData;
  TreeNode<int>* root = new TreeNode<int> (rootData);
  queue<TreeNode<int>*> pendingNodes;
  pendingNodes.push(root);
  while(!pendingNodes.empty())
  {
    TreeNode<int>* front = pendingNodes.front();
    pendingNodes.pop();
    int numChild;
    cout <<"Enter The No.of Children of "<<front->data<<endl;
    cin >>numChild;
    for(int i=0;i<numChild;i++)
    {             //Enter The Child Data
      int childData;
      cout <<"Enter The "<<i<<"th child of "<<front->data<<endl;
      cin >>childData;
      TreeNode<int>* child = new TreeNode<int> (childData);
      front->children.push_back(child);
      pendingNodes.push(child);
    }
  }
  return root;
}

void printTreeLevelWise(TreeNode<int>* root)
{
  queue<TreeNode<int>*> pendingNodes;
pendingNodes.push(root);
while(!pendingNodes.empty())
{
  TreeNode<int>* front = pendingNodes.front();
  pendingNodes.pop();
  cout <<front->data<<":";


  for(int i=0;i<front->children.size();i++)
  {
    if(i==front->children.size()-1){
  cout<<front->children[i]->data;
    }

else{
       cout<<front->children[i]->data<<",";
    }
    pendingNodes.push(front->children[i]);
  }
  cout <<endl;
}

}

int NumNodes(TreeNode<int>* root)
{
  int ans = 1;
  for(int i=0;i<root->children.size();i++)
  {
    ans += NumNodes(root->children[i]);
  }
  return ans;
}

int main()
{
  TreeNode<int> *root = TakeInput();

  printTreeLevelWise(root);
  cout <<"Enter The Number Of Nodes : ";
  cout <<NumNodes(root);
}
