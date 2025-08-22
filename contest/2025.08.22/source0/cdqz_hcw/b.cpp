#include<bits/stdc++.h>
#define F(i,x,y) for(int i=(x);i<=(y);i++)
using namespace std;

int n,a[2005][2005],vis[2005];
int main() {
	freopen("b.in","r",stdin);
	freopen("b.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie (0);
	cin>>n;
	F(i,1,n){
		F(j,i+1,n){
			cin>>a[i][j];
			a[j][i]=a[i][j];
		}
	}
	F(t,1,n){
		F(i,1,n)vis[i]=0;
		vis[t]=1;
		int cur=t,glb=0x3f3f3f3f;
		long long ans=0;
		while (1){
			vis[cur]=1;
			int p=0;
			F(i,1,n){
				if(!vis[i]&&(!p||a[cur][p]>a[cur][i]))p=i;
			}
			if(p){
				glb=min(glb,a[cur][p]);
				ans+=glb;
				cur=p;
			}
			else break;
		}
		cout<<ans<<"\n";
	}
	return 0;
}
