#include<queue>
#include<iostream>
using namespace std;
#include"Tree_class.h"

TreeNode<int>* TakeInput(){
  int rootData;
  cout <<"Enter The Root Data : ";
  cin >>rootData;
  TreeNode<int>* root = new TreeNode<int> (rootData);
  queue<TreeNode<int>*> pendingNode;
  pendingNode.push(root);
  while(!pendingNode.empty())
  {
    TreeNode<int>* front = pendingNode.front();
    pendingNode.pop();
    int numChild;
    cout <<"Enter The Number Of Children Of "<<front->data<<endl;
    cin >>numChild;
    for(int i=0;i<numChild;i++)
    {
      int childData;
      cout <<"Enter The "<<i<<"Th Child Of "<<front->data<<endl;
      cin >>childData;
      TreeNode<int>* child = new TreeNode<int> (childData);
      front->children.push_back(child);
      pendingNode.push(child);
    }
  }
  return root;
}
void print(TreeNode<int>* root)
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

int numLeafNodes(TreeNode<int>* root) {

    int num =0;
    if(root->children.size()==0)
    {
        return 1;
    }
    else{
            for(int i=0;i<root->children.size();i++)
            {
				int ans = numLeafNodes(root->children[i]);
                num = num+ans;
            }
    }

    return num;
}


int main()
{
  TreeNode<int>* root  = TakeInput();
  print(root);
  cout <<"The Number Of Leaves in The Tree is : "<<numLeafNodes(root);
}
