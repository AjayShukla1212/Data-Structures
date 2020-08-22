/*
Pairs with difference K

You are given with an array of integers and an integer K. Write a program to find and print all pairs which have difference K.
Take difference as absolute.

Input Format :
Line 1 : Integer n, Size of array
Line 2 : Array elements (separated by space)
Line 3 : K

Output format :
Print pairs in different lines (pair elements separated by space). In a pair, smaller element should be printed first.
(Order of different pairs is not important)

Constraints :
0 <= n <= 10^4

Sample Input 1 :
4
5 1 2 4
3

Sample Output 1 :
2 5
1 4

Sample Input 2 :
4
4 4 4 4
0

Sample Output 2 :
4 4
4 4
4 4
4 4
4 4
4 4

*/



#include<iostream>
using namespace std;

#include<unordered_map>
void printPairs(int *a, int n, int d) {
	// Write your code here
	unordered_map<int,int> m;
    for(int i=0;i<n;i++){
        if(m.count(a[i])>0){
            m[a[i]]++;
        }
        else{
            m[a[i]] = 1;
        }
    }
    for(int i=0;i<n;i++){

        if(d==0){
            int key = m[a[i]];
            int count = (key-1)*key/2;
            for(int i=0;i<count;i++){
                cout <<key<< " "<<key<<endl;
            }
        }
        else{
            int b = a[i] + d;
            int c = a[i] - d;
            int count = m[a[i]];
            int count1 = m[b];
            int count2 = m[c];
            for(int j=0;j<(count1*count);j++){
                cout <<min(a[i],b)<<" "<<max(a[i],b)<<endl;
            }
            for(int j=0;j<(count2*count);j++){
                cout <<min(a[i],c)<<" "<<max(a[i],c)<<endl;
            }
        }
        m.erase(a[i]);
    }

}




int main() {
	int n;
	cin >> n;
	int *input = new int[n];
	for(int i = 0; i < n; i++){
		cin >> input[i];
	}
	int k;
	cin >> k;
	printPairs(input, n, k);
}
