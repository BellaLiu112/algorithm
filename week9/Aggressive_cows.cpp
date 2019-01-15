#include <algorithm>
#include <cstdio>
using namespace std;

int STALLS[100000];

bool check(int l, int c, int n){
    int i = 0, position = STALLS[0], _c = 1;
    while (i < n) {
        if (_c >= c)
            break;
        if (STALLS[i+1] >= position+l) {
            _c++;
            i++;
            position = STALLS[i];
        } else {
            i++;
        }
    }
    return _c >= c;
}

int main(int argc, const char *argv[])
{
    int N, C;
    scanf("%d %d\n", &N, &C);
    for (int i = 0; i < N; ++i)
        scanf("%d\n", &STALLS[i]);
    sort(STALLS, STALLS + N);
    
    int l, r;
    r = STALLS[N-1] - STALLS[0];
    l = r;
    for (int i = 0; i < N-1; ++i)
        if (STALLS[i+1] - STALLS[i] < l)
            l = STALLS[i+1] - STALLS[i];
    
    int mid;
    while (l <= r) {
        mid = (l+r) / 2;
        if (check(mid, C, N)) l = mid + 1;
        else r = mid - 1;
    }
    printf("%d\n", l-1);
    return 0;
}

