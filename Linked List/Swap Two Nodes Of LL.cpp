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

Node* swapNodes(Node *head,int i,int j){
  Node *p1 = NULL, *c1 = head, *n1 = head->next;
  Node *p2 = NULL, *c2 = head, *n2 = head->next;
  while(i!=0){
    p1 = c1;
    c1 = n1;
    n1 = n1->next;
    i--;
  }
  while(j!=0)
  {
    p2 = c2;
    c2 = n2;
    n2 = n2->next;
    j--;
  }
  p2->next = c1;
  p1->next = c2;
  c1->next = n2;
  c2->next = n1;


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
  cout <<"Enter The Numbers You Want To Swap : ";
  cin >>i >>j;
  cout <<"After Swapping ";
  head = swapNodes(head,i,j);
  print(head);
}
