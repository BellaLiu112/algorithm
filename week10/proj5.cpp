#include <iostream>
using namespace std;

/*
 S = P0 * N + 1;
 S = S - 1 - P0;
 S = P1 * N + 1;
 S = S - 1 - P1;
 
 P0 * N + 1 - 1 - P0  = P1 * N + 1;
 P0 * (N-1) = P1 * N + 1;
 
 P0 = (P1 * (N-1) + P1 + 1) / (N-1)
    = P1 + (P1 + 1) / (N-1)
 */

/*
 p1 = n-1-1;
 p1 > 0;
 p1 = 1;
 p0 = 3;
 s = 7;
 
 */

int main(int argc, const char *argv[])
{
    int n;
    while (cin >> n) {
        if (!n) break;
        int p = 1;
        for (int i = 0; i < n-1; ++i)
            p *= n-1;
        p--;
        if (p < 1) p = 1;
        for (int i = 0; i < n-1; ++i) {
            p += (p+1)/(n-1);
        }
        int s = p * n + 1;
        cout << s << endl;
    }
    return 0;
}
