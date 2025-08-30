#include <bits/stdc++.h>
#define ll long long 
using namespace std;
const int N = 1005;
int g[N][N];
ll dp[N][N], f[N][N];
struct Node{
    int x, y, id;
};
ll read(){
	ll x = 0, f = 1;
	char ch = getchar();
	while(ch > '9' || ch < '0'){
		if(ch == '-')f = -1;
		ch = getchar();
	}
	while(ch >= '0' && ch <= '9'){
		x = (x << 3) + (x << 1) + ch - 48;
		ch = getchar(); 
	}
	return x * f;
}
void write(ll x){
	if(x < 0){
		x = -x;
		putchar('-');
	} 
	if(x < 10){
		putchar(x + 48);
		return;
	}
	else{
		write(x / 10);
		putchar(x % 10 + 48);
	}
}
int main(){
	freopen("glyph.in", "r", stdin);
	freopen("glyph.out", "w", stdout);
    int n, q;
    n = read(), q = read();
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            g[i][j] = read();
        }
    }
   
    
    for(int i = 1; i <= q; i++){
        int sx, sy, tx, ty;
        sx = read(), tx = read(), sy = read(), ty = read();
        memset(dp, 0x3f, sizeof(dp));
        dp[sx][sy] = g[sx][sy];
        for(int j = sx ; j <= tx; j++){
            for(int k = sy; k <= ty; k++){
                if(j == sx && k == sy)continue;
                dp[j][k] = min(dp[j - 1][k], dp[j][k - 1]) + g[j][k];
            }
        }
        // for(int j = sx; j <= tx; j++){
        //     for(int k = sy; k <= ty; k++){
        //         cout << dp[j][k] << ' ';
        //     }
        //     cout << endl;
        // }
        write(dp[tx][ty]);
        puts("");
    }
    return 0;
}
