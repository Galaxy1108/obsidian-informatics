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
#define mod (998244353)
struct matrix
{
	long long mat[4][4] ;
	inline matrix()
	{
		for(int i = 0 ; i < 4 ; ++i)
			for(int j = 0 ; j < 4 ; ++j)
				mat[i][j] = 0 ;
	}
	inline matrix operator*(const matrix& b) const
	{
		matrix ret ;
//		for(int i = 0 ; i < 4 ; ++i)
//			for(int j = 0 ; j < 4 ; ++j)
//				for(int k = 0 ; k < 4 ; ++k)
//					(ret.mat[i][j] += mat[i][k] * b.mat[k][j] % mod) %= mod ;
		(ret.mat[0][0] += mat[0][0] * b.mat[0][0] % mod) ;
		(ret.mat[0][0] += mat[0][1] * b.mat[1][0] % mod) ;
		(ret.mat[0][0] += mat[0][2] * b.mat[2][0] % mod) ;
		(ret.mat[0][0] += mat[0][3] * b.mat[3][0] % mod) ;
		ret.mat[0][0] %= mod ;
		
		(ret.mat[0][1] += mat[0][0] * b.mat[0][1] % mod) ;
		(ret.mat[0][1] += mat[0][1] * b.mat[1][1] % mod) ;
		(ret.mat[0][1] += mat[0][2] * b.mat[2][1] % mod) ;
		(ret.mat[0][1] += mat[0][3] * b.mat[3][1] % mod) ;
		ret.mat[0][1] %= mod ;
		
		(ret.mat[0][2] += mat[0][0] * b.mat[0][2] % mod) ;
		(ret.mat[0][2] += mat[0][1] * b.mat[1][2] % mod) ;
		(ret.mat[0][2] += mat[0][2] * b.mat[2][2] % mod) ;
		(ret.mat[0][2] += mat[0][3] * b.mat[3][2] % mod) ;
		ret.mat[0][2] %= mod ;
		
		(ret.mat[0][3] += mat[0][0] * b.mat[0][3] % mod) ;
		(ret.mat[0][3] += mat[0][1] * b.mat[1][3] % mod) ;
		(ret.mat[0][3] += mat[0][2] * b.mat[2][3] % mod) ;
		(ret.mat[0][3] += mat[0][3] * b.mat[3][3] % mod) ;
		ret.mat[0][3] %= mod ;
		
		(ret.mat[1][0] += mat[1][0] * b.mat[0][0] % mod) ;
		(ret.mat[1][0] += mat[1][1] * b.mat[1][0] % mod) ;
		(ret.mat[1][0] += mat[1][2] * b.mat[2][0] % mod) ;
		(ret.mat[1][0] += mat[1][3] * b.mat[3][0] % mod) ;
		ret.mat[1][0] %= mod ;
		
		(ret.mat[1][1] += mat[1][0] * b.mat[0][1] % mod) ;
		(ret.mat[1][1] += mat[1][1] * b.mat[1][1] % mod) ;
		(ret.mat[1][1] += mat[1][2] * b.mat[2][1] % mod) ;
		(ret.mat[1][1] += mat[1][3] * b.mat[3][1] % mod) ;
		ret.mat[1][1] %= mod ;
		
		(ret.mat[1][2] += mat[1][0] * b.mat[0][2] % mod) ;
		(ret.mat[1][2] += mat[1][1] * b.mat[1][2] % mod) ;
		(ret.mat[1][2] += mat[1][2] * b.mat[2][2] % mod) ;
		(ret.mat[1][2] += mat[1][3] * b.mat[3][2] % mod) ;
		ret.mat[1][2] %= mod ;
		
		(ret.mat[1][3] += mat[1][0] * b.mat[0][3] % mod) ;
		(ret.mat[1][3] += mat[1][1] * b.mat[1][3] % mod) ;
		(ret.mat[1][3] += mat[1][2] * b.mat[2][3] % mod) ;
		(ret.mat[1][3] += mat[1][3] * b.mat[3][3] % mod) ;
		ret.mat[1][3] %= mod ;
		
		(ret.mat[2][0] += mat[2][0] * b.mat[0][0] % mod) ;
		(ret.mat[2][0] += mat[2][1] * b.mat[1][0] % mod) ;
		(ret.mat[2][0] += mat[2][2] * b.mat[2][0] % mod) ;
		(ret.mat[2][0] += mat[2][3] * b.mat[3][0] % mod) ;
		ret.mat[2][0] %= mod ;
		
		(ret.mat[2][1] += mat[2][0] * b.mat[0][1] % mod) ;
		(ret.mat[2][1] += mat[2][1] * b.mat[1][1] % mod) ;
		(ret.mat[2][1] += mat[2][2] * b.mat[2][1] % mod) ;
		(ret.mat[2][1] += mat[2][3] * b.mat[3][1] % mod) ;
		ret.mat[2][1] %= mod ;
		
		(ret.mat[2][2] += mat[2][0] * b.mat[0][2] % mod) ;
		(ret.mat[2][2] += mat[2][1] * b.mat[1][2] % mod) ;
		(ret.mat[2][2] += mat[2][2] * b.mat[2][2] % mod) ;
		(ret.mat[2][2] += mat[2][3] * b.mat[3][2] % mod) ;
		ret.mat[2][2] %= mod ;
		
		(ret.mat[2][3] += mat[2][0] * b.mat[0][3] % mod) ;
		(ret.mat[2][3] += mat[2][1] * b.mat[1][3] % mod) ;
		(ret.mat[2][3] += mat[2][2] * b.mat[2][3] % mod) ;
		(ret.mat[2][3] += mat[2][3] * b.mat[3][3] % mod) ;
		ret.mat[2][3] %= mod ;
		
		(ret.mat[3][0] += mat[3][0] * b.mat[0][0] % mod) ;
		(ret.mat[3][0] += mat[3][1] * b.mat[1][0] % mod) ;
		(ret.mat[3][0] += mat[3][2] * b.mat[2][0] % mod) ;
		(ret.mat[3][0] += mat[3][3] * b.mat[3][0] % mod) ;
		ret.mat[3][0] %= mod ;
		
		(ret.mat[3][1] += mat[3][0] * b.mat[0][1] % mod) ;
		(ret.mat[3][1] += mat[3][1] * b.mat[1][1] % mod) ;
		(ret.mat[3][1] += mat[3][2] * b.mat[2][1] % mod) ;
		(ret.mat[3][1] += mat[3][3] * b.mat[3][1] % mod) ;
		ret.mat[3][1] %= mod ;
		
		(ret.mat[3][2] += mat[3][0] * b.mat[0][2] % mod) ;
		(ret.mat[3][2] += mat[3][1] * b.mat[1][2] % mod) ;
		(ret.mat[3][2] += mat[3][2] * b.mat[2][2] % mod) ;
		(ret.mat[3][2] += mat[3][3] * b.mat[3][2] % mod) ;
		ret.mat[3][2] %= mod ;
		
		(ret.mat[3][3] += mat[3][0] * b.mat[0][3] % mod) ;
		(ret.mat[3][3] += mat[3][1] * b.mat[1][3] % mod) ;
		(ret.mat[3][3] += mat[3][2] * b.mat[2][3] % mod) ;
		(ret.mat[3][3] += mat[3][3] * b.mat[3][3] % mod) ;
		ret.mat[3][3] %= mod ;
		return ret ;
	}
	inline void operator*=(const matrix& b)
	{
		*this = *this * b ;
	}
	inline void operator+=(const matrix& b)
	{
		(mat[0][0] += b.mat[0][0]) %= mod ;
		(mat[0][1] += b.mat[0][1]) %= mod ;
		(mat[0][2] += b.mat[0][2]) %= mod ;
	}
	inline void clear()
	{
		for(int i = 0 ; i < 4 ; ++i)
			for(int j = 0 ; j < 4 ; ++j)
				mat[i][j] = 0 ;
	}
	inline void init()
	{
		clear() ;
		mat[0][0] = mat[1][1] = mat[2][2] = mat[3][3] = 1 ;
	}
	inline bool check()
	{
		return mat[0][1] || mat[0][2] || mat[0][3] || mat[1][0] || mat[1][2] || mat[1][3] || mat[2][0] || mat[2][1] || mat[2][3] || mat[3][0] || mat[3][1] || mat[3][2] || (mat[0][0] != 1) || (mat[1][1] != 1) || (mat[2][2] != 1) || (mat[3][3] != 1) ;
	}
} ;
int n = 0 , m = 0 ;
long long A[250001] = {} , B[250001] = {} , C[250005] = {} ;
struct tr
{
	matrix dat , tag ;
} tree[250001 << 2] ;
#define ls (now << 1)
#define rs (now << 1 | 1)
#define mid (curl + curr >> 1)
inline void pushup(int now)
{
	tree[now].dat.mat[0][0] = (tree[ls].dat.mat[0][0] + tree[rs].dat.mat[0][0]) % mod ;
	tree[now].dat.mat[0][1] = (tree[ls].dat.mat[0][1] + tree[rs].dat.mat[0][1]) % mod ;
	tree[now].dat.mat[0][2] = (tree[ls].dat.mat[0][2] + tree[rs].dat.mat[0][2]) % mod ;
//	tree[now].dat.mat[0][3] = tree[ls].dat.mat[0][3] + tree[rs].dat.mat[0][3] ;
}
inline void pushdown(int now)
{
	if(tree[now].tag.check())
	{
		tree[ls].tag *= tree[now].tag ;
		tree[rs].tag *= tree[now].tag ;
		tree[ls].dat *= tree[now].tag ;
		tree[rs].dat *= tree[now].tag ;
		tree[now].tag.init() ;
	}
}
void build(int now , int curl = 1 , int curr = n)
{
	tree[now].tag.init() ;
	tree[now].dat.mat[0][3] = curr - curl + 1 ;
	if(curl == curr)
	{
		tree[now].dat.mat[0][0] = A[curl] ;
		tree[now].dat.mat[0][1] = B[curl] ;
		tree[now].dat.mat[0][2] = C[curl] ;
//		tree[now].dat.mat[0][3] = 1 ;
		return ;
	}
	build(ls , curl , mid) ;
	build(rs , mid + 1 , curr) ;
	pushup(now) ;
}
//void update(int now , int l , int r , const matrix& k , int curl = 1 , int curr = n)
//{
//	if(l <= curl && r >= curr)
//	{
//		tree[now].dat *= k ;
//		tree[now].tag *= k ;
//		return ;
//	}
//	pushdown(now) ;
//	if(l <= mid)
//		update(ls , l , r , k , curl , mid) ;
//	if(r > mid)
//		update(rs , l , r , k , mid + 1 , curr) ;
//	pushup(now) ;
//}
matrix k ;
void update(int now , int l , int r , int curl = 1 , int curr = n)
{
	if(l <= curl && r >= curr)
	{
		tree[now].dat *= k ;
		tree[now].tag *= k ;
		return ;
	}
	pushdown(now) ;
	if(l <= mid)
		update(ls , l , r , curl , mid) ;
	if(r > mid)
		update(rs , l , r , mid + 1 , curr) ;
	pushup(now) ;
}
matrix query(int now , int l , int r , int curl = 1 , int curr = n)
{
	if(l <= curl && r >= curr)
		return tree[now].dat ;
	pushdown(now) ;
	matrix ans ;
	if(l <= mid)
		ans += query(ls , l , r , curl , mid) ;
	if(r > mid)
		ans += query(rs , l , r , mid + 1 , curr) ;
	return ans ;
}
int main()
{
	File("magic") ;
	qcin>>n ;
	for(int i = 1 ; i <= n ; ++i)
		qcin>>A[i]>>B[i]>>C[i] ;
	build(1) ;
	qcin>>m ;
	matrix ans ;
	k.init() ;
	int op = 0 , l = 0 , r = 0 , v = 0 ;
	while(m--)
	{
		qcin>>op>>l>>r ;
		if(op == 1)
			k.mat[1][0] = 1 , update(1 , l , r) , k.mat[1][0] = 0 ;
		else if(op == 2)
			k.mat[2][1] = 1 , update(1 , l , r) , k.mat[2][1] = 0 ;
		else if(op == 3)
			k.mat[0][2] = 1 , update(1 , l , r) , k.mat[0][2] = 0 ;
		else if(op == 4)
			qcin>>v , k.mat[3][0] = v , update(1 , l , r) , k.mat[3][0] = 0 ;
		else if(op == 5)
			qcin>>v , k.mat[1][1] = v , update(1 , l , r) , k.mat[1][1] = 1 ;
		else if(op == 6)
			qcin>>v , k.mat[2][2] = 0 , k.mat[3][2] = v , update(1 , l , r) , k.mat[2][2] = 1 , k.mat[3][2] = 0 ;
		else
		{
			ans = query(1 , l , r) ;
			qcout<<ans.mat[0][0]<<' '<<ans.mat[0][1]<<' '<<ans.mat[0][2]<<'\n' ;
		}
	}
	return 0 ;
}
