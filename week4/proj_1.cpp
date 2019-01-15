#include <iostream>
#include <set>
#include <cstring>
using namespace std;

int A[10001];
int B[10001];
int pq_num[10001];


void cal_pq(int s, int a, multiset<int> &B)
// i是A数组的第i+1个元素, A, B放在multiset中
{
    if (pq_num[a] == -1){
        int b_tmp = s - a;
        int n = B.count(b_tmp);
        pq_num[a] = n;
    }
}

int main(int argc, char *argv[])
{
    int n;
    cin >> n;
    while (n--) {
        int s;
        cin >> s;
        int a_num, b_num;
        int A[10000];
        multiset<int> B;
        cin >> a_num;
        for (int i = 0; i < a_num; ++i)
            cin >> A[i];
        cin >> b_num;
        for (int i = 0; i < b_num; ++i) {
            int b_tmp;
            cin >> b_tmp;
            B.insert(b_tmp);
        }
        memset(pq_num, -1, sizeof(pq_num));
        for (int i = 0; i < a_num; ++i) {
            cal_pq(s, A[i], B);
        }
        int n_pairs = 0;
        for (int i = 0; i < a_num; ++i)
            n_pairs += pq_num[A[i]];
        cout << n_pairs << endl;
    }
    
    return 0;
}

