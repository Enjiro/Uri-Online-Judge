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
	int m, n;
	while(scanf("%d %d", &m, &n) && (m+n))
	{
		ll data[m][n];
		for(int i=0; i<m; i++)
			for(int j=0; j<n; j++)
				scanf("%lld", &data[i][j]);

		ll dp[n], dp2[m];
		for(int i=0; i<m; i++)
		{
			for(int j=0; j<n; j++)
			{
				if(j==0)
					dp[j]=data[i][j];
				else if(j==1)
					dp[j]=max(dp[j-1], data[i][j]);
				else
					dp[j]=max(data[i][j]+dp[j-2], dp[j-1]);
			}
			if(i==0)
				dp2[i]=dp[n-1];
			else if(i==1)
				dp2[i]=max(dp2[i-1], dp[n-1]);
			else
				dp2[i]=max(dp[n-1]+dp2[i-2], dp2[i-1]);

		}
		printf("%lld\n", dp2[m-1]);
	}
	return 0;
}