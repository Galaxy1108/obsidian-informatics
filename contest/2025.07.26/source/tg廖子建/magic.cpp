#include<bits/stdc++.h>
#define int long long
#define N 200000
#define Q 1000000
using namespace std;
struct Node{int x,y,ans,id;};
int n,q,a[N+5],tip1,tip2,tmp[N+5],k;
Node p[Q+5];
int read(){
	int f=1,g=0;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while('0'<=ch&&ch<='9'){
		g=g*10+ch-'0';
		ch=getchar();
	}
	return f*g;
}
void print(int x){
	if(x<0){
		putchar('-');
		x*=-1;
	}
	if(x>9)print(x/10);
	putchar(x%10+'0');
	return;
}
bool cmp1(Node x,Node y){
	if(x.x==y.x)return x.y<y.y;
	return x.x<y.x;
}
bool cmp2(Node x,Node y){
	return x.id<y.id;
}
main(){
	freopen("magic.in","r",stdin);
	freopen("magic.out","w",stdout);
	n=read(),q=read();
	for(int i=1;i<=n;i++)a[i]=read();
	for(int i=1;i<=q;i++)p[i].x=read(),p[i].y=read(),p[i].id=i;
//	cout<<"dfdsifsujfsdihf\n";
	sort(p+1,p+1+q,cmp1),k=1;
	for(int i=0;i<=n&&k<=q;i++){
		while(k<=q&&p[k].x==i)p[k].ans=a[p[k].y],k++;
		for(int j=1;j<=n;j++)tmp[j]=a[j];
//		cout<<"\n";
		tip1=1,tip2=1;
		while(tip1<=n/2&&tip2<=n/2){
			if(tmp[tip1]<tmp[n/2+tip2])a[tip1+tip2-1]=tmp[tip1],tip1++;
			else a[tip1+tip2-1]=tmp[n/2+tip2],tip2++;
		}
		while(tip1<=n/2)a[n/2+tip1]=tmp[tip1],tip1++;
		while(tip2<=n/2)a[n/2+tip2]=tmp[n/2+tip2],tip2++;
	}
	while(k<=q)p[k].ans=a[p[k].y],k++;
	sort(p+1,p+1+q,cmp2);
	for(int i=1;i<=q;i++)print(p[i].ans),putchar('\n');
	return 0;
}
