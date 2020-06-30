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

//Creating A Pair Class For Head For Tracking Head And Tail

class Pair{
public:
    Node *head = NULL;
    Node *tail = NULL;
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

Pair reverse2_ll(Node *head)
{
  if(head==NULL ||head->next==NULL)
  {
    Pair ans;
    ans.head = head;
    ans.tail = head;
    return ans;
  }
  Pair small_ans = reverse2_ll(head->next);
  small_ans.tail->next = head;
  head->next = NULL;
  Pair Ans;
  Ans.head = small_ans.head;
  Ans.tail = head;
  return Ans;
}

Node* ReverseLL_Better(Node *head)
{
  return reverse2_ll(head).head;
}

int main()
{
  Node *head = takeinput();
  head = ReverseLL_Better(head);
  print(head);
}
