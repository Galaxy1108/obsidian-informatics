#include<bits/stdc++.h>
using namespace std;
int n,idx;
struct node{
	int x,y,z;
}aa[150005],a[150005]; 
map<pair<int,pair<int,int> >,int> book; 
bool cmp(node b,node c){
	return b.x>c.x;
}
int Qread()
{
	int x=0;char ch=getchar();
	while(ch<'0'||ch>'9') ch=getchar();
	while(ch>='0'&&ch<='9') x=x*10+(ch^48),ch=getchar();
	return x;
}
int main(){
	freopen("battle.in","r",stdin);
	freopen("battle.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	n=Qread();
	for(int i=0;i<n;i++){
		aa[i].x=Qread();
		aa[i].y=Qread();
		aa[i].z=Qread();
		pair<int,pair<int,int> >  ttt;
		ttt={aa[i].x,{aa[i].y,aa[i].z} };
		book[ttt]++;
		if(book[ttt]==1)
			a[idx++]=aa[i];
	}
	n=idx;
	sort(a,a+n,cmp);
	int maxn=0;
	for(int i=0;i<n-2;i++){
		for(int j=i+1;j<n-1;j++){
			for(int k=j+1;k<n;k++){
				if(a[j].y>a[i].y&&a[j].y>a[k].y&&a[k].z>a[i].z&&a[k].z>a[j].z&&a[i].x+a[j].y+a[k].z>maxn)
					maxn=a[i].x+a[j].y+a[k].z;
				if(a[k].y>a[i].y&&a[k].y>a[j].y&&a[j].z>a[i].z&&a[j].z>a[k].z&&a[i].x+a[j].z+a[k].y>maxn)
					maxn=a[i].x+a[j].z+a[k].y;
			}
		}
	}
	if(!maxn)
		cout<<-1;
	cout<<maxn;
	return 0;
}

