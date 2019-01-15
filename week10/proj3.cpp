#include <iostream>
#include <cstring>
using namespace std;

int dp[50+1][50+1];

int main(int argc, const char *argv[])
{
    memset(dp, 0, sizeof(dp));
    int N, min;
    cin >> N;
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= i; ++j) {
            if (j == 1) {
                dp[i][j] = 1;
                continue;
            }
            if (i == j) {
                dp[i][j] = dp[i][j-1] + 1;
                continue;
            }
            min = i-j < j ? i-j : j;
            dp[i][j] = dp[i][j-1] + dp[i-j][min];
        }
    }
    cout << dp[N][N] << endl;
    return 0;
}
