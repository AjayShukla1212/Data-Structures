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
	node *p1 = NULL;
	node *c1 = head;
	node *p2 = NULL;
    node *c2 = head;

    node* temp = head; //for moving ahead
    node* prev = NULL;
    int pos = 0; //for checking if we are at i or j
    while(temp != NULL)
    {
        if(pos == i) {
            p1 = prev;
            c1 = temp;
        }
        else if(pos == j) {
            p2 = prev;
            c2 = temp;
        }

        prev = temp;
        temp = temp->next;
        pos++;
    }

    if(p1 != NULL) {
        p1->next = c2;
    }
    else
        head = c2;

    if(p2 != NULL) {
        p2->next = c1;
    }
    else
        head = c1;

    node* t = c2->next;
    c2->next = c1->next;
    c1->next = t;

    return head;


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
