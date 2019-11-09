#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<utility>
#include<algorithm>
using namespace std;
typedef pair<int, int> p;

#define INF 0x7fff
#define N 200100

p arr[N];
int dp[N], t[N], par[N];

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		dp[i] = INF;
		par[i] = -1;
	}
	par[0] = 0;
	for (int i = 0; i < n; ++i) {
		scanf("%d", &arr[i].first);
		arr[i].second = i;
	}
	sort(arr, arr + n);
	for (int i = 0; i < n; ++i) {
		for (int j = 3; j <= 5 && i + j <= n; ++j) {
			bool flag = dp[i + j] > dp[i] + arr[i + j - 1].first - arr[i].first;
			if (flag) {
				par[i + j] = i;
				dp[i + j] = dp[i] + arr[i + j - 1].first - arr[i].first;
			}
		}
	}
	int cur = n;
	int cnt = 0;
	while (cur != 0)
	{
		for (int i = cur - 1; i >= par[cur]; i--)
			t[arr[i].second] = cnt;
		cnt++;
		cur = par[cur];
	}
	printf("%d %d\n", dp[n], cnt);
	for (int i = 0; i < n; ++i) {
		printf("%d ", cnt - t[i]);
	}
	//system("pause");
}
