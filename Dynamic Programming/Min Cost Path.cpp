#include <iostream>
#include <vector>
#include <climits>
using namespace std;
int helper(int **a,int m,int n,int i,int j,int **output){
    if(i>m-1 || j>n-1){
        return INT_MAX;
    }
    if(i==m-1 && j == n-1){
        return a[i][j];
    }

    if(output[i][j] != -1){
      return output[i][j];
    }

    	int x = helper(a,m,n,i+1,j,output);

        int y = helper(a,m,n,i,j+1, output);

    	int z = helper(a,m,n,i+1,j+1,output);

    int minSum = min(x,min(y,z)) + a[i][j];
    output[i][j] = minSum;
	return minSum;
}

int minCostPath(int **input, int m, int n) {
    int i=0,j=0;
    int **output = new int*[m];

    for(int i=0;i<m;i++){
      output[i] = new int[n];
    }
    for(int i=0;i<m;i++){
      for(int j=0;j<n;j++){
        output[i][j] = -1;
      }
    }
    return helper(input,m,n,i,j,output);
}

int minCostPath_dp(int **input,int m,int n){
  int **output = new int*[m];
  for(int i=0;i<m;i++){
    output[i] = new int[n];
  }

  // Fill The Destination
  output[m-1][n-1] = input[m-1][n-1];

  //Fill The Last row
  for(int j=n-2;j>=0;j--){
    output[m-1][j] = output[m-1][j+1] + input[m-1][j];
  }

  //Fill The Last column
  for(int i=m-2;i>=0;i--){
    output[i][n-1] = output[i+1][n-1] + input[i][n-1];
  }

  //Fill The left ones
  for(int i=m-2;i>=0;i--){
    for(int j=n-2;j>=0;j--){
      output[i][j] = input[i][j] + min(output[i+1][j+1],min(output[i+1][j],output[i][j+1]));
    }
  }
  return output[0][0];
}

int main() {
    int **arr,n,m;
    cin >> n >> m;
    arr = new int*[n];
    for(int i = 0; i < n; i++) {
        arr[i] = new int[m];
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> arr[i][j];
        }
    }
    cout <<"Min Cost of Path Using Memoization Process is : ";
    cout << minCostPath(arr, n, m) << endl;

    cout <<"Min Cost of Path Using Dynamic Programming is  : ";
    cout << minCostPath_dp(arr, n, m) << endl;
}
