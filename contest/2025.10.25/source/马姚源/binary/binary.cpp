#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int a[N], p[N];
void read(int &x){
	int f = 1;
	x = 0;
	char ch= getchar();
	while(ch < '0' || ch > '9'){
		if(ch == '-')f = -1;
		ch = getchar();
	}
	while(ch >= '0' && ch <= '9'){
		x = (x << 3) + (x << 1) + ch - 48;
		ch = getchar();
	}
	x *= f;
}
void write(int x){
	if(x < 0)x = -x, putchar('-');
	if(x < 10){
		putchar(x + 48);
		return;
	}
	write(x / 10);
	putchar(x % 10 + 48); 
}
int main(){
	freopen("binary.in", "r", stdin);
	freopen("binary.out", "w", stdout);
	int n, m;
	read(n);
	for(int i = 1; i <= n; i++){
		read(a[i]);
		p[i] = p[i - 1] + a[i];
	}
	int q;
	read(q);
	while(q--){
		int op;
		read(op);
		if(op == 1){
			int id;
			read(id);
			a[id] = (a[id] == 0) ? 1 : 0;
			for(int i = 1; i <= n; i++){
				p[i] = p[i - 1] + a[i];
			}
		}
		else{
			int ql, qr;
			read(ql), read(qr);
			int ans = 0;
			for(int i = ql; i <= qr; i++){
				for(int j = i; j <= qr; j++){
					int cnt1 = p[j] - p[i - 1];
					if(cnt1 & 1){
						if(j - i + 1 - cnt1 >= 2 && cnt1 > 1)ans++;// cout << 2214123;
					}
					else{
						ans++;
//						cout << "138718930";
					}
					
				}
			}
			write(ans), putchar('\n');
		}
		
		
	}
	return 0;
}
