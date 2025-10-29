#include <cstdio>
#include <cstdlib>
#define N 1010
#ifdef WIN32
#define L_L "%I64d"
#else
#define L_L "%lld"
#endif
#define IL inline
#define RG register
#define REP(a,b,c) for(a=b;a<=c;a++)
using namespace std;
typedef long long my;
//迭代加深
int st;
my num[N];
IL my max(RG my a,RG my b){return a>b?a:b;}
IL int rd(){
	RG int res=0;RG char c=getchar();
	while(c<'0'||c>'9')c=getchar();
	while(c>='0'&&c<='9')res=res*10+c-'0',c=getchar();
	return res;
}
IL my gcd(RG my a,RG my b){
	RG my t;while(b)t=a%b,a=b,b=t;return a;
}
struct fs{
	my fz,fm;
	IL void init(RG my a,RG my b){
		RG my t=gcd(a,b);
		if(t)a/=t,b/=t;
		fz=a,fm=b;
	}
	IL fs operator - (RG my b){//分母
		RG fs t;t.fz=fz*b-fm,t.fm=fm*b;
		RG my t2=gcd(t.fz,t.fm);
		if(t2)t.fz/=t2,t.fm/=t2;
		return t;
	}
}s[N];
IL void print(){
	RG int i;
	printf("%d\n",st);
	REP(i,1,st-1)printf(L_L" ",num[i]);
	printf(L_L,num[i]);exit(0);
}
IL void dfs(RG int id){
	if(id==st){
		if(s[id].fz==1)num[id]=s[id].fm,print();
		return;
	}
	RG my a=st-id+1,b,c=s[id].fz,d=s[id].fm;
	//for(b=num[id-1]+1;d>b*c;b++);//直到满足1/b<c/d：b不能太大 
	b=max(d/c+(d%c!=0),num[id-1]+1);
	
	for(;a*d>b*c;b++){//满足：a*1/b>c/d 除最后一项外必须严格大于，否则后面无法达到目标-
		num[id]=b;s[id+1]=s[id]-b;
		dfs(id+1);
	}
}
int main(){
	freopen("math.in","r",stdin),freopen("math.out","w",stdout);
	RG my a=rd(),b=rd();
	s[1].init(a,b);num[0]=1;
	if(s[1].fz==0){printf("0");return 0;}
	REP(st,1,1000)
		dfs(1);
	return 0;
}
