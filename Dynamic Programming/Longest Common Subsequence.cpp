#include<iostream>
using namespace std;
#include<string>

//Brute Force Recursion
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
/////////////////////////////////////////////////////////////
//Memoization
int helper(string s,string t, int **output){
  int m = s.size();
  int n = t.size();

  if(m==0 || n==0){
    return 0;
  }

  if(output[m][n]!=-1){
    return output[m][n];
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
  for(int i=0;i<m+1;i++){
    for(int j=0;j<n+1;j++){
      output[i][j] = -1;
    }
  }

  return helper(s,t,output);
}

/////////////////////////////////////////////////////////////
//Dynamic Programming
int lcs_dp(string s,string t){
  int m = s.size();
  int n = t.size();
  int **output = new int*[m+1];
  for(int i =0;i<=m;i++){
    output[i] = new int[n+1];
  }

  //Fill 1st Column
  for(int i=0;i<=m;i++){
    output[i][0] = 0;
  }
  //Fill 1st Row
  for(int j=1;j<=n;j++){
    output[0][j] = 0;
  }

  //Fill The left
  for(int i=1;i<=m;i++){
    for(int j=1;j<=n;j++){
      if(s[m-i] = t[n-j]){
        output[i][j] = 1 + output[i-1][j-1];
      }
      else{
        int a = output[i-1][j];
        int b = output[i][j-1];
        int c = output[i-1][j-1];
        output[i][j] = max(a,max(b,c));
      }
    }
  }
  return output[m][n];
}




int main(){
  string s,t;
  cin>>s>>t;
  cout<<"Longest Subsequence (in Brute Force Method) is : "<<lcs_brute(s,t)<<endl;
  cout<<"Longest Subsequence (in Memoization Method) is : "<<lcs_memo(s,t)<<endl;
  cout<<"Longest Subsequence (using Dynamic Programming / iterative Method) is : "<<lcs_dp(s,t)<<endl;
}
