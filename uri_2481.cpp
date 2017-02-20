/// David Mateus Batista <david.batista3010@gmail.com>
/// Computer Science - Federal University of Itajuba - Brazil

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

#define INF 0x3F3F3F3F
#define LINF 0x3F3F3F3F3F3F3F3FLL
#define DINF (double)1e+30
#define EPS (double)1e-9
#define PI (double)acos(-1.0)
#define RAD(x) (double)(x*PI)/180.0
#define PCT(x,y) (double)x*100.0/y
#define pb push_back
#define mp make_pair
#define pq priority_queue
#define F first
#define S second
#define D(x) x&(-x)
#define ALL(x) x.begin(),x.end()
#define SET(a,b) memset(a, b, sizeof(a))
#define DEBUG(x,y) cout << x << y << endl
#define gcd(x,y) __gcd(x, y)
#define lcm(x,y) (x/gcd(x,y))*y
#define bitcnt(x) __builtin_popcountll(x)
#define lbit(x) 63-__builtin_clzll(x)
#define zerosbitll(x) __builtin_ctzll(x)
#define zerosbit(x) __builtin_ctz(x)

enum {North, East, South, West};
//{0, 1, 2, 3}
//{Up, Right, Down, Left}

int mi[] = {-1, 0, 1, 0, -1, 1, 1, -1};
int mj[] = {0, 1, 0, -1, 1, 1, -1, -1};

const long long is_query=-(1LL<<62);
class Line
{
public:
	long long m, b;
	mutable function<const Line*()>succ;
	bool operator < (const Line &rhs) const
	{
		if(rhs.b!=is_query)
			return m<rhs.m;
		const Line *s=succ();
		if(!s)
			return 0;
		long long x=rhs.m;
		return (b-s->b)<((s->m-m)*x);
	}
};

class HullDynamic: public multiset<Line>
{
public:
	void cls()
	{
		clear();
	}
	bool bad(iterator y)
	{
		auto z=next(y);
		if(y==begin())
		{
			if(z==end())
				return 0;
			return (y->m==z->m && y->b<=z->b);
		}
		auto x=prev(y);
		if(z==end())
			return (y->m == x->m && y->b<=x->b);
		return ((x->b - y->b)*(z->m - y->m) >= (y->b - z->b)*(y->m - x->m));
	}
	void insertLine(ll m, ll b)
	{
		auto y=insert({m, b});
		y->succ=[=]
		{
			return next(y)==end()?0:&*next(y);
		};
		if(bad(y))
		{
			erase(y);
			return;
		}
		while(next(y)!=end() && bad(next(y)))
			erase(next(y));
		while(y!=begin() && bad(prev(y)))
			erase(prev(y));
	}
	long long query(long long x)
	{
		auto ret=*lower_bound((Line){x, is_query});
		return ret.m*x+ret.b;
	}
};

inline void fastRead(ll &n)
{
	n=0;
	register ll c=getchar_unlocked();
	register ll s=0;
	while(c<'0' || c>'9')
	{
		if(c=='-')
			s=1;
		c=getchar_unlocked();
	}
	while(c>='0' && c<='9')
	{
		n=(n<<3)+(n<<1)+c-'0';
		c=getchar_unlocked();
	}
}

const int MN=1e+5+35;
int n;
HullDynamic cht;
ll dp[MN], x[MN], c[MN];

void init()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	cout << "[FREOPEN]" << endl;
	return;
}

int main()
{
	//init();
	int tt;
	scanf("%d", &tt);
	while(tt--)
	{
		cht.cls();
		scanf("%d", &n);
		for(int i=1; i<=n; i++)
			fastRead(x[i]), fastRead(c[i]);

		dp[n]=-c[n];
		cht.insertLine(x[n], dp[n]);
		for(int i=n-1; i>=0; i--)
		{
			dp[i]=cht.query(x[i])-(x[i]*x[i])-c[i];
			cht.insertLine(x[i], dp[i]);
		}
		ll ans=dp[0];
		printf("%s %lld\n", (ans>0)?"Ganha":"Perde", abs(ans));
	}
	return 0;
}