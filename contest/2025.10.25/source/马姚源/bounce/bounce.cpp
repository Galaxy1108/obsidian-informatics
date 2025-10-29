#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
int deq[N], head = 1, tail = 0, stk[N], tot;
int n, q;
int book[N], book1[N], a[N];
int ans[25];
pair<int, int> ask;
void init(){
	for(int m = 2; m <= 20; m++){
		int cnt = 0, cnt2 = -1;
		for(int i = 1; i <= n; i++)deq[++tail] = i;
		int lst = 0;
		while(cnt < n){
			cnt2++;
			int sum = 0;
			if(cnt2 & 1){
				int c = 0;
				tot = 0;
				while(head <= tail){
					if(c % m == 0){
						book[deq[tail]] = 1;
						lst = deq[tail];
					}
					else stk[++tot] = deq[tail];
					tail--;
					c++; 
				}
				head = 1, tail = 0;
				for(int i = tot; i >= 1; i--)deq[++tail] = stk[i];
				if(!tot){
					ans[m] = lst;
					break;
				}
				continue;
			}
			int c = 0;
			tot = 0;
			while(head <= tail){
				if(c % m == 0){
					book[deq[head]] = 1;
					lst = deq[head];
				}
				else stk[++tot] = deq[head];
				head++;
				c++; 
			}
			head = 1, tail = 0; 
			for(int i = 1; i <= tot; i++)deq[++tail] = stk[i];
			if(!tot){
				ans[m] = lst;
				break;
			}
		}
	}
}
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
	freopen("bounce.in", "r", stdin);
	freopen("bounce.out", "w", stdout);
//	ios::sync_with_stdio(0);
//	cin.tie(0);cout.tie(0);
	read(n), read(q);
	if(n <= 1000){
		while(q--){
			int op, m;
			read(op), read(m);
			if(op == 1){
				int cnt = 0;
				for(int i = 1; i <= n; i++){
					if(i % m == 1)book[i] = 1;
				}	
			}
			if(op == 2){
				int cnt = 0;
				for(int i = 1; i <= n; i++){
					if(book[i])continue;
					if(cnt % m == 0)book[i] = 1;
					cnt++;
				}
			}
			if(op == 3){
				int cnt = 0, cnt2 = -1;
				for(int i = 1; i <= n; i++)book1[i] = book[i], a[i] = i;
				int lst = 0;
				while(cnt < n){
					cnt2++;
					int sum = 0;
					if(cnt2 & 1){
						for(int i = n; i >= 1; i --){
							if(book1[a[i]])continue;
							if(sum % m == 0){
								lst = a[i];
								book1[a[i]] = 1;
								cnt++;
								
								if(cnt == n){
									cout << lst << '\n'; 
									break;
								}
							}
							sum++;	
						}
						if(!sum){
							cout << lst << endl;
							break;
						}
						continue;
					}
					for(int i = 1; i <= n; i++){
						if(book1[a[i]])continue;
						if(sum % m == 0){
							lst = a[i];
							book1[a[i]] = 1;
							cnt++;
							if(cnt == n){
								cout << lst << '\n';
								break;
							}
						}
						sum++;
					}
					if(!sum){
						cout << lst << endl;
						break;
					}
//					cout << cnt << endl;
				}
			}
		}
	}
	
	else{
		init();
		while(q--){
			int op, m;
			read(op), read(m);
			write(ans[m]), putchar('\n');
		}	
	}
	
	return 0;
} 
