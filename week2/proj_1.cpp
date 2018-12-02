#include <iostream>
using namespace std;

#define MAX_N 30

int main(int argc, char *argv[])
{
    int n;
    int dp[MAX_N+1];
    
    dp[0] = 1;
        //奇数个方块永远不可能用domino拼起来
    for (int i = 1; i < MAX_N + 1; ++i)
        dp[i] = 0;
    
    dp[2] = 3;
    dp[4] = 11;
    
    int i = 6;
    for (; i <= MAX_N; ++i) {
        dp[i] = dp[i-2] * 3;
        int t = i-4;
        while (t >= 0) {
            dp[i] += dp[t] * 2;
            t -= 2;
        }
    }

    while (true) {
        cin >> n;
        if (n == -1)
            break;
        
        if (n % 2)
            cout << 0 << endl;
        else
            cout << dp[n] << endl;
    }
    return 0;
}

