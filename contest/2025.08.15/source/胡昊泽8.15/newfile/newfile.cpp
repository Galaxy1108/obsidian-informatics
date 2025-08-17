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
		inline void read(char& c)
		{
			char tmp = getchar() ;
			while(tmp == ' ' || tmp == '\n')
				tmp = getchar() ;
			c = tmp ;
		}
		#define sb(ch) (ch == ' ' || ch == '\n')
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
int n = 0 , m = 0 , q = 0 ;
constexpr long long mod = 1e9 + 9 ;
//struct Seg
//{
//	struct node
//	{
//		long long dat ;
//		long long tag ;
//		node* ch[2] ;
//		inline node()
//		{
//			dat = 0 ;
//			tag = 0 ;
//			ch[0] = ch[1] = nullptr ;
//		}
//		inline node(const node* x)
//		{
//			dat = x -> dat ;
//			tag = x -> tag ;
//			ch[0] = x -> ch[0] , ch[1] = x -> ch[1] ;
//		}
//		inline void copy(const node* x)
//		{
//			dat = x -> dat ;
//			tag = x -> tag ;
//			ch[0] = x -> ch[0] , ch[1] = x -> ch[1] ;
//		}
//	} ;
//	node* rt[100005] ;
//	#define mid (curl + curr >> 1)
//	inline void pushup(node*& now)
//	{
//		(now -> dat = (now -> ch[0] ? now -> ch[0] -> dat : 0) + (now -> ch[1] ? now -> ch[1] -> dat : 0)) %= mod ;
//	}
//	inline void pushdown(node* now , int curl , int curr)
//	{
//		if(now && now -> tag)
//		{
//			if(!now -> ch[0])
//				now -> ch[0] = new node() ;
//			else
//				now -> ch[0] = new node(now -> ch[0]) ;
//			if(!now -> ch[1])
//				now -> ch[1] = new node() ;
//			else
//				now -> ch[1] = new node(now -> ch[1]) ;
//			(((now -> ch[0] -> dat)/* *= 2*/) += now -> tag * (mid - curl + 1)) %= mod ;
//			(((now -> ch[1] -> dat)/* *= 2*/) += now -> tag * (curr - mid)) %= mod ;
//			now -> ch[0] -> tag += now -> tag ;
//			now -> ch[1] -> tag += now -> tag ;
//			now -> tag = 0 ;
//		}
//	}
//	node* update(const node* now , int l , int r , long long k , int curl = 1 , int curr = n)
//	{
//		node* tmp = new node() ;
//		if(now)
//			tmp -> copy(now) ;
//		if(l <= curl && r >= curr)
//		{
//			((tmp -> dat/* *= 2*/) += k * (curr - curl + 1)) %= mod ;
//			(tmp -> tag += k) %= mod ;
//			return tmp ;
//		}
//		pushdown(tmp , curl , curr) ;
//		if(l <= mid)
//			tmp -> ch[0] = update(now ? now -> ch[0] : nullptr , l , r , k , curl , mid) ;
//		if(r > mid)
//			tmp -> ch[1] = update(now ? now -> ch[1] : nullptr , l , r , k , mid + 1 , curr) ;
//		pushup(tmp) ;
//		return tmp ;
//	}
//	long long query(node* now1 , node* now2 , int l , int r , int curl = 1 , int curr = n)
//	{
//		if(l <= curl && r >= curr)
//			return ((now2 ? now2 -> dat : 0) - (now1 ? now1 -> dat : 0) + mod) % mod ;
//		pushdown(now1 , curl , curr) ;
//		pushdown(now2 , curl , curr) ;
//		long long ans = 0 ;
//		if(l <= mid)
//			(ans += query(now1 ? now1 -> ch[0] : nullptr , now2 ? now2 -> ch[0] : nullptr , l , r , curl , mid)) %= mod ;
//		if(r > mid)
//			(ans += query(now1 ? now1 -> ch[1] : nullptr , now2 ? now2 -> ch[1] : nullptr , l , r , mid + 1 , curr)) %= mod ;
//		return ans ;
//	}
//} tree ;
//int tot = 1 ;
//int main()
//{
//	qcin>>n>>m>>q ;
//	for(int i = 1 ; i <= m ; ++i)
//	{
//		int l = 0 , r = 0 ;
//		long long x = 0 ;
//		qcin>>l>>r>>x ;
//		tree.rt[tot + 1] = tree.update(tree.rt[tot] , l , r , x) ;
//		++tot ;
//	}
//	for(int i = 1 ; i <= q ; ++i)
//	{
//		int u = 0 , d = 0 , l = 0 , r = 0 ;
//		qcin>>u>>d>>l>>r ;
//		++u , ++d ;
//		qcout<<tree.query(tree.rt[u - 1] , tree.rt[d] , l , r)<<'\n' ;
//	}
//	return 0 ;
//}
long long a[5005][5005] = {} ;
#define lowbit(x) (x & -x)
inline void add(int x , long long k , int i)
{
	for( ; x <= n ; x += lowbit(x))
		a[i][x] += k ;
}
inline long long get_sum(int x , int i)
{
	long long ans = 0 ;
	for( ; x ; x -= lowbit(x))
		ans += a[i][x] ;
	return ans ;
}
inline long long query(int l , int r , int i)
{
	return get_sum(r , i) - get_sum(l - 1 , i) ;
}
int tot = 0 ;
int main()
{
	File("newfile") ;
	qcin>>n>>m>>q ;
	for(int i = 1 ; i <= m ; ++i)
	{
		int l = 0 , r = 0 ;
		long long x = 0 ;
		qcin>>l>>r>>x ;
		++tot ;
		for(int j = 1 ; j <= n ; ++j)
			a[tot][j] = a[tot - 1][j] ;
		for(int j = l ; j <= r ; ++j)
			add(j , x , tot) ;
	}
	for(int i = 1 ; i <= q ; ++i)
	{
		int u = 0 , d = 0 , l = 0 , r = 0 ;
		qcin>>u>>d>>l>>r ;
		long long ans = 0 ;
		for(int j = u ; j <= d ; ++j)
			(ans += query(l , r , j)) %= mod ;
		qcout<<ans<<'\n' ;
	}
	return 0 ;
}
/*
4 3 1
2 3 1
1 2 1
2 4 1
0 3 2 3

ans:
10
*/
