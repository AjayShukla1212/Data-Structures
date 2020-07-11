/*
Code : Balanced Parenthesis

Given a string expression, check if brackets present in the expression are
 balanced or not. Brackets are balanced if the bracket which opens last, closes
first.You need to return true if it is balanced, false otherwise.

Note: This problem was asked in initial rounds in Facebook

Sample Input 1 :
{ a + [ b+ (c + d)] + (e + f) }

Sample Output 1 :
true

Sample Input 2 :
{ a + [ b - c } ]

Sample Output 2 :
false
*/


#include<iostream>
#include<stack>
using namespace std;

bool checkBalanced(char *exp) {
	// Write your code here
	stack<char> s1;
  for(int i=0;exp[i]!='\0';i++)
  {
    if(exp[i]=='{' || exp[i]=='(' || exp[i]=='[')
    {
      s1.push(exp[i]);

    }

    if(s1.size()!=0)
    {
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
  if(checkBalanced(exp)==0)
  {
    cout <<"false";
  }
  else{
    cout <<"true";
  }
}
