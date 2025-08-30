#include<bits/stdc++.h>
using namespace std;
int n,q;
long long a[305][305],f[305][305][305],s[305][305],ans[200005],book[305][305];
struct node{
	int x,y,xx,yy,id;
}l[200005];
bool cmp(node x,node y){
	return x.x>y.x;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("glyph.in","r",stdin);
	freopen("glyph.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
			s[i][j]=s[i][j-1]+a[i][j];
		}
	for(int i=0;i<q;i++){
		cin>>l[i].x>>l[i].xx>>l[i].y>>l[i].yy;
		l[i].id=i;
		book[l[i].xx][l[i].yy]++;
	}
	sort(l,l+q,cmp);
	for(int i=1;i<=n;i++)
		for(int j=i;j<=n;j++)
			f[i][n][j]=s[n][j]-s[n][i-1];
	int idx=0;
	while(idx<q&&l[idx].x==n){
		ans[l[idx].id]=f[l[idx].y][l[idx].xx][l[idx].yy];
		book[l[idx].xx][l[idx].yy]--;
		idx++;
	}
	for(int i=n-1;i>=1&&idx<q;i--){
		for(int j=i+1;j<=n;j++)
			for(int k=1;k<=n;k++){
				if(!book[j][k])
					continue;
				f[k][j][k]+=a[i][k];
				for(int m=k-1;m>=1;m--)
					f[m][j][k]=min(f[m+1][j][k],f[m][j][k])+a[i][m];
			}
		for(int j=1;j<=n;j++)
			for(int k=j;k<=n;k++){
				if(!book[i][k])
					continue;
				f[j][i][k]=s[i][k]-s[i][j-1];
			} 
		while(idx<q&&l[idx].x==i){
			ans[l[idx].id]=f[l[idx].y][l[idx].xx][l[idx].yy];
			book[l[idx].xx][l[idx].yy]--;
			idx++;
		}
	}
	for(int i=0;i<q;i++)
		cout<<ans[i]<<endl;
	return 0;
}

