#include<bits/stdc++.h>
using namespace std;
int s[1000001], pl[1000001], pr[1000001];
bool dis[1000001], tag[1000001];
int main(){
	freopen("gene.in", "r", stdin);
	freopen("gene.out", "w", stdout);
	int n, l, r, ans = 0x7f7f7f7f, now = 0;
	cin >> n >> l >> r;
	for(int i = 1; i <= n; i++)scanf("%d", &s[i]);
	for(int i = l; i <= r; i++)dis[s[i]] = true;
	for(int i = 1; i < l; i++){
		if(pl[s[i]])pl[s[i]] = 0x7f7f7f7f;
		else pl[s[i]] = i;
	}
	for(int i = n; i > r; i--){
		if(pr[s[i]])pr[s[i]] = 0x7f7f7f7f;
		else pr[s[i]] = i;
	}
	for(int i = 1; i <= 1000000; i++){
		if(pl[i] == 0x7f7f7f7f)pl[i] = 0;
		if(pr[i] == 0x7f7f7f7f)pr[i] = 0;
	}
	memset(tag, 1, sizeof(tag));
	for(int i = 1; i <= 1000000; i++)if(!dis[i])tag[pl[i]] = tag[pr[i]] = 0;
	for(int i = n; i > r; i--)if(!tag[i])tag[pl[s[i]]] = 1;
	for(int i = l - 1; i >= 1; i--){
		if(!tag[i]){
			now = i;
			break;
		}
	}
	for(int i = n; i > r; i--){
		if(tag[i])continue;
		if(now > pl[s[i]])ans = min(ans, i - now + 1);
		now = max(now, pl[s[i]]);
	}
	if(ans == 0x7f7f7f7f)ans = -1;
	cout << ans;
	return 0;
}
