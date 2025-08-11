#include <bits/stdc++.h>
using namespace std;
struct xw{
	int t,i,s;
}a[1000010];
bool cmp(xw x,xw y){
	return x.t<y.t;
}
bool cmp2(xw x,xw y){
	return x.s<y.s;
}
int n,q,flag=0,p[100010],f=1;
queue<int> l,r;
int main(){
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++){
		scanf("%d",&p[i]);
	}
	for(int i=1;i<=q;i++){
		scanf("%d%d",&a[i].t,&a[i].i);
		a[i].s=i;
	}
	sort(a+1,a+q+1,cmp);
	for(int i=a[1].t;i<=a[q].t;i++){
		flag=1;
		for(int j=1;j<=n/2;j++){
			if(p[j]>p[j+n/2]) flag=0;
			l.push(p[j]);
			r.push(p[j+n/2]);
		}
		if(flag) break;
		for(int j=1;j<=n;j++){
			if(l.empty()){
				p[j]=r.front();
				r.pop();
			}
			if(r.empty()){
				p[j]=l.front();
				l.pop();
			}
			if(r.front()>l.front()){
				p[j]=r.front();
				r.pop();
			}
			else{
				p[j]=l.front();
				l.pop();
			}
		}
		while(a[f].t==i){
			a[f].t=p[a[f].i];
			f++; 
		}
	}
	if(flag){
		while(f<=q){
			a[f].t=p[a[f].i];
			f++;
		}
	}
	sort(a+1,a+q+1,cmp2);
	for(int i=1;i<=q;i++){
		printf("%d\n",a[q].t);
	}
	return 0;
}
