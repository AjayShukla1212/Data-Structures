#include<iostream>
using namespace std;


bool checkMaxHeap(int *a,int n){
    for(int i=0;i<n;i++){
      int LCI = 2*i+1;
      int RCI = 2*i+2;
      if(LCI<n){
        if(a[LCI]>a[i]){
          return false;
        }
      }
      if(RCI<n){
        if(a[RCI]>a[i]){
          return false;
        }
      }
    }
    return true;
}

int main(){
  int n;
  cin >>n;
  int *arr = new int[n];
  for(int i=0;i<n;i++){
    cin >>arr[i];
  }
  bool ans = checkMaxHeap(arr,n);
  if(ans){
    cout <<"True"<<endl;
  }
  else{
    cout <<"False"<<endl;
  }
  delete [] arr;
}
