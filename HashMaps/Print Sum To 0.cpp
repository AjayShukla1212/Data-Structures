/*
Code : Pair Sum to 0

Given a random integer array A of size N. Find and print the pair of elements in the array which sum to 0.
Array A can contain duplicate elements.
While printing a pair, print the smaller element first.
That is, if a valid pair is (6, -6) print "-6 6". There is no constraint that out of 5 pairs which have to be printed in 1st line. You can print pairs in any order, just be careful about the order of elements in a pair.

Input format :
Line 1 : Integer N (Array size)
Line 2 : Array elements (separated by space)

Output format :
Line 1 : Pair 1 elements (separated by space)
Line 2 : Pair 2 elements (separated by space)
Line 3 : and so on

Constraints :
0 <= N <= 10^4

Sample Input:
5
2 1 -2 2 3

Sample Output :
-2 2
-2 2
*/

#include <bits/stdc++.h>
using namespace std;

#include<unordered_map>
void pairSum(int *a, int n)
{
    //Write your code here
    unordered_map <int,int> ourmap;
    for(int i=0;i<n;i++){
        if(ourmap.count(a[i])>0){
            ourmap[a[i]]++;
        }
        else{
            ourmap[a[i]] = 1;
        }
    }
	for(int i=0;i<n;i++){
        if(a[i]==0){
            for(int j=0;j<ourmap[a[i]];i++){
                cout<<"0 0"<<endl;
            }
            ourmap[a[i]] = 0;
            ourmap.erase(a[i]);
        }
        else if(ourmap.count(-a[i])>0){
			for(int j=0;j<ourmap[a[i]]*ourmap[-a[i]];j++){
                cout <<min(a[i],-a[i])<<" "<<max(-a[i],a[i])<<endl;
            }
            ourmap[a[i]] = 0;
            ourmap[-a[i]] = 0;
            ourmap.erase(a[i]);
            ourmap.erase(-a[i]);
        }
    }

}


int main()
{
  cout <<"Enter The Size Of Array : ";
	int n;
	cin >> n;
	int *arr = new int[n];
  cout <<"Elements Are : ";
	for (int i = 0; i < n; ++i)
	{
		cin >> arr[i];
	}
  cout <<"Pair Sum Are : "<<endl;
	pairSum(arr, n);

	delete[] arr;

	return 0;
}
