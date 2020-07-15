/*
Minimum bracket Reversal

Given a string expression which consists only ‘}’ and ‘{‘. The expression may
not be balanced. You need to find the minimum number of bracket reversals which
are required to make the expression balanced.
Return -1 if the given expression can't be balanced.

Input Format :
String S

Output Format :
Required count

Sample Input 1 :
{{{

Sample Output 1 :
-1

Sample Input 2 :
{{{{}}

Sample Output 2 :
1
*/

#include <iostream>
using namespace std;

#include<stack>
int countBracketReversals(char input[]){
	// Write your code here
	int l =0;
    for(int i=0;input[i]!='\0';i++)
    {
        l++;
    }
    if(l%2!=0)
    {
        return -1;
    }
    stack<int> s;

    int i=0;
    while(input[i]!='\0')
    {
        if(input[i]=='{')
        {
            s.push(input[i]);
        }
        else if(input[i]=='}')
        {
            if(s.empty())
            {
            	s.push(input[i]);
            }
            else {
                if(s.top()=='{')
                {
                    s.pop();
                }
                else{
                    s.push(input[i]);
                }
            }
        }
        i++;
    }
    int count=0;
    int c1,c2;
        while(!s.empty())
        {
            c1 = s.top();
        s.pop();
        c2 = s.top();
        s.pop();
        if(c1==c2)
        {
            count++;
        }
        else
        {
            count=count+2;
        }
        }

    return count;
}


int main() {
    char input[10000];
    cin >> input;
    cout << countBracketReversals(input) << endl;
}
