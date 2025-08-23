#include <bits/stdc++.h>
using namespace std;
int type,n,m,k,x,y,Q,w,q;
int dx,dy;
bool mp[5000][5000];
int main()
{
    freopen("corridor.in","r",stdin);
    freopen("corridor.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>type>>n>>m>>k;
    for(register int i=1;i<=k;i++)
    {
        cin>>x>>y;
        mp[x][y]=1;
    }
    cin>>Q;
    while(Q--)
    {
        cin>>w;
        if(w==1)
        {
            cin>>x>>y;
            mp[x][y]=1;
        }
        else
        {
            cin>>x>>y>>q;
           // int dx=0,dy=0;
            if(!x)
            {
                dx=1,dy=0;
                x=1;
            }
            if(y==0)
            {
                dx=0,dy=1;
                y=1;
            }
            int tot=0;
            while(1)
            {
            	//cout<<x<<" "<<y<<"\n";
                while(x>=1&&x<=n&&y>=1&&y<=m&&!mp[x][y])
                {
                    x+=dx,y+=dy;
                }
                if(mp[x][y])
                {
                	
                    tot++;
                    if(tot>=q)
                    {
                    	cout<<x<<" "<<y<<" "<<"\n";
                    	break;
					}
                    //cout<<tot<<" "<<"\n";
                    if(dy!=0)
                    {
                        dx=dy;
                        dy=0;
                    }
                    else{
                        dy=dx;
                        dx=0;
                    }
                    x+=dx,y+=dy;
                }
                if(x>n)
                {
                    cout<<n+1<<" "<<y<<"\n";
                    break;
                }
                if(y>m)
                {
                    cout<<x<<" "<<m+1<<"\n";
                    break;
                }
            }
        }
    }
    return 0;
}
