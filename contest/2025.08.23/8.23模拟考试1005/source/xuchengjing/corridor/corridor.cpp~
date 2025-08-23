#include <cstdio>
#include <stack>
struct nd{
private:
  nd *lch,*rch;
public:
  int val;
  nd *lchild(){return lch?lch:lch=::new nd;}
  nd *rchild(){return rch?rch:rch=::new nd;}
  int lchv(){return lch?rch->val:-1;}
  int rchv(){return rch?rch->val:-1;}
  nd(){lch=rch=0ull,val=-1;}
};
struct segmtree{
  nd *root;
  int size;
  segmtree(int size):root(::new nd),size(size){}
  void update(int place,int val){
    std::stack<int> l,r;
    std::stack<nd*> cnd;
    std::stack<bool> vis;
    l.push(0),r.push(size),vis.push(0),cnd.push(root);
    while(vis.size()){
      if(vis.top()){
	cnd.top()->val=cnd.top()->lchv()==-1?cnd.top()->rchv():cnd->top()->lchv();
	l.pop(),r.pop(),vis.pop(),cnd.pop();
      }else{
	int m=l.top()+r.top()>>1;
	vis.pop(),vis.push(1);
	if(place<m){
	  cnd.push(cnd.top()->lchild());
	  l.push(l),r.push(m);
	  vis.push(0);
	}else{
	  cnd.push(cnd.top()->rchild());
	  l.push(m),r.push(r);
	  vis.push(0);
	}
      }
    }
  }
  int query(int x){
    std::stack<int> l,r;
    std::stack<nd*> cnd;
    std::stack<bool> vis;
    l.push(0),r.push(size),vis.push(0),cnd.push(root);
    while(vis.size()){
      if(vis.top()){
	cnd.top()->val=cnd.top()->lchv()==-1?cnd.top()->rchv():cnd->top()->lchv();
	l.pop(),r.pop(),vis.pop(),cnd.pop();
      }else{
	int m=l.top()+r.top()>>1;
	vis.pop(),vis.push(1);
	if(){
	  cnd.push(cnd.top()->lchild());
	  l.push(l),r.push(m);
	  vis.push(0);
	}else{
	  cnd.push(cnd.top()->rchild());
	  l.push(m),r.push(r);
	  vis.push(0);
	}
      }
    }
  }
};
