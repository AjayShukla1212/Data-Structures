#include<iostream>
using namespace std;

#include<unordered_map>
#include<vector>
int highestFrequency(int *a, int n){
    vector<int> elements;
    unordered_map<int,int> ourmap;
      for(int i=0;i<n;i++){
          if(ourmap.count(a[i])>0){
              ourmap[a[i]]++;
          }
          else{
              ourmap[a[i]] = 1;
              elements.push_back(a[i]);
          }
      }
      int maxcount = 0;
      int maxfrequency;
      for(int i=0;i<elements.size();i++){
          if(ourmap.at(elements[i])>maxcount){
              maxcount = ourmap.at(elements[i]);
              maxfrequency = elements[i];
          }
      }
      return maxfrequency;
}



int main()
{
    int n;
    int input[100000];
    cin>>n;
    for(int i=0; i<n; i++)
    {
        cin>>input[i];
    }
    int maxKey= highestFrequency(input, n);
    cout<<"Maximum Occuring Number is : "<<maxKey;
    return 0;
}
