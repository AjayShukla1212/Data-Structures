#include<iostream>
#include<vector>
using namespace std;

#include<queue>
int kthLargest(vector<int> a, int n, int k){
  priority_queue<int> pq;
  for(int i=0;i<n;i++){
    pq.push(a[i]);
  }

  for(int i=1;i<k;i++){
    pq.pop();
  }
  return pq.top();
}

int main(){
  int n,k,s;
  vector<int> arr;
  cin >>n;
  for(int i=0;i<n;i++){
    cin >>s;
    arr.push_back(s);
  }
  cin >>k;
  cout <<kthLargest(arr, n, k)<<endl;
}
