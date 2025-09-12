#include<bits/stdc++.h>
#include"testlib.h"
#define L(i,j,k) for(int i = (j); i <= (k); ++i)
#define R(i,j,k) for(int i = (j); i >= (k); --i)
#define mk make_pair
#define pb push_back
#define sz(a) (int)(a).size()
#define ll long long
#define fir first 
#define sec second

using namespace std;
const int N = 1e5 + 5;
struct qwq{
    int u, v, w;
}e[5 * N]; int ed;
int n, m;
int z[N];
map <pair<int, int>, int> s;
int col[N];
int f[N];
int find(int wi){
    if(f[wi] == 0 || f[wi] == wi) return wi;
    return f[wi] = find(f[wi]);
}
bool cmp(qwq aa, qwq bb){
    return aa.w < bb.w;
}
int rr[N];
int siz[N];
int main(int argc, char *argv[]){
    registerLemonChecker(argc, argv);
    n = inf.readInt(), m = inf.readInt();
    L(i, 1, n) z[i] = inf.readInt();
    int u, v, w;
    int cnt;
    cnt = ouf.readInt();
    int ans_cnt = ans.readInt();
    if(ans_cnt != cnt)    quitf(_wa, "Not perfect");
    L(i, 1, cnt){
        siz[i] = ouf.readInt();
        L(j, 1, siz[i]){
            u = ouf.readInt();
            if(u <= 0 || u > n) quitf(_wa, "Error");
            if(col[u] != 0) quitf(_wa, "A point is in more than one sets");
            col[u] = i;
        }
    }
    L(i, 1, m){
        u = inf.readInt(), v = inf.readInt(), w = inf.readInt();
        if(col[u] > col[v]) swap(u, v);
        if(col[u] != col[v]){
            if(s.count(mk(col[u], col[v]))) s[mk(col[u], col[v])] = min(s[mk(col[u], col[v])], w);
            else s[mk(col[u], col[v])] = w;    
        }
        else {
            e[++ed].u = u, e[ed].v = v, e[ed].w = w;
        }
    } 
    sort(e + 1, e + ed + 1, cmp);
    L(i, 1, ed){
        if(find(e[i].u) != find(e[i].v)){
            f[find(e[i].u)] = find(e[i].v);
            rr[col[e[i].u]] = max(rr[col[e[i].u]], e[i].w);
        }
    }
    for(auto v : s){
        if(v.sec <= min(rr[v.fir.fir] + z[siz[v.fir.fir]], rr[v.fir.sec] + z[siz[v.fir.sec]])){
            quitf(_wa, "Not meeting the conditions");
        }
    }
    quitf(_ok, "Accepted");
    return 0;
}