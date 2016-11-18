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
#define RESET(a,b) memset(a, b, sizeof(a))
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

const int MN=1e+3+35;
pll data[MN];
ll sum[MN];
ll dp[MN][MN];
ll c[MN][MN];

void solve(int k, int l, int r, int L, int R)
{
	if(l>r)
		return;
	int m=(l+r)/2;
	int s=-1;
	dp[k][m]=LINF;
	for(int i=L; i<=min(m, R); i++)
	{
		if(dp[k][m]>dp[k-1][i]+c[i+1][m])
		{
			dp[k][m]=dp[k-1][i]+c[i+1][m];
			s=i;
		}
	}
	solve(k, l, m-1, L, s);
	solve(k, m+1, r, s, R);
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
	int n, k;
	while(scanf("%d %d", &n, &k)!=EOF)
	{
		for(int i=1; i<=n; i++)
			scanf("%lld %lld", &data[i].F, &data[i].S);

		for(int i=n; i>=1; i--)
		{
			ll tot=0;
			c[i][i]=0;
			for(int j=i-1; j>=1; j--)
			{
				tot+=((data[i].F-data[j].F)*data[j].S);
				c[j][i]=tot;
			}
		}
		for(int i=1; i<=n; i++)
			dp[1][i]=c[1][i];
		for(int i=2; i<k+1; i++)
			solve(i, 1, n, 1, n);
		printf("%lld\n", dp[k][n]);	
	
	}
	return 0;
}