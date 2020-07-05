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

Node* arrange_LinkedList(Node* head)
{
  if(head==NULL || head->next ==NULL)
  {
    return head;
  }
  Node *oddH = NULL, *oddT = NULL;
  Node *evenH = NULL, *evenT = NULL;
  while(head!=NULL)
  {
    if(head->data%2!=0)
    {
      if(oddH==NULL)
      {
        oddH = head;
        oddT = head;
      }
      else{
        oddT->next = head;
        oddT = oddT->next;
      }
    }
    else{
      if(evenH==NULL)
      {
        evenH =head;
        evenT = head;
      }
      else{
        evenT->next = head;
        evenT = evenT->next;
      }
    }
    head = head->next;
  }

  if(oddH == NULL){
    evenT->next = NULL;
    return evenH;
  }
  else{
    evenT->next = NULL;
    oddT->next = evenH;
    return oddH;
  }
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
  cout <<"After Separating The Numbers : ";
  head = arrange_LinkedList(head);
  print(head);
}
