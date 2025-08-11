#include <bits/stdc++.h>
#define Mod 998244353
using namespace std;
int Qread()
{
	int x=0;char ch=getchar();
	while(ch<'0'||ch>'9') ch=getchar();
	while(ch>='0'&&ch<='9') x=x*10+(ch^48),ch=getchar();
	return x;
}
int mp[256];
int get_ch()
{
	char ch=getchar();
	while(mp[ch]==-1) ch=getchar();
	return mp[ch];
}
inline void chk(int &a){if(a>=Mod) a-=Mod;}
int n,lm,nw;
int s[210];
int f[62][62][62][2][2],ans;
int o1,o2;
int main()
{
	freopen("abc.in","r",stdin);
	freopen("abc.out","w",stdout);
	
	memset(mp,-1,sizeof(mp));
	mp['A']=1,mp['B']=2,mp['C']=3,mp['?']=0;

	n=Qread();
	for(int i=1;i<=3*n;i++) s[i]=get_ch();

	lm=3*n;
	ans=0;
	for(int A=0,C;A<=n;A++)
	for(int B=0;B<=n;B++)
	{
		C=n-A-B;
		memset(f,0,sizeof(f));
		f[0][0][0][0][0]=1;
		for(int a=0;a<=n;a++)
		for(int b=0;b<=n;b++) if(b-a<=B)
		for(int c=max(0,a-A);c<=n;c++)
		if(c-b<=C&&(nw=a+b+c+1)<=lm)
		{
			if(s[nw]==1)//tr A
			{
				o1=(a+1-c==A),o2=(b-a-1==B);
				for(int z1=0;z1<=1;z1++) for(int z2=0;z2<=1;z2++)
					chk(f[a+1][b][c][z1|o1][z2|o2]+=f[a][b][c][z1][z2]);
			}
			else if(s[nw]==2)//tr B
			{
				o1=(a-c==A),o2=(b+1-a==B);
				for(int z1=0;z1<=1;z1++) for(int z2=0;z2<=1;z2++)
					chk(f[a][b+1][c][z1|o1][z2|o2]+=f[a][b][c][z1][z2]);
			}
			else if(s[nw]==3)//tr C
			{
				o1=(a-c-1==A),o2=(b-a==B);
				for(int z1=0;z1<=1;z1++) for(int z2=0;z2<=1;z2++)
					chk(f[a][b][c+1][z1|o1][z2|o2]+=f[a][b][c][z1][z2]);
			}
			else
			{
				o1=(a+1-c==A),o2=(b-a-1==B);
				for(int z1=0;z1<=1;z1++) for(int z2=0;z2<=1;z2++)
					chk(f[a+1][b][c][z1|o1][z2|o2]+=f[a][b][c][z1][z2]);

				o1=(a-c==A),o2=(b+1-a==B);
				for(int z1=0;z1<=1;z1++) for(int z2=0;z2<=1;z2++)
					chk(f[a][b+1][c][z1|o1][z2|o2]+=f[a][b][c][z1][z2]);
				
				o1=(a-c-1==A),o2=(b-a==B);
				for(int z1=0;z1<=1;z1++) for(int z2=0;z2<=1;z2++)
					chk(f[a][b][c+1][z1|o1][z2|o2]+=f[a][b][c][z1][z2]);
			}
		}
		chk(ans+=f[n][n][n][1][1]);
	}

	printf("%d\n",ans);
	return 0;
}