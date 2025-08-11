---
熟练度:
  - t2
---
## 模板代码-Dijkstra

```cpp
#include <bits/stdc++.h>
using namespace std;
struct tt{ 
	int a,w; // -点数与权值
	friend bool operator>(tt a,tt b){ // -重载大于符号，否则代码会报奇怪的错误
		return a.w>b.w;
	}
}; 
int t[1000010]; // -答案记录
priority_queue< tt,vector<tt>,greater<tt> > q;  // -小根堆（小的在前面）
vector< vector<tt> > a; // -存图，邻接表

int main(){
	int n,m,S; // -点数、边数、原点编号
	cin>>n>>m>>S; 
	memset(t,0x7f,sizeof(t));
	/**
	关于memset还是有还能多要说的
	memset是以字节为单位赋值的
	而int有四个字节
	比如-1用补码是  11111111
	那么在int里面就是 11111111 11111111 11111111 11111111
	还是-1
	0同理
	在我们要赋值极大值时写0x7f
	如果这个极大值要做运算的话写0x3f
	**/
	a.reserve(m+1); // -扩大存储范围
	a.resize(m+1); // -扩大已有大小
	for(int i=0;i<m;i++){ 
		int n,m,v;  // -节点1、节点2、权值
		cin>>n>>m>>v; 
		a[n].push_back({m,v}); // -将线的信息压入邻接表内
		// a[m].push_back({n,v}); 双向图
	} 
	q.push({S,0}); //节点与距离原点的距离（此处压入原点信息）
	while(!q.empty()){ //队列里还有没读完的数据
		tt h=q.top(); //查询队列顶端的数据
		q.pop(); //弹出队列顶端的顺序
		if(t[h.a]<h.w){ //这个点与原点的信息已被算出（因为t初始化为极大值，这时所有可以处理的数都比他小，如果现在的点距离原点的距离小于这个点距离远点的最小距离，就说明这个点已经被搜索到了）
			continue; 
		} 
		t[h.a]=h.w; //更新最短路径
		for(int i=0;i<a[h.a].size();i++){ //这个点连接的其他点
			if(h.w+a[h.a][i].w<t[a[h.a][i].a]){  //如果现在的点与原点的最小距离加这个点与连接的这个点的距离小于这个点距离原点的最短距离，就执行下面的语句，理由同上
				t[a[h.a][i].a]=h.w+a[h.a][i].w; //将这个点距离原点的最短距离更新为现在的点与原点的最短距离加这个点与连接的这个点的距离
				q.push({a[h.a][i].a,t[a[h.a][i].a]}); //入队，内容同上
			} 
		} 
	}
	for(int i=1;i<=n;i++){ 
		cout<<t[i]<<" ";
	} 
	// system("pause"); 
	return 0; //完美结束ヾ(≧▽≦*)o
}
```

## SPFA

todo

## Floyd-Warshall

todo