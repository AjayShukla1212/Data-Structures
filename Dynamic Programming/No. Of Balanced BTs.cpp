#include <iostream>
using namespace std;
#include <cmath>

#include <bits/stdc++.h>
#define mod 1000000007
using namespace std;

int balancedBTs(int h) {
    // Write your code here

    vector <long long> dp(h+1);

    dp[1]=1;
    dp[2]=3;

    if(h==1 || h==2)
        return dp[h];

    for(int i=3;i<=h;i++){
        dp[i]=((dp[i-1]%mod)*(dp[i-1]%mod))%mod+(2*(dp[i-2]%mod)*(dp[i-1]%mod))%mod;
    }
    return dp[h];

}
/*
#include<cmath>
int balancedBTs(int h) {
  /* Don't write main().
     Don't read input, it is passed as function argument.
     Return the output and don’t print it.

    if(h<=1){
        return 1;
    }

    int mod = (int)(pow(10,9))+7;
    int x = balancedBTs(h-1);
    int y = balancedBTs(h-2);

    int temp1 = (int)(((long)(x)*x)%mod);
    int temp2 = (int)(((long)(x)*y*2)%mod);

    int ans = (int)(temp1 + temp2)%mod;

    return ans;
}
*/

int main() {
    int h;
    cin >> h;
    int ans = balancedBTs(h);
    cout << ans << endl;
}
