#include<iostream>
#include<queue>
using namespace std;

int buyTicket(int *a,int n,int k){
  queue<int> q;
  int time = 1;
  priority_queue<int> pq;
  for(int i=0;i<n;i++){
    q.push(a[i]);
    pq.push(a[i]);
  }
  int yourqueue = a[k];
  int yourindex = k;
  while(q.front()!=yourqueue && pq.top()!=yourqueue){
    if(q.front()<pq.top()){
      int temp = q.front();
      q.pop();
      q.push(temp);
    }
    else{
      pq.pop();
      q.pop();
      time++;
    }
  }

  return time;
}

int main(){
  int n,k;
  cin >>n;
  int *a = new int[n];
  for(int i=0;i<n;i++){
    cin>>a[i];
  }
  cin >>k;
  cout <<buyTicket(a,n,k)<<endl;
}
