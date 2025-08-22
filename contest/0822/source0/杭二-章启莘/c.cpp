#include<bits/stdc++.h>
using namespace std;
const int N = 5005;
int a[N][N],n;
int b[N][N];
bool c[N];
int p[N];
void gen(int seed){
    if(!seed)
    {
        for(int i=1;i<=n;++i){
            for(int j=1;j<=n+1;++j){
                cin>>a[i][j];
            }
        }
        return ;
    }
    mt19937 rng(seed);
    for(int i=1;i<=n;++i){
        for(int j=1;j<=n+1;++j){
            a[i][j]=j;
            std::swap(a[i][j],a[i][rng()%j+1]);
        }
    }
}
int main()
{
    //system("fc c.out c2.out /w");
    freopen("c.in","r",stdin);
    freopen("c.out","w",stdout);
    ios::sync_with_stdio(false);cin.tie(0);
    int seed;
    cin>>n>>seed;
    gen(seed);
    for(int i = 1;i <= n;i++) for(int j = 1;j <= n+1;j++) b[i][a[i][j]] = j;
    //cout<<"\n";
    for(int i = 1;i <= n;i++) p[i] = 1;
    for(int i = n;i > 0;i--)
    {
        while(c[b[i][p[i]]]) p[i]++;
        c[b[i][p[i]]] = 1;
    }
    for(int i = 1;i < n;i++)
    {
        for(int j = 1;j <= n+1;j++) if(!c[j])
        {
            cout<<j<<" ";
            break;
        }
        // 接下来i变成最后一个
        p[i] = 1;
        for(int j = 1;j <= n+1;j++) c[j] = 0;
        c[b[i][p[i]]] = 1;
        for(int j = (i+n-2)%n+1;j != i;j = (j+n-2)%n+1)
        {
            while(c[b[j][p[j]]]) p[j]++;
            c[b[j][p[j]]] = 1;
        }
    }
    for(int j = 1;j <= n+1;j++) if(!c[j])
    {
        cout<<j<<"\n";
        break;
    }
    return 0;
}