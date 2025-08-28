#include <bits/stdc++.h>
using namespace std;
#define N 500005
#define ull unsigned long long
mt19937_64 engine((unsigned)time(NULL));
class nr_treap{
public:
	struct node{
		int ls,rs,fa;
		int val,tag;
		ull rnd;
		node():ls(0),rs(0),fa(0),val(0),tag(0){}
	}tree[N];
#define ls(x) (tree[x].ls)
#define rs(x) (tree[x].rs)
#define fa(x) (tree[x].fa)
	int root=0,cnt=0;
	int newnode(int v){
		tree[++cnt].val=v;
		tree[cnt].rnd=engine();
		return cnt;
	}
	inline void ch(int id,int k){
		if(id==0)return ;
		tree[id].val+=k;
		tree[id].tag+=k;
	}
	inline void pushup(int id){
		if(ls(id)!=0)fa(ls(id))=id;
		if(rs(id)!=0)fa(rs(id))=id;
	}
	inline void pushdown(int id){
		if(tree[id].tag!=0){
			ch(ls(id),tree[id].tag);
			ch(rs(id),tree[id].tag);
			tree[id].tag=0;
		}
	}
	int merge(int x,int y){
		if(!x||!y)return x|y;
		pushdown(x);
		pushdown(y);
		if(tree[x].rnd<tree[y].rnd){//x is root
			rs(x)=merge(rs(x),y);
			pushup(x);
			return x;
		}
		else{
			ls(y)=merge(x,ls(y));
			pushup(y);
			return y;
		}
	}
	void split_by_val(int& x,int& y,int id,int val){
		if(!id){x=y=0;return ;}
		pushdown(id);
		if(tree[id].val<=val){
			x=id;
			split_by_val(rs(x),y,rs(id),val);
		}
		else{
			y=id;
			split_by_val(x,ls(y),ls(id),val);
		}
		pushup(x);
		pushup(y);
	}
	void pushdown_node(int x){
		static int nd[N],cnt;
		cnt=0;
		nd[++cnt]=x;
		while(tree[x].fa!=0){
			x=tree[x].fa;
			nd[++cnt]=x;
		}
		for(int i=cnt;i>=1;i--){
			pushdown(nd[i]);
		}
	}
#undef ls
#undef rs
#undef fa
}st;
int n,m,a[N],c[N],nid[N],ans[N];
vector<int>in[N],out[N];
int main(){
	freopen("thief.in","r",stdin);
	freopen("thief.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int _l,_r;
	for(int i=1;i<=m;i++){
		cin>>_l>>_r>>c[i];
		in[_l].emplace_back(i);
		out[_r].emplace_back(i);
	}
	int id1,id2,id3;
	for(int i=1;i<=n;i++){
		for(auto v:in[i]){
			nid[v]=st.newnode(c[v]);
			st.split_by_val(id1,id2,st.root,c[v]);
			st.root=st.merge(st.merge(id1,nid[v]),id2);
		}
		st.split_by_val(id1,id2,st.root,a[i]-1);
		st.split_by_val(id2,id3,id2,a[i]);
		st.ch(id1,1);
		st.ch(id3,-1);
		st.root=st.merge(st.merge(id1,id2),id3);
		for(auto v:out[i]){
			st.pushdown_node(nid[v]);
			ans[v]=st.tree[nid[v]].val;
			if(nid[v]==st.root){
				st.root=st.merge(st.tree[nid[v]].ls,st.tree[nid[v]].rs);
				st.pushup(st.root);
			}
			else{
				static int fa;fa=st.tree[nid[v]].fa;
				if(st.tree[fa].ls==nid[v]){
					st.tree[fa].ls=st.merge(st.tree[nid[v]].ls,st.tree[nid[v]].rs);
					st.pushup(st.tree[fa].ls);
				}
				else{
					st.tree[fa].rs=st.merge(st.tree[nid[v]].ls,st.tree[nid[v]].rs);
					st.pushup(st.tree[fa].rs);
				}
				st.pushup(fa);
			}
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<'\n';
	}
	return 0;
}
