#include<iostream>
#include<vector>
#include<queue>
using namespace std;
template<typename T>
class BTN{
public:
  T data;
  BTN* left;
  BTN* right;
  BTN(T data){
    this->data = data;
    left = NULL;
    right = NULL;
  }
  ~BTN(){
    delete left;
    delete right;
  }
};


class BST{
  BTN<int> *root;
  public:
    BST(){
      root = NULL;
    }
    ~BST(){
      delete root;
    }
  private:
    bool hasData(BTN<int> *node,int data){
      if(node==NULL){
        return false;
      }
      if(node->data == data)
      {
        return true;
      }
      else if(node->data>data)
      {
        return hasData(node->left,data);
      }
      else{
        return hasData(node->right,data);
      }
    }

    BTN<int>* insert(BTN<int> *node,int data){
      if(node==NULL)
      {
        BTN<int> *newNode = new BTN<int> (data);
        return newNode;
      }
      if(node->data>data){
        node->left = insert(node->left,data);
      }
      else{
        node->right = insert(node->right,data);
      }
      return node;
    }
    BTN<int> *deleteData(BTN<int> *node,int data){
        if(node==NULL){
          return NULL;
        }
        if(node->data<data){
          node->right = deleteData(node->right,data);
          return node;
        }
        else if(node->data>data){
          node->left = deleteData(node->left,data);
          return node;
        }
        else{
          if(node->left==NULL && node->right==NULL)
          {
            delete node;
            return NULL;
          }
          else if(node->left==NULL){
            BTN<int> *temp = node->right;
            node->right =NULL;
            delete node;
            return temp;
          }
          else if(node->right==NULL){
            BTN<int> *temp = node->left;
            node->left =NULL;
            delete node;
            return temp;
          }
          else{
            BTN<int> *minNode = node->right;
            while(minNode!=NULL)
            {
              minNode = minNode->left;
            }
            int replace = minNode->data;
            node->data = replace;
            node->right = deleteData(node->right,replace);
            return node;
          }
        }
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

  public:
    bool hasData(int data){
      return hasData(root,data);
    }

    void insert(int data){
      this->root = insert(this->root,data);
    }

    void deleteData(int data){
      this->root = deleteData(this->root,data);
    }

    void printTree(){
      print(root);
    }

};



BTN<int>* takeInput() {
    int rootData;
    //cout << "Enter root data : ";
    cin >> rootData;
    if(rootData == -1) {
        return NULL;
    }
    BTN<int> *root = new BTN<int>(rootData);
    queue<BTN<int>*> q;
    q.push(root);
    while(!q.empty()) {
        BTN<int> *currentNode = q.front();
	q.pop();
        int leftChild, rightChild;
        //cout << "Enter left child of " << currentNode -> data << " : ";
        cin >> leftChild;
        if(leftChild != -1) {
            BTN<int>* leftNode = new BTN<int>(leftChild);
            currentNode -> left =leftNode;
            q.push(leftNode);
        }
        //cout << "Enter right child of " << currentNode -> data << " : ";
        cin >> rightChild;
        if(rightChild != -1) {
            BTN<int>* rightNode = new BTN<int>(rightChild);
            currentNode -> right =rightNode;
            q.push(rightNode);
        }
    }
    return root;
}




int main(){
    BST b;
    b.insert(8);
    b.insert(3);
    b.insert(10);
    b.insert(1);
    b.insert(6);
    b.insert(14);
    b.insert(4);
    b.insert(7);
    b.insert(13);
    b.printTree();
    cout<<b.hasData(14)<<endl;
    cout<<b.hasData(2)<<endl;
    b.deleteData(10);
    b.printTree();
}
