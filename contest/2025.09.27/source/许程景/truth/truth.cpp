#include <cstdio>
struct nd{
    int val;
    nd *lch,*rch;
};
nd *root=::new nd;
int all[50000],inp;
void build_tree(nd *cnd,int l,int r){
    if(r-l==1){
	scanf("%d",&inp);
	cnd->val=1<<(inp-1);
    }else{
	int m=(l+r)>>1;
	build_tree(cnd->lch=::new nd,l,m);
	build_tree(cnd->rch=::new nd,m,r);
	cnd->val=cnd->lch->val|cnd->rch->val;
    }
}
int cval,cx;
void _update(nd *cnd,int l,int r){
    if(l==cx&&r==cx+1) cnd->val=cval;
    else{
	int m=(l+r)>>1;
	if(cx<m) _update(cnd->lch,l,m);
	else _update(cnd->rch,m,r);
	cnd->val=cnd->lch->val|cnd->rch->val;
    }
}
int _query(nd *cnd,int l,int r){
    if(r-l==1){
	if((cnd->val&cval)==cval) return r;
	else return -1;
    }
    int m=(l+r)>>1;
    if((cnd->lch->val&cval)==cval) return _query(cnd->lch,l,m);
    if((cnd->val&cval)==cval){
	cval&=~cnd->lch->val;
	return _query(cnd->rch,m,r);
    }
    return -1;
}

int main(){
    int size,k,ops,p;
    scanf("%d%d%d",&size,&k,&ops);
    build_tree(root,0,size);
    while(ops--){
	int op;
	scanf("%d",&op);
	if(op==1){
	    scanf("%d%d",&cx,&p);
	    cval=(1<<(p-1));cx=cx-1;
	    _update(root,0,size);
	}else{
	    cval=(1<<k)-1;
	    printf("%d\n",_query(root,0,size));
	}
    }
    return 0;
}
	    
