#include<iostream>
using namespace std;

template<typename s>
class Node{
public:
  s data;
  Node<s> *next;
  Node(s data)
  {
    this->data = data;
    next = NULL;
  }
};

template<typename t>
class stack{

Node<t> *head;
int size;
public:
stack()
{
  head = NULL;
  size = 0;
}

int getsize()
{
  return size;
}

bool isempty(){
  return size==0;
}

void push(t element){
  Node<t> *newNode = new Node<t>(element);
    newNode->next = head;
    head = newNode;
  size++;
}
t top(){
  if(size==0)
  {
    return 0;
  }
  return head->data;
}

t pop(){
  if(size==0)
  {
    return 0;
  }
  t ans = head->data;
  Node<t> *temp = head;
  head = head->next;
  delete temp;
  size--;
  return ans;
}
};


int main()
{
  stack<int> s;
  cout <<"Enter The Elements For Stacks : ";
  s.push(10);
  s.push(20);
  s.push(30);
  s.push(40);
  cout <<"Current Length "<<s.getsize()<<endl;
  cout <<"Current Top "<<s.top()<<endl;
  s.push(50);
  cout <<"Current Top "<<s.top()<<endl;
  // cout <<"Current Length "<<s.getsize()<<endl;
  cout <<s.pop()<<endl;
  cout <<s.pop()<<endl;
  // cout <<s.pop()<<endl;
  // cout <<"Current Length "<<s.getsize()<<endl;
  cout <<s.isempty()<<endl;

}
