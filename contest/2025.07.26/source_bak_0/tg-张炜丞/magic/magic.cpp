#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;

int read(){
	int ans=0;
	char c=getchar();
	bool f=0;
	for(;!isdigit(c);c=getchar())c=getchar();
	for(;isdigit(c);c=getchar())ans=(ans<<=1)+(ans<<2)+(c^48);
	return f?-ans:ans;
}

void print(int x){
	if(x<0)x=-x,putchar('-');
	if(x>9)print(x/10);
	putchar(x%10|48);
}

int a[N],b[N],n,m,ans[N],vn;
struct node{
	int x,tim,id;
	bool operator<(const node &n1)const{
		return tim<n1.tim;
	}
}q[N];

bool work(){
	int mid=n/2,x=1,y=mid+1;
	for(int i=1;i<=vn;++i){
		if(y>vn||(x<=mid&&a[x]<a[y]))b[i]=a[x++];
		else b[i]=a[y++];
	} 
	bool flag=0;
	for(int i=1;i<=vn;++i){
		flag|=a[i]!=b[i];
		a[i]=b[i];
	}
	return flag;
}

signed main(){
	freopen("magic.in","r",stdin);
	freopen("magic.out","w",stdout);
	srand(time(0));
	vn=n=read();m=read();
	for(int i=1;i<=n;++i)a[i]=read();
	for(int i=1;i<=m;++i){
		q[i].tim=read();q[i].x=read();q[i].id=i;
		//cout<<" i:"<<i<<" tim:"<<q[i].tim<<" x:"<<q[i].x<<endl;
	}
	sort(q+1,q+m+1);
	bool flag=1;
	for(int i=1,t=0;i<=m;++i){
		while(flag&&t<q[i].tim){
			flag=work();++t;
			//cout<<" t:"<<t<<" flag:"<<flag<<endl;
		}
		ans[q[i].id]=a[q[i].x];
	}
	for(int i=1;i<=m;++i){
		print(ans[i]);putchar('\n');
	}
	return 0;
}


















