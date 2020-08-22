/*
Longest subset zero sum

Given an array consisting of positive and negative integers, find the length of the longest subarray whose sum is zero.
NOTE: You have to return the length of longest subarray .

Input Format :
Line 1 : Contains an integer N i.e. size of array

Line 2 : Contains N elements of the array, separated by spaces

Output Format
 Line 1 : Length of longest subarray

Constraints:
0 <= N <= 10^8

Sample Input :
10
95 -97 -387 -435 -5 -70 897 127 23 284

Sample Output :
5
*/



#include<iostream>
#include<unordered_map>
using namespace std;
int lengthOfLongestSubsetWithZeroSum(int* a, int n){
  if(n==1){
      return 1;
  }
  unordered_map<long,int> ourmap;
  int maxlength = 0;
  long sum =0;
  for(int i=0;i<n;i++){
      int length = 0;
      sum = sum + a[i];
      if(ourmap.count(sum)==0){
          ourmap[sum] = i;
      }
      else{
          length = i-ourmap[sum];
      }
      if(maxlength<=length){
          maxlength = length;
      }
  }
return maxlength;
}

using namespace std;


int main(){
  int size;

  cin >> size;
  int* arr = new int[size];
  for(int i = 0; i < size; i++){
    cin >> arr[i];
  }
  int ans = lengthOfLongestSubsetWithZeroSum(arr,size);
  cout << ans << endl;
  delete arr;
}
