#include<iostream>
using namespace std;

// NODE CLASS

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

// TAKING INPUT

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

// PRINTING THE LINKED LIST

void print(Node *head)
{
  Node *temp = head;
    while(temp!=NULL)
    {
      cout <<temp->data<<" ";
      temp = temp->next;
    }
    cout <<endl;
}

// MERGING TWO LINKED LIST

Node* mergeTwoLLs(Node *h1, Node *h2) {
    int data;
    Node *fh = NULL;
    Node *ft = NULL;
    // putting final head And Final Tail
    if(fh==NULL)
    {
        if(h1->data > h2->data)
     {
         fh = h2;
         ft = h2;
           h2 = h2->next;
     }
     else
        {
         fh = h1;
         ft = h1;
            h1 = h1->next;
        }
    }
    while(h1!=NULL && h2!=NULL)
    {
        if(h1->data > h2->data)
     {
         ft->next = h2;
         ft = ft->next;
           h2 = h2->next;
     }
     else
        {
         ft->next = h1;
         ft = ft->next;
            h1 = h1->next;
        }
    }
    if(h2==NULL){
        ft->next = h1;
    }
 if(h1==NULL){
        ft->next = h2;
    }

    return fh;
}

// Split The LL And Find Mid

Node *mid(Node *head)
{
  Node *slow = head;
  Node *fast = head->next;
  while(fast!=NULL&&fast->next!=NULL)
  {
    slow = slow->next;
    fast = fast->next->next;
  }
  return slow;
}

// MERGE SORT

Node* merge_sort(Node *head)
{
  if(head==NULL ||head->next ==NULL)
  {
    return head;
  }

  Node *h1 = head, *h2 = NULL;
  Node *m = mid(head);
  h2 = m->next;
  m->next = NULL;
   head = mergeTwoLLs(merge_sort(h1),merge_sort(h2));
  return head;
}

int main()
{
  cout <<"Enter The Numbers To Sort : ";
  Node *head = takeinput();
  head = merge_sort(head);
  cout <<"After Sorting : ";
  print(head);
  return 0;
}
