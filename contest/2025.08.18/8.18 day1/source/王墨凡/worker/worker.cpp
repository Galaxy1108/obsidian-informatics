#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
int ans=1e9,n,d[1086],a[1086],b[1086],c[1086],mem[1086][10][10][10];
char ch;
void dfs(int at,int bt,int ct,int pos,int step){
	if(mem[pos][at][bt][ct]>step){
		mem[pos][at][bt][ct]=step;
//		cout << step << ' ' << pos << endl;
	}
	else return;
	if(step>ans)return;
	if(at==0 and bt==0 and ct==0 and pos==n){
		ans=min(ans,step);
		return;
	}
	int k=min((pos+10-at-bt-ct),n);
	at+=a[k]-a[pos];
	bt+=b[k]-b[pos];
	ct+=c[k]-c[pos];
//	cout << at << ' ' << bt << ' ' << ct << endl;
	if(at)dfs(0,bt,ct,k,step+1);
	if(bt)dfs(at,0,ct,k,step+1);
	if(ct)dfs(at,bt,0,k,step+1);
}
int main(){
	freopen("worker.in","r",stdin); 
	freopen("worker.out","w",stdout); 
	memset(mem,0x3f,sizeof mem);
	cin >> n;
	for(int i=1;i<=n;i++)cin >> ch,d[i]=ch-'A'+1;
	for(int i=1;i<=n*2;i++){
		if(d[i]==1)a[i]=1;
		if(d[i]==2)b[i]=1;
		if(d[i]==3)c[i]=1;
		a[i]=a[i]+a[i-1];
		b[i]=b[i]+b[i-1];
		c[i]=c[i]+c[i-1];
	}
//	for(int i=1;i<=n*2;i++){
//		cout << a[i] << ' ' << b[i] << ' ' << c[i] << endl;
//	}
	dfs(0,0,0,0,0);
	cout << ans;
	return 0;
}
