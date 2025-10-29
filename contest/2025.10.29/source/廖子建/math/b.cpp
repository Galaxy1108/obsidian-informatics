#include<bits/stdc++.h>
#define int __int128
#define N 1000
#define M 100000
using namespace std;
struct Node{int a,b;};
Node operator+(Node const &x,Node const &y){
	if(x.b==0)return y;
	if(y.b==0)return x;
	Node z={x.a*y.b+y.a*x.b,x.b*y.b};
	int g=__gcd(z.a,z.b);
	z.a/=g,z.b/=g;
	return z;
}
Node operator-(Node const &x,Node const &y){
	if(x.b==0)return {-y.a,y.b};
	if(y.b==0)return x;
	Node z={x.a*y.b-y.a*x.b,x.b*y.b};
	int g=__gcd(z.a,z.b);
	z.a/=g,z.b/=g;
	return z;
}
bool operator<(Node x,Node y){
	return x.a*y.b<y.a*x.b;
}
Node a,sum[N+5];
int minn=INT_MAX;
vector<int>ans;
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
void solve(Node x){
	vector<int>uans;
	int sum=0;
	for(int i=2;i<=M;i++){
//		cout<<x.a<<" "<<x.b<<" "<<i<<"\n";
//		print(x.a),putchar(' ');
//		print(x.b),putchar(' ');
//		print(i),putchar('\n');
		if(x.a==1&&x.b>=i){
			uans.push_back(x.b);
			sum++;
			x.a=0;
			break;
		}
		if(x.a==0)break;
		if(x<((Node){1,i}))continue;
		if(rand()*1.0/RAND_MAX>0.5){
//			cout<<"ewjehfuhewiufh3uifhe3uif\n";
			uans.push_back(i),sum++;
			x=x-((Node){1,i});
		}
	}
	if(x.a==0){
		if(minn>sum){
			minn=sum;
			ans=uans;
		}
	}
	return;
}
main(){
	freopen("math.in","r",stdin);
	srand(time(0));
//	for(int i=N;i>0;i--)sum[i]=sum[i+1]+((Node){1,i}),cout<<sum[i].a<<" "<<sum[i].b<<"\n";
	a.a=read(),a.b=read();
	int gg=__gcd(a.a,a.b);
	a.a/=gg,a.b/=gg;
	while(clock()<=CLOCKS_PER_SEC*0.9)solve(a);
	print(minn),putchar('\n');
	Node check={0,0};
	for(int i:ans)print(i),putchar(' '),check=check+((Node){1,i});
	putchar('\n');
	print(check.a),putchar(' ');
	print(check.b),putchar('\n');
	return 0;
}
//0.64994298745724059293044469783352
//570 877
