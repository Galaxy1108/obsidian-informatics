#include <bits/stdc++.h>
#define N 45
using namespace std;
int n,lim;
string name[N];
int vis[N],flg,path[N<<1];


namespace solve
{

    int res40[]={0,2,3,6,2,8,3,7,10,11,6,13,16,14,8,7,17,20,21,10,23,11,22,25,26,13,27,30,14,16,31,32,33,36,17,35,37,40,20,39,21,38,34,28,23,22,29,9,18,25,24,26,15,19,27,4,12,9,30,5,4,1,31,1,32,5,33,18,15,12,36,35,28,19,37,24,29,34,40,39,38};
    int res39[]={0,2,3,6,2,7,3,9,11,8,6,12,15,7,16,17,20,9,8,21,11,23,24,22,12,26,27,30,15,29,33,16,35,17,31,37,38,20,39,34,36,21,28,32,25,23,22,24,13,19,14,5,26,18,27,4,10,5,30,29,4,1,13,1,33,14,31,10,35,19,25,28,18,37,34,38,32,36,39};
    void Mobius(int p)
    {
        if(p==2*n+1){flg=1;return;}
        if(p==2*lim+1)lim+=4;
        if(path[p])Mobius(p+1);
        else
        {
        	for(int i=1;i<=lim;i++)
	        {
	            if(!vis[i] && !path[p+1+i] && i+1+p<=2*lim)
	            {
	                path[p]=i;
	                path[p+i+1]=i;
	                vis[i]=1;
	                Mobius(p+1);
	                if(flg)return;
	                vis[i]=0; 
					path[p]=0;
	                path[p+i+1]=0;
	            }
	        }
		}
    }



    void solve()
    {
        if(n==40)
        {
            for(int i=1;i<=2*n;i++)cout<<name[res40[i]]<<'\n';
            return;
        }
        if(n==39)
        {
            for(int i=1;i<=2*n;i++)cout<<name[res39[i]]<<'\n';
            return;
        }
    	lim=n%4;
        Mobius(1);
        if(flg)for(int i=1;i<=2*n;i++)cout<<name[path[i]]<<'\n';
    }
}


int main()
{
    freopen("flower.in","r",stdin);
    freopen("flower.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++)cin>>name[i];
    solve::solve();
    return 0;
}