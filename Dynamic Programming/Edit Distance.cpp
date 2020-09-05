/*
Code : Edit Distance (Memoization and DP)


Given two strings s and t of lengths m and n respectively, find the Edit Distance between the strings. Edit Distance of two strings is minimum number of steps required to make one string equal to other. In order to do so you can perform following three operations only :
1. Delete a character

2. Replace a character with another one

3. Insert a character

Note - Strings don't contain spaces

Input Format :
Line 1 : String s
Line 2 : String t

Output Format :
Line 1 : Edit Distance value

Constraints
1<= m,n <= 20

Sample Input 1 :
abc
dc

Sample Output 1 :
2
*/

#include<iostream>
#include<string>
using namespace std;
/*

////////////////////////////////////////////////////
//Brute Force Method

int editDistance(string s1, string s2){}

	//Base Case
    int x,y,z;
    if(s1.size() ==0 ||s2.size()==0){
        return max(s1.size(),s2.size());
    }

    //If 1st chars matches
    if(s1[0] == s2[0]){
        return editDistance(s1.substr(1),s2.substr(1));
    }

    //Recursive calls
    else{
        x = editDistance(s1.substr(1),s2) + 1; //Insert
        y = editDistance(s1,s2.substr(1)) + 1; //Delete
        z = editDistance(s1.substr(1),s2.substr(1)) + 1;  //Replace
    }
    return min(x,min(y,z));

}




//////////////////////////////////////////////////////////////
//Memoization


int editD_memo(string s,string t,int **output){
    int m = s.size();
    int n = t.size();
    //Base Case
    if(m==0 || n==0){
        return max(m,n);
    }
    if(output[m][n]!=-1){
        return output[m][n];
    }
    //Compare 1st Char
    int ans;
    if(s[0] == t[0]){
        ans = editD_memo(s.substr(1),t.substr(1),output);
    }
    else{
        int x = editD_memo(s.substr(1),t,output) + 1; //Insert
        int y = editD_memo(s,t.substr(1),output) + 1; //Delete
        int z = editD_memo(s.substr(1),t.substr(1),output) + 1;  //Replace
    	ans = min(x,min(y,z));
    }
    output[m][n] = ans;
    return output[m][n];
}



int editDistance(string s1, string s2){
    int m = s1.size();
    int n = s2.size();
	int  **output = new int*[m+1];
 	for(int i=0;i<=m;i++){
        output[i] = new int[n+1];
    }
    for(int i=0;i<=m;i++){
        for(int j=0;j<=n;j++){
            output[i][j] = -1;
        }
    }
    return editD_memo(s1,s2,output);
}*/

/////////////////////////////////////////////////////////////////////////////
//Dynamic Programming


int editDistance(string s,string t){
	int m = s.size();
    int n = t.size();
	int  **output = new int*[m+1];
 	for(int i=0;i<=m;i++){
        output[i] = new int[n+1];
    }

    //Fill The 1st Row And Columns
    for(int i=0;i<=m;i++){
        output[i][0] = i;
    }
    for(int j=1;j<=n;j++){
        output[0][j] = j;
    }

    //Fill The Left One's As Per Their Dependencies
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            if(s[m-i]==t[n-j]){
                output[i][j] = output[i-1][j-1];
            }
            else{
                int x = output[i-1][j] + 1;
                int y = output[i-1][j-1] + 1;
            	int z = output[i][j-1] + 1;
             	output[i][j] = min(x,min(y,z));
            }
        }
    }
    return output[m][n];
}

int main(){

  string s1;
  string s2;

  cin >> s1;
  cin >> s2;

  cout << editDistance(s1,s2) << endl;

}
