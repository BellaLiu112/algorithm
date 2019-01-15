#include <cstdio>
using namespace std;

int main(int argc, char *argv[])
{
    int N, S;
    //cin >> N >> S;
    scanf("%d  %d", &N, &S);    
    int P = 5000;
    long long costs = 0;
    for (int i = 0; i < N; ++i){
        int C, Y;
        //cin >> C >> Y;
        scanf("%d  %d", &C, &Y);
        P = P + S < C ? P+S : C;
        costs += P * Y;
    }
    //cout << costs << endl;
    printf("%d\n", costs);
    return 0;
}
