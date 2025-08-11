#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5,M=1e6+5;
int n,m,a[N],b[N];
void work(){
	memcpy(b,a,sizeof(b));
	int cur1=1,cur2=n/2+1,i=0;
	while(cur1<=n/2||cur2<=n){
		if(cur1>n/2||cur2<=n&&b[cur1]>b[cur2])a[++i]=b[cur2++];
		else a[++i]=b[cur1++];
	}
}
struct Query{
	int t,i,id;
}q[M]; 
int ans[M];
bool operator<(Query x,Query y){
	return x.t<y.t;
}
void read(int&x){
	x=0;char c=getchar();
	while(c<'0'||'9'<c)c=getchar();
	while('0'<=c&&c<='9')x=x*10+(c-'0'),c=getchar();
}
void write(int x){
	if(x>=10)write(x/10);
	putchar(x%10+'0'); 
}
int main(){
	freopen("magic.in","r",stdin);
	freopen("magic.out","w",stdout);
	read(n),read(m);
	for(int i=1;i<=n;i++)read(a[i]);
	for(int i=1;i<=m;i++)read(q[i].t),read(q[i].i),q[i].id=i;
	sort(q+1,q+1+m);
	int cnt=0,cur=1;
	while(cnt==q[cur].t&&cur<=m)ans[q[cur].id]=a[q[cur].i],cur++;
	while(1){
		cnt++;
		work();
		bool fl=1;
		for(int i=1;i<=n;i++)if(a[i]^b[i])fl=0;
		if(fl)break;
		while(cnt==q[cur].t&&cur<=m)ans[q[cur].id]=a[q[cur].i],cur++;
	}while(cur<=m)ans[q[cur].id]=a[q[cur].i],cur++;
	for(int i=1;i<=m;i++)write(ans[i]),putchar('\n');
	return 0;
}
