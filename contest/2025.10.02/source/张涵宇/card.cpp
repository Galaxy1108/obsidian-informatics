#include <bits/stdc++.h>
#define int long long
using namespace std;
const int maxn = 1e6+10;
int line[maxn],data[maxn];
int n,m,q;
int maxx[2];
struct sq{
	int l,r,len;
	int tp;
}node[maxn];
int read(){
    int f=1,k=0;char c = getchar();
    while(c<'0'||c>'9'){if(c=='-') f=-1;c = getchar();}
    while(c>='0'&&c<='9'){k=k*10+c-'0'; c = getchar();}
    return f*k;
}
map <int,int> mp;
bool cmp(sq a,sq b)
{
	return a.len<b.len;
}
int solve()
{
	int ans=0,cnt=0;
	int max1=maxx[1],max0=maxx[0];
    for(int i=1;i<=n;i++)
    {
        if(line[i]==-1){
            int j=i;
            while(line[j]==-1&&j<=n) j++;
            j--;
            node[++cnt]={i,j,j-i+1,(i==1||j+1==n||line[i-1]==line[j+1])?(i!=1?line[i-1]:line[j+1]):-1};
        	i=j;
		}
        else if(i!=1){
        	if(line[i-1]!=-1&&line[i]^line[i-1]) ans++;
		} 
    }
    sort(node+1,node+1+cnt,cmp);
//    printf("%lld %lld\n",max1,max0);
//    for(int i=1;i<=cnt;i++){
//    	printf("%lld %lld %lld\n",node[i].l,node[i].r,node[i].tp);
//	}
//	printf("\n");
    for(int i=1;i<=cnt;i++)
    {
    	if(node[i].tp==-1){
    		ans++;
		} 
		else{
			if(node[i].tp==1){
				if(node[i].len<=max1) max1-=node[i].len;
				else ans+=2;
			}
			else{
				if(node[i].len<=max0) max0-=node[i].len;
				else ans+=2;
			}
		}
	} 
	return ans;
}
signed main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout); 
	n=read();m=read();q=read();memset(line,-1,sizeof(line));
    for(int i=1;i<=n;i++){
        int num=read();
        maxx[num&1]++;
    }
    for(int i=1;i<=m;i++){
        int pos=read(),num=read();
        mp[num]=pos;
        line[pos]=num&1;data[pos]=num;maxx[num&1]--;
    }
    for(int i=1;i<=q;i++){
        int op=read();
        switch(op)
        {
            case 1:{
                int pos=read();int tt = line[pos];
                if(tt!=-1) maxx[tt]++;
                line[pos]=-1;mp[data[pos]]=0;printf("%lld\n",solve());
                break;
            }
            case 2:{
            	int pos = read(),b = read(),tt = line[pos],kk = mp[b];
            	if(tt!=-1) maxx[tt]++;
            	line[pos]=b&1;
				int KK=line[kk];
				if(kk!=0) line[kk]=-1;
				else maxx[b&1]--;
				mp[b]=pos;printf("%lld\n",solve());
				break;
			}
        }
    }
	return 0;
}
/*
10 8 10 
15 4 12 10 14 5 18 7 9 11  
5 12 
6 18 
1 4 
10 5 
7 7 
2 15 
9 14 
4 10 
2 8 11 
1 7 
1 6 
2 7 18 
2 6 9 
1 8 
2 8 7 
1 9 
1 4 
1 5 
*/ 
