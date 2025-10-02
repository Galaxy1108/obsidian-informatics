#include <bits/stdc++.h>
#define N 1000006
using namespace std;
int n,m,q,cnt[2],res[N];

int findnxt(int idx)
{
    for(int i=idx+1;i<=n;i++)if(res[i]!=-1)return i;
    return n+1;
}
int solve()
{
	int tmp[2],flg1=0,flg2=0;
	tmp[1]=cnt[1],tmp[0]=cnt[0]; 
    int ans=0;
    int lst=findnxt(0);
    vector<pair<int,int> >v;
    if(lst>1)flg1=lst;
    
    for(int i=findnxt(lst);i<=n;i=findnxt(i))
    {
        int len=i-lst-1;
        if(res[i]%2!=res[lst]%2)ans++;
        else if(len>0)v.push_back(make_pair(len,res[lst]&1));
        lst=i;
    }
    if(lst<n)flg2=lst;
    
    sort(v.begin(),v.end());
    for(int i=0;i<v.size();i++)
    {
       	if(tmp[v[i].second]>=v[i].first)tmp[v[i].second]-=v[i].first;
        else ans+=2;
    }
    if(flg1)
    {
    	int len=flg1-1;
    	if(tmp[res[flg1]&1]>=len)tmp[res[flg1]&1]-=len;
    	else ans++;
	}
	if(flg2)
	{
		int len=n-flg2;
		if(tmp[res[flg2]&1]>=len)tmp[res[flg2]&1]-=len;
		else ans++;
	}
    return ans;
}

int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
	cin>>n>>m>>q;
    for(int i=1,a;i<=n;i++)cin>>a,cnt[a&1]++,res[i]=-1;
    for(int i=1,p,b;i<=m;i++)cin>>p>>b,cnt[b&1]--,res[p]=b;
    int ty,p,x;
    while(q--)
    {
        cin>>ty>>p;
        if(ty==1)
        {
            cnt[res[p]&1]++;
            res[p]=-1;
        }
        else
        {
            cin>>x;
            cnt[x&1]--;
            res[p]=x;
        }
        cout<<solve()<<"\n";
    }
	return 0;
}
