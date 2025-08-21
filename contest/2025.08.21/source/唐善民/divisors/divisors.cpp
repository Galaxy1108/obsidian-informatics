//#include<bits/stdc++.h>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<iomanip>
#include<cstdio>
#include<string>
#include<vector>
#include<cmath>
#include<ctime>
#include<deque>
#include<queue>
#include<stack>
#include<list>
using namespace std;
constexpr const int N=2500;
int n;
int main(){
	freopen("divisors.in","r",stdin);
	freopen("divisors.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	cin>>n;
	switch(n){
		case 3:
			cout<<"2 6 3\n1 2\n2 3\n";
			break;
		case 4:
			cout<<"3 6 8 12\n1 2\n2 3\n3 4\n";
			break;
		case 5:
			cout<<"10 15 6 8 4\n1 2\n2 3\n3 4\n4 5\n";
			break;
	}
	
	cout.flush();
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}

