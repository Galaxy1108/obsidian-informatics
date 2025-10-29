#include <bits/stdc++.h>
using namespace std;
const int N = 50;
string s[N];
int n;
int a[N*2];
bool fl;
void dfs(int now)
{
    if(now == 0) {fl=1;return;}
    for(int i=1;i<=n*2-now-1;i++)
    {
        if(!a[i] && !a[i+now+1])
        {
            a[i] = a[i+now+1] = now;
            dfs(now-1);
            if(fl) return;
            a[i] = a[i+now+1] = 0;
        }
    } 
}

int main()
{
    freopen("flower.in","r",stdin);
    freopen("flower.out","w",stdout);
    cin >> n;
    for(int i=1;i<=n;i++)
    {
        cin >> s[i];
    }
    dfs(n);
    for(int i=1;i<=n*2;i++)
    {
        cout << s[a[i]] << '\n';
    }
}