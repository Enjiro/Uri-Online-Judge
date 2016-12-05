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

const int MN=305;
int n;
double prob[MN][MN];
int sz[2*MN];
int L[2*MN], R[2*MN]; //tree

vector< pair<int,double> >solve(int x)
{
	vector< pair<int,double> >ret;
	if(x<=n)
	{
		ret.pb({x, 1});
		return ret;
	}
	vector< pair<int, double> >nxt[2];
	nxt[0]=solve(L[x]);
	nxt[1]=solve(R[x]);

	for(int l=0; l<2; l++)
	{
		for(int j=0; j<nxt[l].size(); j++)
		{
			double p=0;
			for(int k=0; k<nxt[l^1].size(); k++)
				p+=(nxt[l][j].S*nxt[l^1][k].S)*prob[nxt[l][j].F][nxt[l^1][k].F];
			ret.pb({nxt[l][j].F, p});
		}
	}
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
		for(int i=0; i<2*n; i++)
			sz[i]=0;

		for(int i=1; i<=n; i++)
			for(int j=1; j<=n; j++)
				scanf("%lf", &prob[i][j]);

		for(int i=n+1; i<2*n; i++)
		{
			scanf("%d %d", &L[i], &R[i]);
			sz[L[i]]++;
			sz[R[i]]++;
		}

		vector< pair<int,double> >ans;
		for(int i=1; i<2*n; i++)
		{
			if(sz[i]==0)
			{
				ans=solve(i);
				break;
			}
		}

		for(int i=0; i<ans.size(); i++)
		{
			if(ans[i].F==1)
			{
				printf("%.6f\n", ans[i].S);
				break;
			}
		}
	}
	return 0;
}