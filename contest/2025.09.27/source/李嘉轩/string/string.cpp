#include<bits/stdc++.h>
using namespace std;
int n;
bool check(string s){
	for(int i = 1; i < n; i++)if(s[i] == s[i - 1])return false;
	return true;
}
int dist(string a, string b){
	int p, res = 0;
	char tmp;
	for(int i = n - 1; i >= 1; i--){
		for(int j = 0; j <= i; j++)if(a[j] == b[i])p = j;
		res += i - p;
		tmp = a[p];
		for(int j = p; j < i; j++)a[j] = a[j + 1];
		a[i] = tmp;
	}
	return res;
}
int main(){
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	int c0 = 0, c1 = 0, c2 = 0, ans, pl = 0;
	string s, s2;
	cin >> s;
	n = s.size();
	for(int i = 0; i < n; i++){
		if(s[i] == '0')c0++;
		else if(s[i] == '1')c1++;
		else if(s[i] == '2')c2++;
	}
	if(max({c0, c1, c2}) > ((n + 1) >> 1) || (n > 12 && c0 <= (n >> 1))){
		cout << -1;
		return 0;
	}
	if(n <= 12){
		ans = 0x7f7f7f7f;
		s2 = s;
		sort(s2.begin(), s2.end());
		do{if(check(s2))ans = min(ans, dist(s, s2));}while(next_permutation(s2.begin(), s2.end()));
	}else{
		ans = 0;
		for(int i = 0; i < n; i++){
			if(s[i] == '0'){
				ans += i - pl;
				pl += 2;
			}
		}
	}
	cout << ans << "\n";
	return 0;
}
