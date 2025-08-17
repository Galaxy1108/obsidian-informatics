#include <bits/stdc++.h>
using namespace std;
#define ull unsigned long long
int n,q;
ull s1,s2,tr[40000005],ans;
ull my_rand()
{
    ull s3=s1,s4=s2;
    s1=s2^774527;
    s3^=(s3<<47)^(s3>>13);
    s2^=s3^(s4<<31)^(s4>>17);
    return s2+s4;
}
void get_query(int &op,ull &num1,ull &num2)
{
    op=my_rand()%2+1;
    if(op==1)
    {
        num1=my_rand()%n+1;
        num2=my_rand()%n+1;
    }
    else
    {
        num1=my_rand()%n+1;
        num2=my_rand()%n+1;
        if(num1>num2)
             swap(num1,num2);
    }
}
void add(int p,int l,int r,int x,int y){
	if(l==r){
		tr[p]+=y;
		return;
	}
	int mid=(l+r)>>1;
	if(x<=mid)
		add(p<<1,l,mid,x,y);
	else
		add(p<<1|1,mid+1,r,x,y);
	tr[p]=tr[p<<1]+tr[p<<1|1];
}
ull query(int p,int s,int t,int l,int r){
	if(l<=s&&t<=r)
		return tr[p];
	int mid=(s+t)>>1;
	ull res=0;
	if(l<=mid)
		res=query(p<<1,s,mid,l,r);
	if(r>mid)
		res+=query(p<<1|1,mid+1,t,l,r);
	return res;
}
int main()
{
    freopen("fenwick.in","r",stdin);
    freopen("fenwick.out","w",stdout);
   	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>q>>s1>>s2;
	int f=0;
	for(int i=1;i<=q;i++){
		int opt;
		ull x,y;
		get_query(opt,x,y);
		switch(opt){
			case 1:
				for(;x<=n;x+=(x&-x))
					add(1,1,n,x,y);
				break;
			case 2:
				if(f)
					ans^=(i*query(1,1,n,x,y));
				else{
					ans=i*query(1,1,n,x,y);
					f=1;
				}
				break;
		}
	}
	cout<<ans;
    return 0;
}
