#include <iostream>
#include <algorithm>
#include <set>
using namespace std;


struct point {
    int m_x;
    int m_y;
    int m_height;
    point( ) { }
    point(int x, int y,  int height):m_x(x), m_y(y), m_height(height){ }
} A;


struct  point_comp{
    bool operator()(const point &a, const point &b){
        return a.m_height < b.m_height;
    }
} my_object;

int main(int argc, char *argv[])
{
    int r, c;
    cin >> r >> c;

    multiset<point, point_comp> height;
    int L[20000];
    int points[101][101];
   
    int num = r * c;
    int tmp_h;
    for (int i = 1; i <= r; ++i) {
        for (int j = 1; j <= c; ++j) {
            cin >> tmp_h;
            height.insert(point(i, j, tmp_h));
            points[i][j] = tmp_h;
        }
    }
    
    fill(L, L+num, 1);
    
    for (int i = 0; i < c+2; ++i){
        points[0][i] = 0;
        L[i] = 0;
    }
    for (int i = 0; i < c+2; ++i){
        points[r+1][i] = 0;
        int tmp = (c+2) * (r+1);
        L[tmp+i] = 0;
    }
    
    for (int i = 0; i < r+1; ++i){
        points[i][0] = 0;
        L[i*(c+2)] = 0;
    }
    
    for (int i = 0; i < r+1; ++i){
        points[i][c+1] = 0;
        L[i*(c+2) + c+1] = 0;
    }
    
    multiset<point>::iterator it;
    
    for (it = height.begin(); it != height.end() ; ++it) {
        int x = it->m_x;
        int y = it->m_y;
        
        int tmp[4];
        tmp[0] = L[(x-1)*(c+2) + y + 1];
        tmp[1] = L[(x+1)*(c+2) + y + 1];
        tmp[2] = L[x*(c+2) + y - 1];
        tmp[3] = L[x*(c+2) + y + 1];
        
        int _max = *max_element(tmp, tmp+4);
        L[x*(c+2) + y] = _max+1;
    }
    
    int max_len = *max_element(L+c+2, L+ (c+2)*(r+2));
    cout << max_len << endl;
    return 0;
}

