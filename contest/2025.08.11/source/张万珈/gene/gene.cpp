#include <bits/stdc++.h>
using namespace std;
int s[1000010];
vector<int> e[1000010];
int mn[1000010],id[1000010];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    freopen("gene.in","r",stdin);
    freopen("gene.out","w",stdout);
    int n,ll,rr;
    cin >> n >> ll >> rr;
    for(int i=1;i<=n;i++)
    {
        cin >> s[i];
        // cout << s[i] << endl;
        e[s[i]].push_back(i);
    }
    mn[rr] = 1e8;
    for(int i=rr+1;i<=n;i++)
    {
        int now = 0;
        if(e[s[i]][e[s[i]].size()-1] != i)
        {
            mn[i] = mn[i-1];
            id[i] = id[i-1];
            continue;
        }
        bool fl=0;
        for(int x:e[s[i]])
        {
            if(x != i && x >= ll)
            {
                id[i] = id[i-1];
                mn[i] = mn[i-1];
                fl=1;
                break;
            }
            
        }
        if(fl) continue;
        if(e[s[i]].size()==1) 
        {
            mn[i] = 0;
            for(int j=i;j<=n;j++)
            {
                id[j] = i;
            }
            break;
        }
        if(e[s[i]][e[s[i]].size()-2] < mn[i-1])
        {
            mn[i] = e[s[i]][e[s[i]].size()-2];
            id[i] = i;
        }
        mn[i] = min(mn[i-1],e[s[i]][e[s[i]].size()-2]);
    }
    int ans = 1e8;
    for(int i=1;i<=ll-1;i++)
    {
        bool fl=0;
        for(int x:e[s[i]])
        {
            if(x != i && x <= rr)
            {
                fl=1;
                break;
            }
        }
        if(fl) continue;
        int l=rr+1,r=n,ansr=-1;
        while(l<=r)
        {
            int mid = (l+r)>>1;
            if(mn[mid] < i && (e[s[i]].size() == 1 || (id[mid] < e[s[i]][1])))
            {
                // cout << mid << ' ' << ((e[s[i]].size()==1)?e[s[i]][0]:e[s[i]][1]) << endl;
                ansr = mid;
                r = mid-1;
            }
            else
            {
                l = mid+1;
            }
        }
        if(ansr!=-1)
        {
            // cout << i << ' ' << ansr << endl;
            ans = min(ans,ansr-i+1);
        }
    }
    if(ans == 1e8) cout << -1;
    else cout << ans;
    return 0;
}