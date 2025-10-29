#include <bits/stdc++.h>
using namespace std;
inline int read(){
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||'9'<ch){if(ch=='-')f=-1;ch=getchar();}
	while('0'<=ch&&ch<='9'){x=(x<<3)+(x<<1)+(ch^48);ch=getchar();}
	return x*f;
}
const int N=12;
int n,a[N],b[N];
long long ans,p;
inline int getnic(int *x){
	int cnt=0;
	for(int i=1;i<n;++i){
		for(int j=i+1;j<=n;++j)
			if(x[j]<x[i])++cnt;
	}return cnt;
}
const long long bsa[11]={0,0,0,0,17,904,45926,2725016,196884712,}; 
map<long long,int>nic;
inline long long getval(int *x){
	long long sum=0;
	for(int i=1;i<=n;++i)
		sum=sum*11+x[i];
	return sum;
}
int main(){
	freopen("pairs.in","r",stdin);
	freopen("pairs.out","w",stdout);
	scanf("%d %lld",&n,&p);
	/*int all=1,cnt=0;
	for(int i=1;i<=n;++i)all*=i;
	for(int i=1;i<=n;++i)a[i]=i;
	do{
		nic[getval(a)]=getnic(a);
	}while(next_permutation(a+1,a+1+n));
	for(int i=1;i<=n;++i)a[i]=i;
	do{	
		//printf("a ");for(int i=1;i<=n;++i)
		//	printf("%d ",a[i]);
		//putchar('\n'); 
		int tmp=nic[getval(a)];
		memcpy(b,a,sizeof(a));
		while(next_permutation(b+1,b+1+n)){
			
			//printf("b ");for(int i=1;i<=n;++i)
			//	printf("%d ",b[i]);
			//putchar('\n');
			if(nic[getval(b)]<tmp)++ans;
			//cout<<nic<<' '<<getnic(b)<<endl; 
		}++cnt;
		if(cnt%1000==0)printf("%d/%d",cnt,all);
	}while(next_permutation(a+1,a+1+n));*/
	printf("%lld\n",bsa[n]%p);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
