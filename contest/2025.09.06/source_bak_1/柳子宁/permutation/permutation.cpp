#include<bits/stdc++.h>
using namespace std;
int n;
int p[100010],q[100010],to[100010],to2[100010],h[100010];
int lenp[100010],lenh[100010],tagp[100010],tagh[100010];
vector<int> a[100010],b[100010];
void solve(int A,int B,int siz){
	int x=A,y=B;
	for(int i=1;i<=siz;++i){
		h[y]=x;
		x=to2[x],y=to[y];
	}
	return;
}
int main()
{
	freopen("permutation.in","r",stdin);
	freopen("permutation.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;++i) scanf("%d",&p[i]);
	for(int i=1;i<=n;++i) scanf("%d",&q[i]);
	for(int i=1;i<=n;++i) to[q[i]]=i;
	for(int i=1;i<=n;++i) to2[p[i]]=i;
	for(int i=1;i<=n;++i){
		if(tagp[i]) continue;
		int len=0,x=i;
		while(!tagp[x]){
			tagp[x]=1,++len;
			x=p[x];
		}
		a[len].push_back(i);
		++lenp[len];
	}

	for(int i=1;i<=n;++i){
		if(tagh[i]) continue;
		int len=0,x=i;
		while(!tagh[x]){
			tagh[x]=1,++len;
			x=to[x];
		}
		b[len].push_back(i);
		++lenh[len];
	}

	int Tag=1;
	for(int i=1;i<=n;++i){
		if(lenp[i]!=lenh[i]) {Tag=0;break;}
	}
	if(Tag) printf("YES\n");
	else {printf("NO\n");return 0;}
	for(int i=1;i<=n;++i){
		int siz=(int)a[i].size();
		for(int j=0;j<siz;++j){
			solve(a[i][j],b[i][j],i);
		}
	}
	for(int i=1;i<=n;++i) printf("%d ",h[i]);
	printf("\n");
	return 0;
}