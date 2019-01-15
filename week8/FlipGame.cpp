#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int pieces[6][6];
int pieces_copy[6][6];

void press_button(int r, int c)
{
    pieces[r][c] = 1 - pieces[r][c];
    pieces[r+1][c] = 1 - pieces[r+1][c];
    pieces[r-1][c] = 1 - pieces[r-1][c];
    pieces[r][c-1] = 1 - pieces[r][c-1];
    pieces[r][c+1] = 1 - pieces[r][c+1];
}

int press_from_second_row(int row, int col, int goal)
{
    int n = 0;
    for (int i = 2; i <= row; ++i)
        for (int j = 1; j <= col; ++j)
            if (pieces[i-1][j] != goal){
                press_button(i, j);
                n++;
            }
    return n;
}

int main(int argc, const char *argv[])
{
    memset(pieces, 0, sizeof(pieces));
    
    char buff[5];
    memset(buff, 0, sizeof(buff));
    for (int i = 0; i < 4; ++i){
        cin >> buff;
        for (int j = 0; j < 4; ++j) {
            if (buff[j] == 'b')
                pieces[i+1][j+1] = 0;
            else
                pieces[i+1][j+1] = 1;
        }
    }
    memcpy(pieces_copy, pieces, sizeof(pieces));
    int min_n = 1 << 30;
    int black;
    int white;
    for (int i = 0; i < 16; ++i) {
        black = 0;
        memcpy(pieces, pieces_copy, sizeof(pieces));
        if (i & 1) {press_button(1, 1); ++black;}
        if (i & 2) {press_button(1, 2); ++black;}
        if (i & 4) {press_button(1, 3); ++black;}
        if (i & 8) {press_button(1, 4); ++black;}
        black += press_from_second_row(4, 4, 0);
        
        if (black > min_n)
            continue;
        
        bool sucess = true;
        for (int i = 1; i <= 4; ++i) {
            if (pieces[4][i]) {
                sucess = false;
                break;
            }
        }
        if (sucess)
            min_n = min(min_n, black);
    }
    
    for (int i = 0; i < 16; ++i) {
        white = 0;
        memcpy(pieces, pieces_copy, sizeof(pieces));
        if (i & 1) {press_button(1, 1); ++white;}
        if (i & 2) {press_button(1, 2); ++white;}
        if (i & 4) {press_button(1, 3); ++white;}
        if (i & 8) {press_button(1, 4); ++white;}
        white += press_from_second_row(4, 4, 1);
        
        if (white > min_n)
            continue;
        
        bool sucess = true;
        for (int i = 1; i <= 4; ++i) {
            if (!pieces[4][i]) {
                sucess = false;
                break;
            }
        }
        if (sucess)
            min_n = min(min_n, white);
        
    }
    if (min_n < 1 << 30) cout << min_n << endl;
    else    cout << "Impossible" << endl;
    
    return 0;
}

