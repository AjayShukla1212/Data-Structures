#include<iostream>
using namespace std;

class Node{
public:
  int data;
  Node *next;

  Node(int data)
  {
    this->data = data;
    next =NULL;
  }
};


Node* takeinput()
{
  Node *head = NULL, *tail = NULL;
  int data;
  cin >>data;
  while(data!=-1)
  {
    Node *newNode = new Node(data);
    if(head==NULL)
    {
      head = newNode;
      tail = newNode;
    }
    else
    {
      tail->next = newNode;
      tail = newNode;
    }
    cin >>data;
  }
  return head;
}

Node* skipMdeleteN(Node *head,int m,int n){
  Node *t1 = head;
  Node *t2 = NULL;

  while(t1!=NULL && t1->next!= NULL)
  {
    int c1 = 1,c2 = 0;
    while(c1!=m && t1!=NULL)
    {
      t1 = t1->next;
      c1++;
    }
    t2 = t1->next;
    while(c2!= n && t2!= NULL){
      t2 = t2->next;
      c2++;
    }
    t1->next = t2;
    t1 = t2;
  }
  return head;
}

void print(Node *head)
{
  Node *temp = head;
    while(temp!=NULL)
    {
      cout <<temp->data<<" ";
      temp = temp->next;
    }
}



int main()
{
  cout <<"Enter Your Input : ";
  Node *head = takeinput();
  int i,j;
  cout <<"Enter the Numbers to skip and Numbers to delete : ";
  cin >>i >>j;
  cout <<"After Skipping And Deleting ";
  head = skipMdeleteN(head,i,j);
  print(head);
}
