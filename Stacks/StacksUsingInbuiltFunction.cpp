#include<iostream>
#include<stack>
using namespace std;
int main()
{
  stack<char> s1;
  s1.push('a');
  s1.push('b');
  s1.push('c');
  cout <<"Current Size : ";
  cout <<s1.size()<<endl;
  cout <<"Current Size : ";
  cout <<s1.top()<<endl;
  s1.push('d');
  s1.push('e');
  s1.push('f');
  cout <<"Current Size : ";
  cout <<s1.size()<<endl;
  cout <<"Current Size : ";
  cout <<s1.top()<<endl;
  s1.pop();
  s1.pop();
  s1.pop();
  s1.pop();
  cout <<"Current Size : ";
  cout <<s1.size()<<endl;
  cout <<"Current Size : ";
  cout <<s1.top()<<endl;
  s1.pop();
  cout <<"Is Empty : "<<s1.empty()<<endl;
  s1.pop();
  cout  <<"Is Empty : "<<s1.empty()<<endl;
  s1.pop();
  cout  <<"Is Empty : "<<s1.empty()<<endl;
}
