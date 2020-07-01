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


//Iterative Reverse
Node* reverse1_ll(Node *head)
{
  Node *prev = NULL;
  Node *n = head->next;
  Node *curr = head;
  while(curr!=NULL)
  {
    n = curr->next;
    curr->next = prev;
    prev = curr;
    curr = n;
  }

  return prev;
}



int main()
{
  cout <<"Enter Your Input : ";
  Node *head = takeinput();
  cout <<"Using Iterative Approach "<<endl;
  head = reverse1_ll(head);
  cout <<"Elements After Reversal Is : ";
  print(head);
}
