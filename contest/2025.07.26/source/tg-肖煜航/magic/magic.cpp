#include<cstdio>
#include<algorithm>
using namespace std;
int read(){
	register int p=0;char ch=getchar();
	while(ch<'0'||ch>'9') ch=getchar();
	while(ch>='0'&&ch<='9') p=(p<<1)+(p<<3)+ch-'0',ch=getchar();
	return p;
}
void write(register int x){
	if(x>9) write(x/10);
	putchar(x%10+'0');
} 
const int N=2e5+5;
const int M=1e6+5;
int n,q;
int a[N];
int b[N];
int ans[M];
pair<int,pair<int,int> > c[M];
int main(){
	freopen("magic.in","r",stdin);
	freopen("magic.out","w",stdout);
	n=read(),q=read();
	for(register int i=1;i<=n;i++) a[i]=read();
	for(register int i=1;i<=q;i++){
		register int x=read(),y=read();
		c[i].first=x;
		c[i].second.first=y;
		c[i].second.second=i;
	}
	sort(c+1,c+q+1);
	register int now=1;
	register int cnt=0;
	while(1){
		while(now<=q&&c[now].first==cnt){
			ans[c[now].second.second]=a[c[now].second.first];
			now++;
		}
		if(now>q) break; 
		register int pos1=1,pos2=n/2+1;
		register int pos=1;
		while(pos1<=n/2&&pos2<=n){
			if(a[pos1]<a[pos2]){
				b[pos++]=a[pos1++];
			}
			else{
				b[pos++]=a[pos2++];				
			}
		}
		while(pos1<=n/2) b[pos++]=a[pos1++];
		while(pos2<=n) b[pos++]=a[pos2++];
		bool flag=1;
		for(register int i=1;i<=n;i++) if(a[i]!=b[i]){
			flag=0;
			break;
		}	
		if(flag) break;
		for(register int i=1;i<=n;i++) a[i]=b[i];
		cnt++;
	}
	while(now<=q){
		ans[c[now].second.second]=a[c[now].second.first];
		now++;
	}
	for(register int i=1;i<=q;i++){
		write(ans[i]);
		putchar('\n');
	}
	return 0;
}
