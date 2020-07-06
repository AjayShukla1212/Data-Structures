/*
Delete every N nodes

Given a linked list and two integers M and N. Traverse the linked list such that you retain
M nodes then delete next N nodes, continue the same until end of the linked list. That is,
in the given linked list you need to delete N nodes after every M nodes.

Input format :

Line 1 : Linked list elements (separated by space and terminated by -1)

Line 2 : M

Line 3 : N

Sample Input 1 :
1 2 3 4 5 6 7 8 -1
2
2

Sample Output 1 :
1 2 5 6

Sample Input 2 :
1 2 3 4 5 6 7 8 -1
2
3

Sample Output 2 :
1 2 6 7
*/

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
  Node *t1 = head;
  Node *t2 = NULL;

  while(t1!=NULL && t1->next!= NULL)
  {
    int c1 = 1,c2 = 0;
    while(c1!=m && t1!=NULL)
    {
      t1 = t1->next;
      c1++;
    }
    if(t1==NULL)
      {
          return head;
      }
    t2 = t1->next;
    while(c2!= n && t2!= NULL){
      t2 = t2->next;
      c2++;
    }
    t1->next = t2;
    t1 = t2;
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
