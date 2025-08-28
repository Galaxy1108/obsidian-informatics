#include<iostream>
#include<cstring>
using namespace std ;
#define File(s) freopen(s".in" , "r" , stdin) , freopen(s".out" , "w" , stdout)
namespace IO
{
	#define isdigit(ch) (ch >= '0' && ch <= '9')
	#define SIZE (1 << 16)
	namespace Read
	{
		char buf[SIZE] , *_now = buf , *_end = buf ;
		inline char getchar()
		{
			if(_now == _end)
			{
				_now = _end = buf ;
				_end += fread(buf , 1 , SIZE , stdin) ;
				if(_now == _end)
					return EOF ;
			}
			return *(_now++) ;
		}
		template<typename T>
		inline void read(T& w)
		{
			w = 0 ;
			short f = 1 ;
			char ch = getchar() ;
			while(!isdigit(ch))
			{
				if(ch == '-')
					f = -1 ;
				ch = getchar() ;
			}
			while(isdigit(ch))
				w = (w << 1) + (w << 3) + (ch ^ 48) , ch = getchar() ;
			w *= f ;
		}
		#define sb(ch) (ch == ' ' || ch == '\n' || ch == '\r')
		inline void read(char& c)
		{
			char tmp = getchar() ;
			while(sb(tmp))
				tmp = getchar() ;
			c = tmp ;
		}
		inline void read(char* s)
		{
			char ch = getchar() ;
			while(sb(ch) && ch != EOF)
				ch = getchar() ;
			int len = 0 ;
			while(!sb(ch) && ch != EOF)
				s[len++] = ch , ch = getchar() ;
			s[len] = '\0' ;
		}
		inline void read(string& s)
		{
			s.clear() ;
			char ch = getchar() ;
			while(sb(ch) && ch != EOF)
				ch = getchar() ;
			while(!sb(ch) && ch != EOF)
				s.push_back(ch) , ch = getchar() ;
		}
		class qistream
		{
			public:
			template<typename T>
			inline qistream& operator>>(T& a)
			{
				read(a) ;
				return *this ;
			}
			inline qistream& operator>>(char* s)
			{
				read(s) ;
				return *this ;
			}
		} qcin ;
	}
	namespace Write
	{
		#define SIZE (1 << 16)
		char buf[SIZE] , *p = buf ;
		inline void flush()
		{
			fwrite(buf , 1 , p - buf , stdout) ;
			p = buf ;
		}
		inline void putchar(char ch)
		{
			if(p == buf + SIZE)
				flush() ;
			*p = ch ;
			++p ;
		}
		class Flush{public:~Flush(){flush() ;};}_;
		template<typename T>
		inline void write(T x)
		{
			char st[50] ;
			int len = 0 ;
			if(x < 0)
				putchar('-') , x = -x ;
			do
			{
				st[++len] = x % 10 + '0' ;
				x /= 10 ;
			} while(x) ;
			while(len)
				putchar(st[len--]) ;
		}
		inline void write(char c)
		{
			putchar(c) ;
		}
		inline void write(const char* s)
		{
			int siz = strlen(s) ;
			for(int i = 0 ; i < siz ; ++i)
				putchar(s[i]) ;
		}
		inline void write(char* s)
		{
			int siz = strlen(s) ;
			for(int i = 0 ; i < siz ; ++i)
				putchar(s[i]) ;
		}
		inline void write(string& s)
		{
			int siz = s.size() ;
			for(int i = 0 ; i < siz ; ++i)
				putchar(s[i]) ;
		}
		class qostream
		{
			public:
			template<typename T>
			inline qostream& operator<<(T x)
			{
				write(x) ;
				return *this ;
			}
			inline qostream& operator<<(const char* s)
			{
				write(s) ;
				return *this ;
			}
		} qcout ;
	}
	using Read::qcin ;
	using Write::qcout ;
}
using namespace IO ;
int n = 0 , q = 0 ;
long long a[200005] = {} ;
#define baoli
#ifdef baoli
namespace S1
{
	inline void solve()
	{
		int op = 0 , l = 0 , r = 0 ;
		long long v = 0 ;
		while(q--)
		{
			qcin>>op ;
			if(op == 1)
			{
				qcin>>v ;
				for(int i = 1 ; i <= n ; ++i)
					a[i] = a[i] > v ? v : a[i] ;
			}
			else if(op == 2)
			{
				for(int i = 1 ; i <= n ; ++i)
					a[i] += i ;
			}
			else
			{
				qcin>>l>>r ;
				long long ans = 0 ;
				for(int i = l ; i <= r ; ++i)
					ans += a[i] ;
				qcout<<ans<<'\n' ;
			}
		}
		return ;
	}
}
#endif
#define sol
#ifdef sol
constexpr long long inf = 1e15 ;
#define mid (curl + curr >> 1)
struct Seg
{
	struct node
	{
		long long sum ;
		int cnt ;
		node* ch[2] ;
		inline node()
		{
			sum = cnt = 0 ;
			ch[0] = ch[1] = nullptr ;
		}
	} ;
	node* rt ;
	#define ls (now -> ch[0])
	#define rs (now -> ch[1])
	void update(node*& now , long long x , long long curl = 0 , long long curr = 1e12)
	{
		if(!now)
			now = new node() ;
		++now -> cnt , now -> sum += x ;
		if(curl == curr)
			return ;
		if(x <= mid)
			update(ls , x , curl , mid) ;
		else
			update(rs , x , mid + 1 , curr) ;
	}
	void del(node*& now , long long x , int cnt = 0 , long long curl = 0 , long long curr = 1e12)
	{
		if(!now)
			return ;
		now -> cnt += cnt , now -> sum += x * cnt ;
		if(curl == curr)
			return ;
		if(x <= mid)
			del(ls , x , cnt + (rs -> cnt) , curl , mid) , rs = nullptr ;
		else
			del(rs , x , cnt , mid + 1 , curr) ;
	}
	#undef ls
	#undef rs
} ;
//Seg::node* merge(Seg::node* x , Seg::node* y , long long curl = 0 , long long curr = 1e12)
//{
//	Seg::node* tmp = new Seg::node() ;
//	tmp -> cnt = x -> cnt + y -> cnt , tmp -> sum = x -> sum + y -> sum ;
//	if(curl == curr)
//		return tmp ;
//	if(x -> ch[0] && y -> ch[0])
//		tmp -> ch[0] = merge(x -> ch[0] , y -> ch[0] , curl , mid) ;
//	else if(x -> ch[0])
//		tmp -> ch[0] = x -> ch[0] ;
//	else if(y -> ch[0])
//		tmp -> ch[0] = y -> ch[0] ;
//	if(x -> ch[1] && y -> ch[1])
//		tmp -> ch[1] = merge(x -> ch[1] , y -> ch[1] , curl , mid) ;
//	else if(x -> ch[1])
//		tmp -> ch[1] = x -> ch[1] ;
//	else if(y -> ch[1])
//		tmp -> ch[1] = y -> ch[1] ;
//	return tmp ;
//}
struct tr
{
	Seg dat ;
	long long tag ;
} tree[200001 << 2] ;
#define ls (now << 1)
#define rs (now << 1 | 1)
//inline void pushup(int now)
//{
//	tree[now].dat.rt = merge(tree[ls].dat.rt , tree[rs].dat.rt) ;
//}
inline void pushdown(int now)
{
	if(tree[now].tag != inf)
	{
		tree[ls].tag = min(tree[ls].tag , tree[now].tag) ;
		tree[rs].tag = min(tree[rs].tag , tree[now].tag) ;
		tree[ls].dat.del(tree[ls].dat.rt , tree[ls].tag) ;
		tree[rs].dat.del(tree[rs].dat.rt , tree[rs].tag) ;
		tree[now].tag = inf ;
	}
}
void build(int now , int curl = 1 , int curr = n)
{
	for(int i = curl ; i <= curr ; ++i)
		tree[now].dat.update(tree[now].dat.rt , a[i]) ;
	tree[now].tag = inf ;
	if(curl == curr)
		return ;
	build(ls , curl , mid) ;
	build(rs , mid + 1 , curr) ;
}
inline void update(long long x)
{
	tree[1].dat.del(tree[1].dat.rt ,  x) ;
	tree[1].tag = min(tree[1].tag , x) ;
	return ;
}
long long query(int now , int l , int r , int curl = 1 , int curr = n)
{
	if(l <= curl && r >= curr)
		return tree[now].dat.rt -> sum ;
	pushdown(now) ;
	long long ans = 0 ;
	if(l <= mid)
		ans += query(ls , l , r , curl , mid) ;
	if(r > mid)
		ans += query(rs , l , r , mid + 1 , curr) ;
	return ans ;
}
#undef ls
#undef rs
inline void solve3()
{
	int op = 0 , l = 0 , r = 0 ;
	long long v = 0 ;
	build(1) ;
	while(q--)
	{
		qcin>>op ;
		if(op == 1)
			qcin>>v , update(v) ;
		else if(op == 3)
			qcin>>l>>r , qcout<<query(1 , l , r)<<'\n' ;
	}
}
#endif
int main()
{
	File("easy") ;
	qcin>>n>>q ;
	for(int i = 1 ; i <= n ; ++i)
		qcin>>a[i] ;
	#ifdef baoli
	if(n <= 10000)
	{
		S1::solve() ;
		return 0 ;
	}
	#endif
	#ifdef sol
	solve3() ;
	#endif
	return 0 ;
}
