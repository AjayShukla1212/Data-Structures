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
  Node *p = head;
  while(m!=1)
  {
    p = p->next;
    m--;
  }
  Node *c = p->next;
  while(n!=0)
  {
    c = c->next;
    n--;
  }
  p->next = c;
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
