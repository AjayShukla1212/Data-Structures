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

int length(Node *head)
{
  if(head==NULL)
  {
    return 0;
  }
  else{
    return length(head->next) + 1;
  }
}

Node* bubble_sort(Node *head){

  int len = length(head);
  for(int i=0;i<len-1;i++){
    Node *prev = NULL;
    Node *curr = head;
    Node *next = head->next;

    while(next!=NULL)
    {
      if(curr->data > next->data)
      {
        if(prev==NULL)
        {
          curr->next = next->next;
          next->next = curr;
          prev = next;
          next = curr ->next;
          head = prev;
        }
        else{
          prev->next = curr->next;
          curr->next = next->next;
          next->next = curr;
          prev = next;
          next = curr->next;
        }
      }
      else{
        if(prev==NULL)
        {
          prev = curr;
          head = prev;
        }
        else{
          prev = curr;
        }
        curr = curr->next;
        next = next->next;
      }
    }
  }
  return head;
}

int main()
{
  cout <<"Enter The Numbers To Sort : ";
  Node *head = takeinput();
  head = bubble_sort(head);
  cout <<"After Using Bubble Sort : ";
  print(head);
}
