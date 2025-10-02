#include<bits/stdc++.h>
using namespace std;
int n, a = 0, b = 0, fix[1000001], cnt[2][1000001], c[2][1000001];
int solve(){
	for(register int i = 1; i <= n; i++)cnt[0][i] = cnt[1][i] = 0;
	int sum = 0, last = -1, len = 0, reqa = 0, reqb = 0, sec;
	for(register int i = 1; i <= n; i++){
		if(fix[i] != -1){
			if(last == -1 || last == fix[i]){
				if(fix[i])reqa += len;
				else reqb += len;
			}else sum++;
			last = fix[i];
			len = 0;
		}else len++;
	}
	if(last == -1){
		if(a && b)return 1;
		return 0;
	}
	if(last)reqa += len;
	else reqb += len;
	if(reqa > a)sec = 1;
	else sec = 0;
	len = 0;
	last = -1;
	for(register int i = 1; i <= n; i++){
		if(fix[i] != -1){
			if(fix[i] == sec && len > 0){
				if(last == -1){
					sum++;
					cnt[1][len]++;
				}else if(last == fix[i]){
					sum += 2;
					cnt[0][len]++;
				}
			}
			last = fix[i];
			len = 0;
		}else len++;
	}
	if(last == sec && len > 0){
		sum++;
		cnt[1][len]++;
	}
	if(sec)len = a;
	else len = b;
	last = reqa = reqb = 0;
	for(register int i = 1; i <= n; i++){
		while(cnt[0][i]--){
			c[0][reqa + 1] = c[0][reqa] + i;
			reqa++;
		}
	}
	for(register int i = 1; i <= n; i++)while(cnt[1][i]--)c[1][++reqb] = i;
	last = upper_bound(c[0] + 1, c[0] + reqa + 1, len) - c[0] - 1;
	len -= c[0][last];
	sum -= (last << 1);
	if(reqb >= 2 && len >= c[1][1] + c[2][1])return sum - 2;
	else if(reqb >= 1 && len >= c[1][1])return sum - 1;
	return sum;
}
int main(){
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	int m, q, op, p, x;
	cin >> n >> m >> q;
	memset(fix, -1, sizeof(fix));
	for(int i = 1; i <= n; i++){
		cin >> x;
		if(x & 1)a++;
		else b++;
	}
	while(m--){
		cin >> p >> x;
		if(x & 1)a--;
		else b--;
		fix[p] = (x & 1);
	}
	while(q--){
		cin >> op >> p;
		if(op == 1){
			if(fix[p])a++;
			else b++;
			fix[p] = -1;
		}else{
			cin >> x;
			if(x & 1)a--;
			else b--;
			fix[p] = (x & 1);
		}
		cout << solve() << "\n";
	}
	return 0;
}
