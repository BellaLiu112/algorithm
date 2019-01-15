#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

const int MAXN = 10;
int n, k, cnt;
int book[MAXN];
char MAP[MAXN][MAXN];

void dfs(int x, int y){
    if(y >= k){
        cnt++;
        return;
    }
    if (x >= n)
        return;
    
    for(int i = x; i < n; i++){
        for(int j = 0; j < n; j++){
            if(MAP[i][j] == '#' && !book[j]){
                book[j] = 1;
                dfs(i+1, y+1);
                book[j] = 0;
            }
        }
    }
}

int main(){
    while(cin >> n >> k){
        if(n == -1 && k == -1)
            break;
        memset(book, 0, sizeof(book));
        for(int i = 0; i < n; i++)
            cin >>MAP[i];
        cnt = 0;
        dfs(0, 0);
        cout << cnt << endl;
    }
}

