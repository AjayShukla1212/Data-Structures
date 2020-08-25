#include<iostream>
using namespace std;
#include<queue>
void KSortedArray(int input[],int n,int k){
  priority_queue<int> pq;
  for(int i=0;i<k;i++){
    pq.push(input[i]);
  }
  int j=0;
  for(int i=k;i<n;i++){
    input[j] = pq.top();
    pq.pop();
    pq.push(input[i]);
    j++;
  }
  while(!pq.empty()){
    input[j] = pq.top();
    pq.pop();
    j++;
  }
}


int main(){
  int a[] = {10,15,6,4,5};
  KSortedArray(a,5,3);
  for(int i=0;i<5;i++){
    cout <<a[i]<<" ";
  }
}
