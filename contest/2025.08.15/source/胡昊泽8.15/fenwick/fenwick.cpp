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
#define ull unsigned long long
int n = 0 ;
ull s1 = 0 , s2 = 0 ;
inline ull my_rand()
{
    ull s3 = s1 , s4 = s2 ;
    s1 = s2 ^ 774527 ;
    s3 ^= (s3 << 47) ^ (s3 >> 13) ;
    s2 ^= s3 ^ (s4 << 31) ^ (s4 >> 17) ;
    return s2 + s4 ;
}
inline void myswap(ull& a , ull& b)
{
	a ^= b ^= a ^= b ;
}
inline void get_query(int &op , ull &num1 , ull &num2)
{
    op = my_rand() % 2 + 1 ;
    if(op == 1)
    {
        num1 = my_rand() % n + 1 ;
        num2 = my_rand() % n + 1 ;
    }
    else
    {
        num1 = my_rand() % n + 1 ;
        num2 = my_rand() % n + 1 ;
        if(num1 > num2)
             myswap(num1 , num2) ;
    }
}
int Q = 0 ;
ull a[10000005] = {} ;
#define lowbit(x) (x & -x)
ull sum_a[10000005] = {} ;
//inline void add_sum(int x , ull k)
//{
//	for ( ; x <= n ; x += lowbit(x))
//		sum_a[x] += k ;
//}
inline void add(int x , ull k)
{
	ull i = 1 ;
	for ( ; x <= n ; x += lowbit(x) , ++i)
//		a[x] += k , add_sum(x , k) ;
		/*a[x] += k , */sum_a[x] += i * k ;
}
//inline ull get_sum(int x)
//{
//	ull ans = 0 ;
//	for( ; x ; x -= lowbit(x))
//		ans += a[x] ;
//	return ans ;
//}
//inline ull query(int l , int r)
//{
//	return get_sum(r) - get_sum(l - 1) ;
//}
inline ull get_sum(int x)
{
	ull ans = 0 ;
	for( ; x ; x -= lowbit(x))
		ans += sum_a[x] ;
	return ans ;
}
inline ull query(int l , int r)
{
	return get_sum(r) - get_sum(l - 1) ;
}
int main()
{
	File("fenwick") ;
	qcin>>n>>Q>>s1>>s2 ;
	int op = 0 ;
	ull l = 0 , r = 0 , ans = 0 ;
	for(ull i = 1 ; i <= Q ; ++i)
	{
		get_query(op , l , r) ;
		if(op == 1)
			add(l , r) ;
		else
			ans ^= i * query(l , r) ;
	}
	qcout<<ans<<'\n' ;
    return 0;
}
