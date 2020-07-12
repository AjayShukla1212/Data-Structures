#include<iostream>
#include<stack>
#include<queue>
using namespace std;

void reverseQueue(queue<int> &q)
{
  queue<int> q2;
  while(!q.empty())
  {
    q2.push(q.front());
    q.pop();
  }
  q = q2;
}

int main()
{
  queue<int> q;
  int size;
  cin >> size;

  int val;
  for(int i=0;i<size;i++)
  {
    cin >> val;
    q.push(val);
  }
  reverseQueue(q);
  while(!q.empty())
  {
    cout <<q.front() <<" ";
    q.pop();
  }
}
