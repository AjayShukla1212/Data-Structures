#include<iostream>
using namespace std;
#include"QueueUsingArray.h"

int main()
{
  QueueUsingArrays<int> q;
  q.enqueue(10);
  q.enqueue(20);
  q.enqueue(30);
  q.enqueue(40);
  q.enqueue(50);
  q.enqueue(60);
  q.enqueue(70);
  cout <<q.getSize()<<endl;
  cout<<q.dequeue()<<endl;
  cout<<q.dequeue()<<endl;
  cout <<q.front()<<endl;
  cout <<q.getSize()<<endl;
  cout <<q.isEmpty()<<endl;
  cout<<q.dequeue()<<endl;
  cout<<q.dequeue()<<endl;
  cout<<q.dequeue()<<endl;
  cout <<q.front()<<endl;
  cout <<q.getSize()<<endl;
  cout <<q.isEmpty()<<endl;
  cout<<q.dequeue()<<endl;
  cout<<q.dequeue()<<endl;
}
