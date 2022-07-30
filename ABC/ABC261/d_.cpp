#include <bits/stdc++.h>
using namespace std;

long long x[5001];
long long b[5001], dp[5001][5001];
int main(void) {
	int n, m;
	long long c, y;
	long long ans;
	for (int i = 0; i <= n; i++)b[i] = 0;

	cin >> n >> m;
	for (int i = 0; i < n; i++)cin >> x[i + 1];
	for (int i = 0; i < m; i++) {
		cin >> c >> y;
		b[c] = y;
	}

	dp[0][0] = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) dp[i][j] = dp[i - 1][j - 1] + x[i] + b[j];

		dp[i][0] = 0;
		for (int j = 0; j < i; j++)dp[i][0] = max(dp[i][0], dp[i - 1][j]);
	}

	ans = 0;
	for (int i = 0; i <= n; i++)ans = max(ans, dp[n][i]);
	cout << ans << endl;

	return 0;
}
