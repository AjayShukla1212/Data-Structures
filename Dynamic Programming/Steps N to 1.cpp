#include<iostream>
using namespace std;
#include<climits>

//Brute Force Approach
int steps(int n){

  if(n<=1){
    return 0;
  }
  int x = INT_MAX;
  int y = INT_MAX;
  int z = steps(n-1);
    if(n%3==0){
      x = steps(n/3);
    }
    else if(n%2==0){
      y = steps(n/2);
    }
    return min(x,min(y,z))+1;
}


//Memoization Appraoch
int helper(int n,int *ans){
    if(n<=1){
        return 0;
    }
    int x;
    if(ans[n-1]!=-1){
        x = ans[n-1];
    }
    else{
        x = helper(n-1,ans);
    }
    int y = INT_MAX;
    int z = INT_MAX;
    if(n%3==0){
        if(ans[n/3]!=-1){
            y = ans[n/3];
        }
        else{

            y =  helper(n/3,ans);
        }
    }
    if(n%2==0){
        if(ans[n/2]!=-1){
            z = ans[n/2];
        }
        else{
            z = helper(n/2,ans);
        }
    }
    ans[n] = min(x,min(y,z))+1;
    return ans[n];
}


int countStepsToOne(int n)
{
    int *ans = new int[n+1];
    for(int i=0;i<n+1;i++){
    	ans[i] = -1;
    }
	//Write your code here
    return helper(n,ans);
}


//Dynamic Programming Appraoach
int countStepsToOne_2(int n)
{
    int *ans = new int[n+1];
    ans[1] = 0;
    for(int i=2;i<n+1;++i){
 		int x = ans[i-1];

        int y = INT_MAX;
        int z = INT_MAX;

        if(i%2==0){
            y = ans[i/2];
        }

        if(i%3==0){
            z = ans[i/3];
        }

        ans[i] = 1 + min(x, min(y, z));
    }
    int result = ans[n];
    delete[] ans;
    return result;
}




//////////////////////////////////////////////////////////////////////////////
int main(){
  int n;
  cout <<"Enter The Number : ";
  cin >> n;
  cout <<"The Number Of Steps Required Are : "<<steps(n)<<endl;
}
