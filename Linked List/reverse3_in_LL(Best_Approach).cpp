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

void print(Node *head)
{
  Node *temp = head;
    while(temp!=NULL)
    {
      cout <<temp->data<<" ";
      temp = temp->next;
    }
}

Node* reverse3_best(Node *head)
{
  if(head==NULL ||head->next==NULL)
  {
    return head;
  }
  Node *small_ans = reverse3_best(head->next);
  Node *tail = head->next;
  tail->next = head;
  head->next = NULL;
  return small_ans;
}



int main()
{
  Node *head = takeinput();
  head = reverse3_best(head);
  print(head);
}
