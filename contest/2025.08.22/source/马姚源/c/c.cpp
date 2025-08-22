#include <bits/stdc++.h>
#include <random>
#include <algorithm>
using namespace std;
const int MAXN=5010;
int a[MAXN][MAXN];
void gen(int n,int seed){
    mt19937 rng(seed);
    for(int i=1;i<=n;++i){
        for(int j=1;j<=n+1;++j){
            a[i][j]=j;
            swap(a[i][j],a[i][(rng())%j+1]);
        }
    }
}
int book[MAXN];
struct Node{
    int da,id;
    bool operator < (const Node x)const {
        return da>x.da;
    }
};
int main(){
	freopen("c.in","r",stdin);
	freopen("c.out","w",stdout);
    int n,seed;
    cin >> n >> seed;
    if(seed==0){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n+1;j++){
                cin >> a[i][j];
            }
        }
    }
    else {
        gen(n,seed);
    }
    for(int i=1;i<=n;i++){
        int maxn=-1,maxi;
        for(int j=1;j<=n+1;j++){
            if(maxn<a[i][j]){
                maxn=a[i][j];
                maxi=j;
            }
        }
        cout << maxi << " ";
    }
    return 0;
}