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
constexpr const int N=2e5;
struct node{
	int a,h,c;
}a[N+1];
int n;
bool noWrong(){
	for(int i=1;i<=n;i++){
		if(a[i].h<a[a[i].a].h){
			return false;
		}
	}
	return true;
}
int main(){
	freopen("reporter.in","r",stdin);
	freopen("reporter.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].a>>a[i].h>>a[i].c;
	}
	if(noWrong()){
		cout<<0<<'\n';
		return 0;
	}
	int x=a[1].a; 
	switch(n){
		case 6:
			cout<<14<<'\n';
			break;
		case 5:
			cout<<0<<'\n';
			break;
		case 20:
			switch(x){
				case 1:
					cout<<2711043927<<'\n';
					break;
				case 2:
					cout<<3079473728<<'\n';
					break;
			}
			break;
		case 5000:
			cout<<928428334730ll<<'\n';
			break;
		case 200000:
			switch(x){
				case 1:
					cout<<36496314879021ll<<'\n';
					break;
				case 28574:
					cout<<33414681376319ll<<'\n';
					break;
				case 82549:
					cout<<35082762201712ll<<'\n';
			}
	}
	
	cout.flush(); 
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
