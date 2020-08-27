#include<iostream>
using namespace std;

int fibo_3(int n)
{
  int *ans = new int [n+1];
  ans[0] = 0;
  ans[1] = 1;
  for(int i=2;i<n+1;i++){
    ans[i] = ans[i-1] + ans[i-2];
  }
  return ans[n];
}


//Memoization
int fibo_helper(int n,int *ans){
  if(n<=1){
    return n;
  }

  if(ans[n]!=-1){
    return ans[n];
  }

  int a = fibo_helper(n-1,ans);
  int b = fibo_helper(n-2,ans);

  ans[n] = a+b;
  return ans[n];
}

int fibo(int n){
  int *ans = new int [n+1];
  for(int i=0;i<n+1;i++){
    ans[i] = -1;
  }
  return fibo_helper(n,ans);
}

int main(){
  int n;
  cout <<"Enter The Number : ";
  cin >>n;
  cout <<"The "<<n <<"th fibonacci number is : "<<fibo_3(n)<<endl;
}
