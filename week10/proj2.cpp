#include <iostream>
using namespace std;

int main(int argc, const char *argv[])
{
    int M, N;
    
    while (cin >> M >> N) {
        if (M < N) {
            int tmp = M;
            M = N;
            N = tmp;
        }
        int t = M % N;
        while (t) {
            M = N;
            N = t;
            t = M % N;
        }
        cout << N << endl;
    }
    return 0;
}

