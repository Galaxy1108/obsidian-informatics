#include <bits/stdc++.h>
using namespace std;
int gcd(int a, int b){
	return (b) ? gcd(b, a % b) : a;
}
int lcm(int a, int b){
	return a / gcd(a, b) * b;
}
int vis[1005];
int fa, fb;
vector<int> A, B;
void dfs(int id, int a, int b){
//	if(b > fb)return;
	if(a == fa && b == fb){
		cout << id << endl;
		for(int i = 0; i < A.size(); i++)cout << A[i] << ' ';
		exit(0);
//		return;
	}
//	cout << a << " " << b << endl;
	for(int i = 2; i <= 1000; i++){
		if(vis[i])continue;
		vis[i] = 1;
		int tb = lcm(b, i);
		int ta = (tb / b) * a + 1;
		A.push_back(i);
		int t = gcd(ta, tb);
		ta = ta / t, tb = tb / t;
		dfs(id + 1, ta, tb);
		A.pop_back(); 
		vis[i] = 0;
	}
}
int main(){
	freopen("math.in", "r", stdin);
	freopen("math.out", "w", stdout);
	cin >> fa >> fb;
	dfs(0, 0, 1);
	return 0;
}
