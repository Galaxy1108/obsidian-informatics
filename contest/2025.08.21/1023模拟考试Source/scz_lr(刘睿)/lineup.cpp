#include <bits/stdc++.h>
using namespace std;
inline int read(){
	int x=0,w=1;
	char ch=getchar();
	while(!isdigit(ch)){
		if(ch=='-') w=-1;
		ch=getchar();
	}
	while(isdigit(ch)){
		x=x*10+(ch-'0');
		ch=getchar();
    }
    return x*w;
}
struct node{
	int v,p;
}h[121];
int n,ans;
bool cmp(node x,node y){
	if(x.v<=y.v) return 0;
	ans+=abs(x.p-y.p);
	swap(x.p,y.p);
	return 1;
}
int main()
{
	freopen("lineup.in","r",stdin);
	freopen("lineup.out","w",stdout); 
	n=read();
	for(int i=1;i<=n;i++) h[i].v=read(),h[i].p=i;
	sort(h+1,h+1+n,cmp);
	cout<<ans<<endl;
    return 0;
}

