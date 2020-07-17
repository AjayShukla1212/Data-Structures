#include<iostream>
#include "vector"
using namespace std;

template<typename T>
class TreeNode{
public:
  T data;
  vector<TreeNode*> children;
  TreeNode(T data)
  {
    this->data = data;
  }
};

void print(TreeNode<int>* root)
{
  if(root==NULL){   //Corner Case
    return ;
  }
  cout <<root->data <<":";
  for(int i=0;i<root->children.size();i++)
  {
    cout << root->children[i]->data<<",";
  }
  cout <<endl;
  for(int i=0;i<root->children.size();i++)
  {
    print(root->children[i]);
  }
}
TreeNode<int>* TakeInput()
{
  int rootData;
  cout <<"Enter The Data"<<endl;
  cin >>rootData;
  TreeNode<int>* root = new TreeNode<int> (rootData);
  int n;
  cout <<"Enter The No of children of "<<rootData<<endl;
  cin >>n;
  for(int i=0;i<n;i++)
  {
    TreeNode<int>* child = TakeInput();
    root->children.push_back(child);
  }

  return root;
}

int main()
{
  TreeNode<int>* root = TakeInput();
  print(root);
}
