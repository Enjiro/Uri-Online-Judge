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

const int MN=2035;
int n, m;
char str[2][MN];
int data[MN][26];

bool memo[MN][MN];
int dp[MN][MN];
int solve(int i, int j)
{
	if(j==0)
		return 1;
	if(i==0)
		return data[j][ (str[0][i]-'a') ]==0?1:INF;
	if(data[j][ (str[0][i]-'a') ]==0)
		return 1;
	if(memo[i][j])
		return dp[i][j];

	int &ret=dp[i][j]=INF;
	ret=min(ret, solve(i-1, j));
	ret=min(ret, 1+solve(i-1, data[j][ (str[0][i]-'a') ]-1));
	memo[i][j]=true;
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
	scanf("%d %d", &n, &m);
	for(int i=0; i<2; i++)
		scanf("%s", str[i]);
	
	for(int i=1; i<=m; i++)
	{
		for(int j=0; j<26; j++)
		{
			data[i][j]=data[i-1][j];
			if(j==(str[1][i-1]-'a'))
				data[i][j]=i;
		}
	}
	printf("%d\n", solve(n-1, m));
	return 0;
}