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

const int MN=101;
int n;
int dp[MN][MN][MN];
bool memo[MN][MN][MN];
int data[MN][3];

int solve(int a, int b, int c)
{
	if(a+b+c==3*n)
		return 1;
	if(memo[a][b][c])
		return dp[a][b][c];

	int &ret=dp[a][b][c]=0;
	for(int i=1; i<(1<<3); i++)
	{
		int sum=0;
		int v[3]={0, 0, 0};
		if(a<n && (i&(1<<0)))
		{
			sum+=data[a][0];
			v[0]=1;
		}
		if(b<n && (i&(1<<1)))
		{
			sum+=data[b][1];
			v[1]=1;
		}
		if(c<n && (i&(1<<2)))
		{
			sum+=data[c][2];
			v[2]=1;
		}

		if((v[0]+v[1]+v[2]) && sum%3==0)
		{
			ret=max(ret, solve(a+v[0], b+v[1], c+v[2]));
		}
	}
	memo[a][b][c]=true;
	return ret;
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
	while(scanf("%d", &n) && n)
	{
		for(int i=0; i<n; i++)
			for(int j=0; j<3; j++)
				scanf("%d", &data[i][j]);
		RESET(memo, false);
		printf("%d\n", solve(0, 0, 0));
	}
	return 0;
}