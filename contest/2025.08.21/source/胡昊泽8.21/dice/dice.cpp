#include<iostream>
#include<cstring>
#include<algorithm>
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
constexpr long long mod = 1e9 + 7 ;
inline long long qpow(long long a , long long k)
{
	long long ret = 1 ;
	while(k)
	{
		if(k & 1)
			(ret *= a) %= mod ;
		(a *= a) %= mod ;
		k >>= 1 ;
	}
	return ret ;
}
long long ans = 0 ;
long long a[5005] = {} ;
int n = 0 ;
long long mul[5005] = {} ;
int main()
{
	File("dice") ;
	qcin>>n ;
//	long long maxa = 0 ;
//	for(int i = 1 ; i <= n ; ++i)
//		qcin>>a[i] , maxa = max(maxa , a[i]) ;
//	for(long long i = 1 ; i <= maxa ; ++i)
//	{
//		long long res = 1 , del = 1 ;
//		for(int j = 1 ; j <= n ; ++j)
//			(res *= min(a[j] , i) * qpow(a[j] , mod - 2) % mod) %= mod , (del *= min(a[j], i - 1) * qpow(a[j] , mod - 2) % mod) %= mod ;
//		((res -= del) += mod) %= mod ;
//		(ans += i * res % mod) %= mod ;
//	}
//	qcout<<ans<<'\n' ;
//	直接用式子可以O(nk)的做(当然，有个log，但这不重要)
	for(int i = 1 ; i <= n ; ++i)
		qcin>>a[i] ;
	sort(a + 1 , a + n + 1) ;
	mul[0]  = 1 ;
	for(int i = 1 ; i <= n ; ++i)
		mul[i] = mul[i - 1] * a[i] % mod ;
	for(int i = 0 ; i < n ; ++i)
	{
		if(a[i] == a[i + 1])
			continue ;
		long long res = 0 ;
		for(int k = a[i] + 1 ; k <= a[i + 1] ; ++k)
			(res += qpow(k , n - i + 1)) %= mod ;
		(ans += mul[i] * res % mod) %= mod ;
	}
	for(int i = 0 ; i < n ; ++i)
	{
		if(a[i] == a[i + 1])
			continue ;
		long long del = 0 ;
		for(int k = a[i] + 1 ; k <= a[i + 1] ; ++k)
			(del += qpow(k - 1 , n - i) * k % mod) %= mod ;
		((ans -= mul[i] * del % mod) += mod) %= mod ;
	}
	(ans *= qpow(mul[n] , mod - 2)) %= mod ;
	qcout<<ans<<'\n' ;
//	把式子拆一下，发现可以O(k)的做(还是有一个log，所以不可能冲过去)
//	瓶颈在于中间连续的数的幂之和，考虑这部分能不能log求
//	再硬算一下，发现有一个类似于杨辉三角的系数矩阵，但是好像没什么用，只能优化为O(n^4 log k)，不管了 
//	如果只维护下三角矩阵的话，那就会将常数缩小一半，但是还是没用
	return 0 ;
}
