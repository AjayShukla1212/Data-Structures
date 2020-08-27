
  #include<iostream>
  using namespace std;


  //Brute Force Approach
/*
  long staircase(int n){
    if(n==0 || n==1){
      return 1;
    }
    if(n==2){
      return 2;
    }
    long x = staircase(n-1);
    long y = staircase(n-2);
    long z = staircase(n-3);
    long ans = x + y + z;
    return ans;

  }
*/
/*

//Memoization Approach

  long staircase(int n,long *ans){
    if(n==1 || n==0){
      ans[n] = 1;
      return ans[n];
    }
    if(n==2){
      ans[n] = 2;
      return ans[n];
    }
    if(ans[n-1]==-1){
      ans[n-1] = staircase(n-1,ans);
    }
    if(ans[n-2]==-1){
      ans[n-2] = staircase(n-2,ans);
    }
    if(ans[n-3]==-1){
      ans[n-3] = staircase(n-3,ans);
    }
    ans[n] = ans[n-1] + ans[n-2] + ans[n-3];
    return ans[n];

  }

  long staircase(int n){
    long *ans = new long[n+1];
    for(int i=0;i<n+1;i++){
      ans[i] = -1;
    }
    return staircase(n,ans);
  }

*/

//DP Appraoach
long staircase(int n){
  long *ans = new long[n+1];
  ans[0] = 1;
  ans[1] = 1;
  ans[2] = 2;
  for(int i=3;i<n+1;i++){
    ans[i] = ans[i-1] + ans[i-2] + ans[i-3];
  }
  return ans[n];
}




///////////////////////////////////////////////////////////////////////////////
  int main(){
    int n;
    cout <<"Enter The number of Steps : ";
    cin >>n;
    cout <<"The Number Of Ways To Run Up The Stairs Hopping 1/2/3 steps are : "<<staircase(n);
  }
