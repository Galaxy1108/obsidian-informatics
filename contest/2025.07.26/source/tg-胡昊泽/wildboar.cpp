#include<iostream>
#include<cstring>
#include<vector>
#include<queue>
#define File(s) freopen(s".in" , "r" , stdin) , freopen(s".out" , "w" , stdout)
using namespace std ;
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
int n = 0 , m = 0 , t = 0 , l = 0 ;
struct edg
{
	int to ;
	long long val ;
	inline bool operator<(const edg& b) const
	{
		return val > b.val ;
	}
} ;
vector<edg> edge[2005] ;
int pat[100005] = {} ;
int fro[2005] = {} , fro_dis[2005] = {} ;
long long dis[2005] = {} , all_dis[2005] = {} ;
int cnt[2005] = {} ;
inline void dij(int sta)
{
	for(int i = 1 ; i <= n ; ++i)
		dis[i] = 1e18 , all_dis[i] = 1e18 , cnt[i] = 0 ;
	dis[sta] = 0 ;
	all_dis[sta] = 0 ;
	priority_queue<edg> Q ;
	Q.push((edg){sta , 0}) ;
	while(!Q.empty())
	{
		int now = Q.top().to ;
		Q.pop() ;
		++cnt[now] ;
		if(cnt[now] > 2)
			continue ;
		int siz = edge[now].size() , to = 0 , w = 0 ;
		for(int i = 0 ; i < siz ; ++i)
		{
			to = edge[now][i].to , w = edge[now][i].val ;
			if(to == fro[now])
				continue ;
			all_dis[to] = all_dis[now] + w ;
			if(cnt[now] == 2 && dis[to] > all_dis[now] + w)
			{
				dis[to] = all_dis[now] + w ;
				fro_dis[to] = now ;
			}
			if(cnt[now] == 1 && dis[to] > dis[now] + w)
			{
				dis[to] = dis[now] + w ;
				fro_dis[to] = now ;
			}
			fro[to] = now ;
			Q.push((edg){to , dis[to]}) ;
		}
	}
}
inline void solve()
{
	if(m > 500)
	{
		qcout<<"-1\n" ;
		return ;
	}
	long long ans = 0 ;
	for(int i = 1 ; i < l ; ++i)
	{
		for(int j = 1 ; j <= n ; ++j)
		{
			if(j != pat[i])
				fro[j] = 0 ;
			else
				fro[j] = fro_dis[j] ;
			fro_dis[j] = 0 ;
		}
		dij(pat[i]) ;
		if(dis[pat[i + 1]] == 1e18)
		{
			qcout<<"-1\n" ;
			return ;
		}
		ans += dis[pat[i + 1]] ;
	}
	qcout<<ans<<'\n' ;
	for(int i = 1 ; i <= n ; ++i)
		fro_dis[i] = 0 ;
	return ;
}
int main()
{
	File("wildboar") ;
	qcin>>n>>m>>t>>l ;
	for(int i = 1 , a , b , c ; i <= m ; ++i)
	{
		qcin>>a>>b>>c ;
		edge[a].push_back((edg){b , c}) ;
		edge[b].push_back((edg){a , c}) ;
	}
	for(int i = 1 ; i <= l ; ++i)
		qcin>>pat[i] ;
	for(int i = 1 , a , b ; i <= t ; ++i)
	{
		qcin>>a>>b ;
		pat[a] = b ;
		solve() ;
	}
	return 0 ;
}
