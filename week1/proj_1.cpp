#include <iostream>
#include <string>
#include <vector>
#include <numeric>
using namespace std;

int search_paint(vector<vector<int> > paint, vector<vector<int> > &wall, int n)
{
    int r, c;
    for (r = 1; r < n; ++r)
        for (c = 1; c < n+1; ++c)
            paint[r+1][c] = (wall[r][c] + paint[r][c] + paint[r][c-1] +
                             paint[r][c+1] + paint[r-1][c]) % 2;
    
    for (c = 1; c <n+1; ++c)
        if ((paint[n][c] + paint[n][c-1] + paint[n][c+1] + paint[n-1][c]) % 2 != wall[n][c])
            return -1;
    
    int count = 0;
    for (int i = 1; i < n+1; ++i)
        for (int j = 1; j < n+1; ++j)
            count += paint[i][j];
    
    return count;
}

int enumerate (vector<vector<int> > &paint, vector<vector<int> > &wall, int n)
{
    int c;
    int count = -1;
    int guess = search_paint(paint, wall, n);
    if (guess != -1)
        count = guess;
    
    while(true){
        paint[1][1]++;
        c = 1;
        while (paint[1][c] > 1) {
            paint[1][c] = 0;
            c++;
            paint[1][c]++;
        }
        guess = search_paint(paint, wall, n);
        if (count == -1) {
            count = guess;
        } else {
            if (guess != -1)
                count = min(count, guess);
        }
        int exit_code = accumulate(paint[1].begin(), paint[1].end(), 0);
        if (exit_code == n) {
            break;
        }
    }
    return count;
}

int main(int argc, const char *argv[])
{
    int t;
    cin >> t;
    
    for (int i = 0; i < t; ++i) {
        int n;
        cin >> n;
        vector<vector<int> > wall(n+1);
        vector<vector<int> > paint(n+1);
        
        for (int s = 0; s < wall.size();++s)
            wall[s].assign(n+2, 0);
        
        for (int s = 0; s < paint.size();++s)
            paint[s].assign(n+2, 0);
        
        for (int j = 1; j < n + 1; ++j) {
            string tmp;
            cin >> tmp;
            for (int k = 0; k < n; ++k)
                if (tmp[k] == 'w')
                    wall[j][k+1] = 1;
        }
        
        int paint_count = enumerate(paint, wall, n);
        if (paint_count == -1) cout << "inf" << endl;
        else cout << paint_count << endl;
    }
    
    return 0;
}

