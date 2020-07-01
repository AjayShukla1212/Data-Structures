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
    return length(head->next)+1;
  }
}

//Iterative Reverse

int IONR(Node *head,int n,int l)
{
  if(head==NULL)
  {
    return -1;
  }
  if(head->data == n)
  {
    return l-length(head);
  }
  else{
   int small_ans = IONR(head->next,n,l);

  }
}
int IndexOfNRecursive(Node *head,int n){
  int l = length(head);
  return IONR(head,n,l);
}


int main()
{
  cout <<"Enter Your Input : ";
  Node *head = takeinput();
  int n;
  cout <<"Enter The Number You Want To Search For : ";
  cin >>n;
  cout <<"The Index Of Element Is : ";
  cout << IndexOfNRecursive(head,n);
}
