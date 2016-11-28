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

const int MN=1e+3+1;
const int MN2=200000+1;
int n, k;
int data[MN];
int dp[2][MN2];

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
	while(scanf("%d", &n) && n)
	{
		k=0;
		for(int i=0; i<n; i++)
		{
			scanf("%d", &data[i]);
			k+=data[i];
		}

		for(int i=0; i<=2*k; i++)
			dp[0][i]=-INF;
		dp[0][k]=0;
		for(int i=0; i<n; i++)
		{
			for(int j=-k; j<=k; j++)
			{
				dp[1][k+j]=dp[0][k+j];
				
				dp[1][k+j]=max(dp[1][k+j], data[i]+dp[0][k+j+data[i]]);
				if(k+j-data[i]>=0)
					dp[1][k+j]=max(dp[1][k+j], data[i]+dp[0][k+j-data[i]]);
			}
			for(int j=0; j<=2*k; j++)
				dp[0][j]=dp[1][j];
		}
		printf("%d\n", max(0, dp[0][k]/2));
	}
	return 0;
}