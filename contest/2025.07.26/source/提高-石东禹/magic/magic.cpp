#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+10;
int n,q;
int a[2][maxn];
//int b[maxn];
int lmax=0x3f3f3f3f;

int read(){
	int x;
	char c=1;
	while(c<'0'||c>'9')c=getchar();
	while('0'<=c&&c<='9'){
		x=x*10+c-48;
		c=getchar();
	}
	return x;
}

void wr(int x){
	int num[10],cnt=0;
	while(x){
		num[++cnt]=x%10;
		x/=10;
//		putchar(num+48);
	}
	for(int i=cnt;i>=1;i--)putchar(num[i]+48);
	return;
}

struct qu{
	int t;int id;
	int pos;
}ask[1000010];

int ans[1000010];

bool cmp(qu a,qu b){
	return a.t<b.t;
}

void change(int now){
//	qqq++;
//	printf("%d\n",qqq);
	
	lmax=0;
	int s=(now+1)%2,t=now%2;
	int i=1,j=n/2+1,cnt=1;
	for(;i<=n/2&&j<=n;cnt++){
		if(a[s][i]<a[s][j]){
			a[t][cnt]=a[s][i];
			i++;
		}else{
			a[t][cnt]=a[s][j];
			j++;
		}
		if(cnt<=n/2)lmax=max(lmax,a[t][cnt]);
	}
	for(;i<=n/2;i++,cnt++){
		a[t][cnt]=a[s][i];
	}
	for(;j<=n;j++,cnt++){
		a[t][cnt]=a[s][j];
	}
	return;
}

int sign=1;
int tr=0;
int ko=0;
//int ww[]

int main(){
	freopen("magic.in","r",stdin);
	freopen("magic.out","w",stdout);
	
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[0][i]);
	}
	for(register int i=1;i<=q;i++){
		scanf("%d%d",&ask[i].t,&ask[i].id);
//		ask[i].t=read();ask[i].id=read();
		ask[i].pos=i;
	}
	sort(ask+1,ask+1+q,cmp);
	int last=0;

	for(register int i=1;i<=q;i++){
		int xx=ask[i].t;
		if(sign==1){
			for(int j=last+1;j<=xx;j++){
				if(lmax<a[(j+1)%2][n/2+1]){
					tr=(j+1)%2;
					sign=0;
					break;
				}
				change(j);
				
			}
			last=xx;
			if(sign==1)tr=xx%2;
		}
//		printf("%d\n",last);
		ans[ask[i].pos]=a[tr][ask[i].id];
//		if(sign==0){
//			ko=a[tr][ask[i].id];
//			break;
//		}
	}
	for(register int i=1;i<=q;i++){
//		if(!ans[i])printf("%d\n")
//		printf("%d\n",ans[i]);
		wr(ans[i]);
		putchar('\n');
	}
	return 0;
}
/*
6 3 
1 5 6 2 3 4 
1 2 
0 4 
1 5

*/
