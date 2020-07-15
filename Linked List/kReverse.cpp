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

Node* kReverse(Node *head,int n)
{
  int count=0;
  Node *prev = NULL;
  Node *curr = head;
  Node *next = head->next;
  while(curr!=NULL && count<n)
  {
    next = curr->next;
    curr->next = prev;
    prev = curr;
    curr = next;
    count++;
  }
  if(next!=NULL)
  {
    head->next = kReverse(next,n);
  }
  return prev;
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
  int i;
  cout <<"Enter the Numbers upto reverse : ";
  cin >>i;
  cout <<"After k reverse";
  head = kReverse(head,i);
  print(head);
}
