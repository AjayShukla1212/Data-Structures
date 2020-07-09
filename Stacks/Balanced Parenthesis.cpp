#include<iostream>
#include<stack>
using namespace std;

bool balanced_paranthesis(char *exp)
{
  stack<char> s1;
  for(int i=0;exp[i]!='\0';i++)
  {
    if(exp[i]=='{' || exp[i]=='(' || exp[i]=='[')
    {
      s1.push(exp[i]);

    }
    if(exp[i]=='}' && s1.top()=='{')
    {
      s1.pop();
    }

    if(exp[i]==']' && s1.top()=='[')
    {
      s1.pop();
    }
    if(exp[i]==')' && s1.top()=='(')
    {
      s1.pop();
    }
  }
  return s1.size()==0;

}

int main()
{
  int n;
  cout <<"Enter The Length Of Balanced Parenthesis : ";
  cin >>n;
  char exp[100];
  cout <<"Enter The Expression : ";
  for(int i=0;i<n;i++)
  {
    cin >>exp[i];
  }
  cout <<"Balanced Pranthesis : ";
  if(balanced_paranthesis(exp)==0)
  {
    cout <<"false";
  }
  else{
    cout <<"true";
  }
}
