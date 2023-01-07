#include<iostream>
#include<bits/stdc++.h>
#include <vector>

using namespace std;

//finocci series using dp and recursion
//creating a function
int f(int n  , vector<int> &dp) {
	//base case
	if(n <= 1 ) {
		return n ;
	}
	if(dp[n] != -1 ) return dp[n];
	//return f(n+1) + f(n-2);
	return dp[n] = f(n-1 , dp) + f(n-2 , dp); 
}





int main() {

	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	int n;
	cout<<n;

	//declaring the vector

	vector<int> dp(n+1 , -1);
	cout << f(n , dp);
	return 0;





}
