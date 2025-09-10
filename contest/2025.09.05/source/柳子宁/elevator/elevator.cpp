#include<bits/stdc++.h>
using namespace std;
int n,ans,cnt,o,tot;
int a[2010],b[2010];
bitset<10010> f[10][2010];
struct Node{
	int floor,i,S;
};
queue<Node> q[2];
void add(int floor,int i,int S){
	++tot;
	if(f[floor][i][S]==1) return;
	f[floor][i][S]=1;
	q[o^1].push((Node){floor,i,S});
	return;
}
int main()
{
	freopen("elevator.in","r",stdin);
	freopen("elevator.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;++i){
		scanf("%d",&a[i]);
		scanf("%d",&b[i]);
	}
	f[1][0][0]=1;
	q[0].push((Node){1,0,0});
	ans=-1;
	while(1){
		while(!q[o].empty()){
			Node p=q[o].front();
			q[o].pop();
			int floor=p.floor,S=p.S,i=p.i;
			int a=S%10,b=(S/10)%10,c=(S/100)%10,d=(S/1000);
			if(i==n&&S==0) {ans=cnt;break;}
			
			if(floor!=1) add(floor-1,i,S);
			if(floor!=9) add(floor+1,i,S);
			if(a==floor) add(floor,i,b*10+c*100+d*1000);
			if(b==floor) add(floor,i,a+c*100+d*1000);
			if(c==floor) add(floor,i,a+b*10+d*1000);
			if(d==floor) add(floor,i,a+b*10+c*100);
			if(i<n&&(::a[i+1])==floor){
				int e=(::b[i+1]);
				if(a==0) add(floor,i+1,e+b*10+c*100+d*1000);
				if(b==0) add(floor,i+1,a+e*10+c*100+d*1000);
				if(c==0) add(floor,i+1,a+b*10+e*100+d*1000);
				if(d==0) add(floor,i+1,a+b*10+c*100+e*1000);
			}
		}
		if(ans!=-1) break;
		o^=1,++cnt;
	}
	cerr<<tot<<' ';
	printf("%d\n",ans);
	return 0;
}
