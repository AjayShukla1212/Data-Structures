#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
vector<int> RemoveDuplicate(int *a,int size){
  vector<int> output;
  unordered_map<int,bool> seen;

  for(int i=0;i<size;i++){
    if(seen.count(a[i])>0){
      continue;
    }
    else{
      seen[a[i]] = true;
      output.push_back(a[i]);
    }
  }
  return output;
}
int main(){
  int a[] = {1,2,3,3,4,2,1,4,3,6,5,5,12};
  vector<int> output = RemoveDuplicate(a,13);
  cout <<"After Removing Elements : ";
  for(int i=0;i<output.size();i++)
  {
    cout <<output[i]<<" ";
  }
}
