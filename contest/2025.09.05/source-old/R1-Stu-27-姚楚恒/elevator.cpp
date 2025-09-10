#include<bits/stdc++.h>
using namespace std;
#define getchar() (p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<11,stdin),p1==p2)?EOF:*p1++)
#define putchar(x) (p3-obuf<1<<11)?(*p3++=x):(fwrite(obuf,p3-obuf,1,stdout),p3=obuf,*p3++=x)
static char buf[1<<11],*p1=buf,*p2=buf,obuf[1<<11],*p3=obuf;
inline int read(register int &x)
{
    char c=getchar();x=0;bool f=0;
    for(;!isdigit(c);c=getchar())f^=!(c^45);
    for(;isdigit(c);c=getchar())x=(x<<1)+(x<<3)+(c^48);
    if(f)x=-x;
}
#define print(x) if(x==0)putchar('0');else write(x)
static char c[1<<11];
inline void write(register int &x)
{
	register int len=0,k1=x;
	if(k1<0)k1=-k1,putchar('-');
	while(k1)c[len++]=k1%10+'0',k1/=10;
	while(len--)putchar(c[len]);
}
int dp1[15][15][15][15][15],dp2[15][15][15][15][15],a,b,n,ssa;
int main()
{
	freopen("elevator.in","r",stdin);
	freopen("elevator.out","w",stdout);
	read(n);
	memset(dp1,0x3f,sizeof(dp1)),dp1[1][0][0][0][0]=0;
	for(register int i=1;i<=n;i++){
		read(a),read(b);
		memset(dp2,0x3f,sizeof(dp2));
		for(register int j=1;j<=9;j++){
			for(register int k1=0;k1<=9;k1++){
				for(register int k2=0;k2<=9;k2++){
					for(register int k3=0;k3<=9;k3++){
						for(register int k4=0;k4<=9;k4++){
							ssa=dp1[j][k1][k2][k3][k4]+abs(j-a)+1;
							if(!k1)dp2[a][b][k2][k3][k4]=min(dp2[a][b][k2][k3][k4],ssa);
							if(!k2)dp2[a][k1][b][k3][k4]=min(dp2[a][k1][b][k3][k4],ssa);
							if(!k3)dp2[a][k1][k2][b][k4]=min(dp2[a][k1][k2][b][k4],ssa);
							if(!k4)dp2[a][k1][k2][k3][b]=min(dp2[a][k1][k2][k3][b],ssa);
						}
					}
				}
			}
		}
		memcpy(dp1,dp2,sizeof(dp1));
		for(register int k=1;k<=4;k++){
			for(register int j=1;j<=9;j++){
				for(register int k1=0;k1<=9;k1++){
					for(register int k2=0;k2<=9;k2++){
						for(register int k3=0;k3<=9;k3++){
							for(register int k4=0;k4<=9;k4++){
								if(k1)dp1[k1][0][k2][k3][k4]=min(dp1[k1][0][k2][k3][k4],dp1[j][k1][k2][k3][k4]+abs(j-k1)+1);
								if(k2)dp1[k2][k1][0][k3][k4]=min(dp1[k2][k1][0][k3][k4],dp1[j][k1][k2][k3][k4]+abs(j-k2)+1);
								if(k3)dp1[k3][k1][k2][0][k4]=min(dp1[k3][k1][k2][0][k4],dp1[j][k1][k2][k3][k4]+abs(j-k3)+1);
								if(k4)dp1[k4][k1][k2][k3][0]=min(dp1[k4][k1][k2][k3][0],dp1[j][k1][k2][k3][k4]+abs(j-k4)+1);
							}
						}
					}
				}
			}
		}
	}
	int ans=0x3f3f3f3f;
	for(register int i=1;i<=9;i++)ans=min(ans,dp1[i][0][0][0][0]);
	print(ans);
	fwrite(obuf,p3-obuf,1,stdout);
	return 0;
}
