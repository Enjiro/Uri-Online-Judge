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
#define SZ(x) (int)x.size()
#define ALL(x) x.begin(),x.end()
#define SET(a,b) memset(a, b, sizeof(a))

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

inline int cmp(ll x, ll y=0)
{
	return (x<=y)?(x<y)?-1:0:1;
}

struct point
{
	ll x=0, y=0;
	point(){};
	point(ll _x, ll _y)
	{
		x=_x, y=_y;
	}
	point operator +(point q){return point(x+q.x, y+q.y);}
	point operator -(point q){return point(x-q.x, y-q.y);}
	point operator *(double t){return point(x*t, y*t);}
	point operator /(double t){return point(x/t, y/t);}
	double operator *(point q){return x*q.x + y*q.y;}
	double operator %(point q){return x*q.y - y*q.x;}
	double polar(){return atan2(x, y);}
	double mod(){return sqrt(x*x + y*y);}
	double mod2(){return (x*x + y*y);}
	point rotate(double t){return point(x*cos(t)-y*sin(t), x*sin(t)+y*cos(t));}
	int cmp(point q) const
	{
		if(int t=::cmp(x, q.x))
			return t;
		return ::cmp(y, q.y);
	}
	bool operator ==(point q) const{return cmp(q)==0;}
	bool operator !=(point q) const{return cmp(q)!=0;}
	bool operator <(point q) const{return cmp(q)<0;}
	static point pivot;
};
point point::pivot;
typedef vector<point>polygon;
inline int ccw(point p, point q, point r)
{
	return cmp((p-r)%(q-r));
}

bool polarCompare(point x, point y)
{
	return x.polar()<y.polar();
}

const int MN=2*100+35;
int n, m, s;

ll val[MN][MN];
bool memo[MN][MN];
ll dp[MN][MN];
ll solve(int i, int g)
{
	if(g==1)
		return val[i][n-2+s];
	if(i==(n-1)+s)
		return g==0?0:LINF;
	if(memo[i][g])
		return dp[i][g];
	ll &ret=dp[i][g]=LINF;
	for(int j=i+1; j<n+s-1; j++)
		if(val[i][j]!=LINF)
			ret=min(ret, val[i][j]+solve(j+1, g-1));
	memo[i][g]=true;
	return ret;
}

ll getArea(polygon P)
{
	ll result=0, x1, y1, x2, y2;
	for (int i=0; i<(int)P.size()-1; i++)
	{
		x1 = P[i].x; x2 = P[i+1].x;
		y1 = P[i].y; y2 = P[i+1].y;
		result += (x1 * y2 - x2 * y1);
	}
	return abs(result);
}

polygon convexHull(polygon T)
{
	int n=T.size(), k=0;
	polygon H(2*n);

	sort(T.begin(), T.end());
	//lower_hull
	for(int i=0; i<n; i++)
	{
		while(k>=2 && ccw(H[k-1], T[i], H[k-2])<=0)
			k--;
		H[k++]=T[i];
	}
	//upper_hull
	for(int i=n-2, t=k+1; i>=0; i--)
	{
		while(k>=t && ccw(H[k-1], T[i], H[k-2])<=0)
			k--;
		H[k++]=T[i];
	}
	H.resize(k);
	return H;
}

point c;
void build(polygon T)
{
	int sz=T.size();
	sort(T.begin(), T.end(), polarCompare);

	for(int i=0; i<2*sz; i++)
		for(int j=0; j<2*sz; j++)
			val[i][j]=LINF;

	for(int i=0; i<sz; i++)
	{
		polygon temp;
		temp.pb(c);
		temp.pb(T[i%sz]);
		for(int j=i+1; j<i+sz; j++)
		{
			temp.pb(T[j%sz]);
			polygon ch=convexHull(temp);

			bool flag=false;
			for(int k=0; k<ch.size() && !flag; k++)
				flag=(c.x==ch[k].x && c.y==ch[k].y);

			if(flag)
				val[i][j]=getArea(convexHull(temp));
		}
	}
}

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
	while(scanf("%d %d", &m, &n) && (n+m))
	{
		scanf("%lld %lld", &c.x, &c.y);
		polygon data;
		for(int i=0; i<n-1; i++)
		{
			ll x, y;
			scanf("%lld %lld", &x, &y);
			data.pb(point(x-c.x, y-c.y));
		}
		c.x=c.y=0;
		build(data);
		
		ll ans=LINF;
		for(s=0; s<n-1; s++)
		{
			SET(memo, false);
			ans=min(ans, solve(s, m));
		}

		double dans=1.0L*ans/2.0L;
		printf("%.2f\n", dans);
	}
	return 0;
}