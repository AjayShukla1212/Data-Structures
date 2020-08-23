/*
Longest Consecutive Sequence

You are given an array of unique integers that contain numbers in random order. Write a program to find the longest possible sequence of consecutive numbers using the numbers from given array.
You need to return the output array which contains consecutive elements. Order of elements in the output is not important.
Best solution takes O(n) time.
If two sequences are of equal length then return the sequence starting with the number whose occurrence is earlier in the array.

Input Format :
Line 1 : Integer n, Size of array
Line 2 : Array elements (separated by space)

Constraints :
0 <= n <= 10^8

Sample Input 1 :
13
2 12 9 16 10 5 3 20 25 11 1 8 6

Sample Output 1 :
8
9
10
11
12

Sample Input 2 :
7
3 7 2 1 9 8 41

Sample Output 2 :
7
8
9

Explanation: Sequence should be of consecutive numbers. Here we have 2 sequences with same length i.e. [1, 2, 3] and [7, 8, 9], but output should be [7, 8, 9] because the starting point of [7, 8, 9] comes first in input array.

Sample Input 3 :
7
15 24 23 12 19 11 16

Sample Output 3 :
15
16
*/

#include<iostream>
using namespace std;
#include <vector>
using namespace std;
#include<unordered_map>

#include <vector>
#include<bits/stdc++.h>
using namespace std;
#include<unordered_map>
vector<int> longestConsecutiveIncreasingSequence(int *a, int n){
	//Your Code goes here
    vector<int > output;
    unordered_map<int,bool> ourmap;
    for(int i=0;i<n;i++){
        ourmap[a[i]] = true;
    }
    unordered_map<int,int> m;
    for(int i=0;i<n;i++){

        if(m.count(a[i])==0)
        m[a[i]] = i;
    }

   /*
  for(int i=0;i<n;i++){
        cout<<a[i]<<" "<<m[a[i]]<<endl;
    }*/

    int start ;
    int maxlength = 0;
    for(int i=0;i<n;i++){
        int length = 0;
        int temp2 = a[i];
        if(ourmap[a[i]]==false){
            continue;
        }
        while(ourmap[temp2]!=false){
            ourmap[temp2] = false;
            length++;
            temp2++;
        }
        int temp = a[i]-1;
        while(ourmap[temp]!=false)
        {
            ourmap[temp] = false;
        	length++;
            temp--;
        }
        temp++;
        if(maxlength==length){
            if(m[start]>m[temp]){
                start = temp;
            }
        }
        if(maxlength<length){
          	maxlength = length;
            // if(a[i]-temp>1){
            //     start = temp;
            // }
            // else{
            //     start = a[i];
            // }
             start = temp;
        }

    }
    for(int i=0;i<maxlength;i++){
        output.push_back(start);
        start++;
    }
    return output;
}
int main(){
  int size;

  cin >> size;
  int* arr = new int[size];
  for(int i = 0; i < size; i++){
    cin >> arr[i];
  }
  vector<int> ans = longestConsecutiveIncreasingSequence(arr,size);

  for (auto it = ans.cbegin(); it != ans.cend(); it++) {
	cout << *it <<endl;
  }

  delete arr;
}
