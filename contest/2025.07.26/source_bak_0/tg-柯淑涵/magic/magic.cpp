#include <bits/stdc++.h>
using namespace std;
struct node{
	int nex,lst,val,num;
}f[200005];
int n,q;
int a[300005];
int s[10001][1001],s1[200001];
int main(){
	freopen("magic.in","r",stdin);
	freopen("magic.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(n<=1000){
		for(int i=1;i<=n;i++) s[0][i]=a[i];
		int x,y,cnt=0;
		for(int i=1;i<=n*3;i++){
			x=1,y=n/2+1;
			for(int j=1;j<=n;j++){
				if((s[i-1][x]<s[i-1][y]||y==n+1)&&x<=n/2) s[i][j]=s[i-1][x],x++;
				else s[i][j]=s[i-1][y],y++;
			}
		}
		for(int i=1;i<=q;i++){
			scanf("%d%d",&x,&y);
			if(x>n*3) x=n*3;
			printf("%d\n",s[x][y]);
		}
	} 
	else{
		int xx,yy,x,y;
		cin>>xx>>yy;
		int t1,t2,t3,t4;
		f[0].nex=1;
		int fl=1;
		for(int i=1;i<=xx;i++){
			x=1,y=n/2+1;
			for(int j=1;j<=n;j++){
				if((a[x]<a[y]||y==n+1)&&x<=n/2) s1[j]=a[x],x++;
				else s1[j]=a[y],y++;
			}
			fl=1;
			for(int j=1;j<=n;j++){
				if(a[j]!=s1[j]) fl=0;
				a[j]=s1[j];
			}
			if(fl) break;
		}
		cout<<s1[yy]<<endl;
		for(int i=1;i<=q;i++){
			scanf("%d%d",&x,&y);
			printf("%d\n",s1[y]);
		}
	}
	return 0;
}
/*
6 3 
1 5 6 2 3 4 
1 2 
0 4 
1 5

6 6 
2 1 5 4 6 3 
0 1 
1 1 
0 3 
1 3 
0 6 
10 6

10 10 
7 5 2 9 10 8 4 3 6 1 
3 1 
3 2 
3 3 
3 4 
3 5 
3 6 
3 7 
3 8 
3 9 
3 10
*/
