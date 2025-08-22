#include<bits/stdc++.h>
using namespace std;
const int MAXN=5010;
const int len = 400;
int a[MAXN][MAXN];
int bel[MAXN][MAXN];
void gen(int n,int seed){
    std::mt19937 rng(seed);
    for(int i=1;i<=n;++i){
        for(int j=1;j<=n+1;++j){
            a[i][j]=j;
            std::swap(a[i][j],a[i][rng()%j+1]);
        }
    }
}
int n, seed;
bitset<2005>nw;
int vis[5005];
bitset<2005> b[2005][(int)(2000 / len + 5)];
void run(int i){
    if(!seed){
        int L = 0, R = nw.count(), ans;
        int l = 0, r = R / len;
        while(l <= r){
            int mid = l+r>>1;
            if((b[i][mid] & nw) == b[i][mid]){
                ans = mid;
                l = mid + 1;
            }else{
                r = mid - 1;
            }
        }
        ans *= len;
        for(int j = ans + 1; ; ++j){
            if(nw[bel[i][j]] == 0){
                nw[bel[i][j]] = 1;
                return;
            }
        }
    }else{
        for(int j = 1; j <= n + 1; ++j){
            if(vis[bel[i][j]] == 0){
                vis[bel[i][j]] = 1;
                return;
            }
        }
    }
}
int read(){
    int s = 0;
    char ch = getchar();
    while(ch < '0' || ch > '9')ch = getchar();
    while('0' <= ch && ch <= '9')s = s * 10 + ch - '0', ch = getchar();
    return s;
}
char ch[1000005];
int tot;
void write(int x){
    if(x > 9)write(x / 10);
    ch[++tot] = x % 10 + '0';
}
signed main(){
    freopen("c.in", "r", stdin);
    freopen("c.out", "w", stdout);
    cin >> n >> seed;
    if(!seed){
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n + 1; j++){
                a[i][j] = read();
            }
        }
    }else{
        gen(n, seed);
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n + 1; j++){
            bel[i][a[i][j]] = j;
        }
    }
    if(!seed){
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= (n + 1) / len; j++){
                b[i][j] = b[i][j - 1];
                for(int k = (j - 1) * len + 1; k <= j * len; k++)b[i][j][bel[i][k]] = 1;
            }
        }
    }
    for(int i = 1; i <= n; i++){
        nw.reset();
        for(int j = 1; j <= n + 1; j++)vis[j] = 0;
        for(int j = i - 1; j >= 1; j--)run(j);
        for(int j = n; j >= i; j--)run(j);
        if(!seed){
            for(int j = 1; j <= n + 1; j++){
                if(nw[j] == 0){
                    write(j);
                    ch[++tot] = ' ';
                    break;
                }
            }
        }else{
            for(int j = 1; j <= n + 1; j++){
                if(vis[j] == 0){
                    write(j);
                    ch[++tot] = ' ';
                    break;
                }
            }
        }
    }
    ch[++tot] = '\n';
    printf(ch+1);
    return 0;
}