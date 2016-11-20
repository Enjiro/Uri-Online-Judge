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
int n, m;
int data[MN][MN];
pair<int,int>pos[MN*MN];


void g(int l, int r) //collumn
{
	for(int i=0; i<n; i++)
	{
		swap(pos[ data[i][l] ], pos[ data[i][r] ]);
		swap(data[i][l], data[i][r]);
	}
}

void f(int l, int r) //row
{
	for(int i=0; i<m; i++)
	{
		swap(pos[ data[l][i] ], pos[ data[r][i] ]);
		swap(data[l][i], data[r][i]);
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
	while(scanf("%d %d", &n, &m)!=EOF)
	{
		for(int i=0; i<n; i++)
		{
			for(int j=0; j<m; j++)
			{
				scanf("%d", &data[i][j]);
				pos[ data[i][j] ]=mp(i, j);
			}
		}

		bool flag=true;
		for(int i=1; i<=n*m && flag; i+=m)
		{
			int l=pos[i].F;
			for(int j=i; j<i+m && flag; j++)
			{
				if(l!=pos[j].F)
				{
					flag=false;
				}
			}
		}
		for(int i=1; i<=n && flag; i++)
		{
			int l=pos[i].S;
			for(int j=i; j<=(n*m) && flag; j+=m)
			{
				if(l!=pos[j].S)
				{
					flag=false;
				}
			}
		}

		if(!flag)
			printf("*\n");
		else
		{
			int ans=0;
			for(int i=0; i<n; i++)
			{
				for(int j=0; j<m; j++)
				{
					int x=i*m+j+1;
					if(pos[x].F!=i)
					{
						f(i, pos[x].F);
						ans++;
					}
					if(pos[x].S!=j)
					{
						g(j, pos[x].S);
						ans++;
					}
				}
			}
			printf("%d\n", ans);
		}
	}
	return 0;
}