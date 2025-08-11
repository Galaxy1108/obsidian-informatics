#include<bits/stdc++.h>
using namespace std;
const int N=150010;
int n;
struct PER{
	int x,y,z;
}a[N];
bool cmp1(PER p,PER q){
	if(p.x==q.x){
		if(p.y==q.y){
			return p.z<q.z;
		}
		else return p.y<q.y;
	}
	return p.x>q.x;
}
bool cmp2(PER p,PER q){
	if(p.y==q.y){
		if(p.z==q.z){
			return p.x<q.x;
		}
		else return p.z<q.z;
	}
	return p.y>q.y;
}
bool cmp3(PER p,PER q){
	if(p.z==q.z){
		if(p.x==q.x){
			return p.y<q.y;
		}
		else return p.x<q.x;
	}
	return p.z>q.z;
}
PER b[4][N];
int cnt[4][4010];
int sum[4][4010];//代表三种值大于i的人数 
bool flag;
int tmp[4];
void dfs(int now,int tot){
	if(now>3){
		cout<<tot;
		exit(0);
	}
	int res;
	for(int i=1;i<=n;i++){
		if(now!=1&&!sum[1][b[now][i].x]) continue;
		if(now!=2&&!sum[2][b[now][i].y]) continue;
		if(now!=3&&!sum[3][b[now][i].z]) continue;
		if(now>1&&b[now][i].x>=tmp[1]) continue;
		if(now>2&&b[now][i].y>=tmp[1]) continue;
		if(now==1) res=tot+b[now][i].x,tmp[1]=b[now][i].x;
		if(now==2) res=tot+b[now][i].y,tmp[2]=b[now][i].y;
		if(now==3) res=tot+b[now][i].z,tmp[3]=b[now][i].z;
		dfs(now+1,res);
	}
}
void solve1(){
	dfs(1,0);
	cout<<-1;
}
void dfs2(int now,int tot){
	if(now>3){
		cout<<tot;
		exit(0);
	}
	int res;
	for(int i=1;i<=n;i++){
		if(now!=1&&b[1][i].x<=b[now][i].x) continue;
		if(now!=2&&b[2][i].y<=b[now][i].y) continue;
		if(now!=3&&b[3][i].z<=b[now][i].z) continue;
		if(now>1&&b[now][i].x>=tmp[1]) continue;
		if(now>2&&b[now][i].y>=tmp[2]) continue;
		if(now==1) res=tot+b[now][i].x,tmp[1]=b[now][i].x;
		if(now==2) res=tot+b[now][i].y,tmp[2]=b[now][i].y;
		if(now==3) res=tot+b[now][i].z,tmp[3]=b[now][i].z;
		dfs2(now+1,res);
	}
}
void solve2(){
	dfs2(1,0);
	cout<<-1;
}
int main(){
	freopen("battle.in","r",stdin);
	freopen("battle.out","w",stdout);
	ios::sync_with_stdio(0);
	cin>>n;
	int max1=0,max2=0,max3=0;
	for(int i=1;i<=n;i++){
		cin>>a[i].x>>a[i].y>>a[i].z;
		max1=max(max1,a[i].x);
		max2=max(max2,a[i].y);
		max3=max(max3,a[i].z);
		if(max1<=4000&&max2<=4000&&max3<=4000){
			cnt[1][a[i].x]++;
			cnt[2][a[i].y]++;
			cnt[3][a[i].z]++;			
		}
	}
	int top=max(max1,max(max2,max3));
	sort(a+1,a+n+1,cmp1);
	for(int i=1;i<=n;i++) b[1][i]=a[i];
	sort(a+1,a+n+1,cmp2);
	for(int i=1;i<=n;i++) b[2][i]=a[i];
	sort(a+1,a+n+1,cmp3);
	for(int i=1;i<=n;i++) b[3][i]=a[i];
	if(top<=4000){
		for(int i=top;i>=1;i--){
			for(int j=1;j<=3;j++){
				sum[j][i-1]=sum[j][i]+cnt[j][i];
			}
		}	
		solve1();	
	}
	else solve2();
	return 0;
}
