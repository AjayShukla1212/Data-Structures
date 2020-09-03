#include<iostream>
using namespace std;
#include<string>

int lcs_brute(string s,string t){
  //Base case
  if(s.size()==0 || t.size()==0){
    return 0;
  }

  if(s[0]==t[0]){
    return 1 + lcs_brute(s.substr(1),t.substr(1));
  }
  else{
    //Recursive Calls
    int a = lcs_brute(s.substr(1),t);
    int b = lcs_brute(s,t.substr(1));
    int ans = max(a,b);
    return ans;
  }
}

//Memoization
int helper(string s,string t, int **output){
  int m = s.size();
  int n = t.size();

  if(m==0 || n==0){
    return 0;
  }
  int ans;
  if(s[0]==t[0]){
    ans =  1 + helper(s.substr(1),t.substr(1),output);
  }

  else{
    int a = helper(s.substr(1),t,output);
    int b = helper(s.substr(1),t.substr(1),output);
    int c = helper(s,t.substr(1),output);
    ans = max(a,max(b,c));
  }
  output[m][n] = ans;
  return ans;
}

int lcs_memo(string s,string t){
  int m = s.size();
  int n = t.size();
  int **output = new int*[m+1];
  for(int i=0;i<m+1;i++){
    output[i] = new int[n+1];
  }
  return helper(s,t,output);
}

int main(){
  string s,t;
  cin>>s>>t;
  cout<<"Longest Subsequence (in Brute Force Method) is : "<<lcs_brute(s,t)<<endl;
  cout<<"Longest Subsequence (in Memoization Method) is : "<<lcs_memo(s,t)<<endl;
}
