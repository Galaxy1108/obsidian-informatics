#include<bits/stdc++.h>
#define int __int128
using namespace std;
inline int read() {
	int x = 0;
	char c = getchar();
	bool f = 0;
	while(!isdigit(c)) f = f | (c == '-'), c = getchar();
	while(isdigit(c)) x = (x * 10) + (c ^ 48), c = getchar();
	return f ? -x : x;    
}
inline void write(int x){
    if(x<0){putchar('-');x=-x;}
    if(x>9)write(x/10);
    putchar(x%10+'0');
}
inline void writeln(int x){write(x); puts("");}
inline void writepl(int x){write(x); putchar(' ');}
const int maxn = 16, maxS = (1 << 16) + 7;
int n, m;
int K[maxn], Answer, Lcm[maxS], Cnt[maxS];
inline int Ex_gcd(int a, int b, int &x, int &y)
{
	if(!b) { x = 1, y = 0; return a; }
	int g = Ex_gcd(b, a % b, x, y);
    int t = x; x = y, y = t - a / b * y;
    return g;
}
signed main(){

    freopen("so.in", "r", stdin);
    freopen("so.out", "w", stdout);
    
    n = read(), m = read();
    for(register int i = 1; i <= m; ++i) K[i] = read();
    sort(K + 1, K + m + 1); m = unique(K + 1, K + m + 1) - K - 1;
    K[++m] = n;
    for(register int i = 1; i <= m; ++i) Lcm[1 << (i - 1)] = K[i];
    Lcm[0] = 1;
    for(register int i = 1; i < (1 << m); ++i) {
        Cnt[i] = Cnt[i >> 1] + (i & 1);
        int A = Lcm[i & (i - 1)], B = Lcm[i & (-i)], g = __gcd(A, B);
        int cnt = A / g * B;
        if(A > n || B > n || cnt > n) Lcm[i] = n + 1;
        else Lcm[i] = cnt;
    }
    Answer = 0;
    for(register int i = 1; i < (1 << m); ++i) {
        int A = Lcm[i], s = ((1 << m) - 1) ^ i;
        if(A > n) continue;
        for(register int j = s; j; j = s & (j - 1)) {
            int B = Lcm[j];
            if(B >= n) continue;
            int x, y, g = Ex_gcd(A, B, x, y), C = A / g * B;
            if(g > 1) continue;
            x = (x % B + B) % B;
            Answer += ((Cnt[i] + Cnt[j]) & 1 ? - 1 : 1) * (n / C + (n % C >= A * x));
        }
    }
    write(Answer);
	return 0;
}