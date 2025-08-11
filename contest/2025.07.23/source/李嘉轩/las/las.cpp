//O(rand)ÉñÃØ´úÂë
#include<bits/stdc++.h>
using namespace std;
int c[1000001], cnt[1000001], nxt[1000001], ans[1000001];
int main(){
	clock_t st, nd;
	st = clock();
	freopen("las.in", "r", stdin);
	freopen("las.out", "w", stdout);
	int n;
	bool h;
	cin >> n;
	for(int i = 1; i <= n; i++){
		scanf("%d", &c[i]);
		cnt[i] = 1;
		ans[i] = i;
		if(i < n)nxt[i] = i + 1;
		else nxt[i] = 1;
	}
	while(1){
		h = true;
		for(int i = 1; i <= n; i++){
			if(ans[i] == i){
				if(c[i] * (cnt[nxt[i]] + 1) < c[i + 1] * cnt[i]){
					cnt[i]--;
					cnt[nxt[i]]++;
					ans[i] = nxt[i];
					h = false;
				}
			}else if(c[nxt[i]] * (cnt[i] + 1) < c[i] * cnt[nxt[i]]){
				cnt[nxt[i]]--;
				cnt[i]++;
				ans[i] = i;
				h = false;
			}
		}
		if(h)break;
		nd = clock();
		if(nd - st >= 1900){
			cout << "NIE";
			return 0;
		}
	}
	for(int i = 1; i <= n; i++)cout << ans[i] << " ";
	return 0;
}
