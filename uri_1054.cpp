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

const int MN=105;
pair<int,int>data[MN];

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
	for(int t=1; t<=tt; t++)
	{
		int n, d;
		scanf("%d %d", &n, &d);
		data[0]={0, 0};
		data[n+1]={d, 0};

		for(int i=1; i<=n; i++)
		{
			char c;
			int x;
			scanf(" %c-%d", &c, &x);
			data[i]={x, c=='S'};
		}

		int ans=0;
		int p=0, c=1;
		for(int i=1; i<=n+1; i++)
		{
			if(data[i].S==0)
			{
				ans=max(ans, abs(p-data[i].F));
				p=data[i].F;
			}
			else if(data[i].S==1)
			{
				if(c)
				{
					data[i].S=2;
					ans=max(ans, abs(p-data[i].F));
					p=data[i].F;
				}
				c^=1;
			}
		}
		for(int i=n; i>=0; i--)
		{
			if(data[i].S<=1)
			{
				ans=max(ans, abs(p-data[i].F));
				p=data[i].F;
			}
		}
		printf("Case %d: %d\n", t, ans);
	}
	return 0;
}