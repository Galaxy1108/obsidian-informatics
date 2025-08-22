#include <cstdio>
#include <iostream>
using namespace std;
const int N=100003;
int n,a[N],b[N],p,c[N];
int main(){
	freopen("d.in","r",stdin);
	freopen("d.out","w",stdout);
	int i,j,t,q,l,r,sc;
	int s1,s2,s3,cnt[2];
	long long sa,sb;
	for(scanf("%d",&t);t>0;t--){
		scanf("%d",&n);
		for(i=1;i<=n;i++)
			scanf("%d",&a[i]);
		for(i=1;i<n;i++)
			b[i]=a[i+1]-a[i];
		for(i=2;i<n;i++)
			if(b[i]!=b[i-1]) break;
		if(i==n){
			scanf("%d",&q);
			for(i=1;i<=q;i++){
				scanf("%d%d",&l,&r);
				if(l==r) printf("0 %d 1\n",a[l]);
				else printf("%d %d 1\n",b[l],a[l]);
			}
			continue;
		}
		s1=min(b[i],b[i-1]);
		scanf("%d",&q);
		for(i=1;i<=q;i++){
			scanf("%d%d",&l,&r);
			if(l==r){
				printf("0 %d 1\n",a[l]);
				continue;
			}
			cnt[0]=cnt[1]=0;
			for(j=l;j<r;j++)
				cnt[b[j]-s1]++;
			if(cnt[0]>cnt[1]){
				if(cnt[1]==0){
					printf("%d %d 1\n",b[l],a[l]);
					continue;
				}
				s2=l,s3=r;
				while(b[s2]!=s1+1) s2++;
				while(b[s3]!=s1+1) s3--;
				if(s2==s3){
					sc=max(s2-l,r-s3)+1;
					sa=(long long)(s1+1)*sc-1;
					sb=(long long)a[l]*sc+(s2-l);
				}
				else{
					p=1,c[1]=0;
					for(j=s2+1;j<s3;j++)
						if(b[j]>s1) c[++p]=0;
						else ++c[p];
				}
				cnt[0]=cnt[1]=0;
			}
			printf("%d %d %d\n",sa,sb,sc);
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
