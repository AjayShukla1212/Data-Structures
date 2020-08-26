
#include <iostream>
using namespace std;
#include<queue>
#include <cstdlib>
void findMedian(int a[], int n){
    /* Don't write main().
     * Don't read input, it is passed as function argument.
     * Print output as specified in the question.
     */
    priority_queue<int> maxheap;
	priority_queue<int, vector<int>, greater<int>> minheap;
    maxheap.push(a[0]);
    cout <<a[0]<<endl;
    for(int i=1;i<n;i++){
        //Special Case Only


        if(minheap.empty()){
            maxheap.push(a[i]);
            int temp = maxheap.top();
            maxheap.pop();
            minheap.push(temp);
        }
        else if(a[i]>maxheap.top()){
            minheap.push(a[i]);
        }
        else if(a[i]<maxheap.top()){
            maxheap.push(a[i]);
        }

        int diff = maxheap.size()-minheap.size();
        if(abs(diff)>1){
            if(maxheap.size()>minheap.size()){
                int temp = maxheap.top();
                maxheap.pop();
                minheap.push(temp);
            }
            else{
                int temp = minheap.top();
                minheap.pop();
                maxheap.push(temp);
            }
        }
        if((i+1)%2==0){
            cout <<(maxheap.top()+minheap.top())/2<<endl;
        }
           else{
               if(maxheap.size()>minheap.size()){
                cout <<maxheap.top()<<endl;
            }
            else{
                cout <<minheap.top()<<endl;
            }
           }

    }
}






int main() {

    int n;
    cin >> n;

    int arr[n], i;
    for(i=0;i<n;i++) cin >> arr[i];

    findMedian(arr, n);
}
