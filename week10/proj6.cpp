#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

int maze[201][201];

struct point_s {
    int r;
    int c;
    int time;
    point_s(){r=0; c=0; time=0;}
    point_s(int _r, int _c, int _t){
        r = _r;
        c = _c;
        time = _t;
    }
} point_t;

vector<point_s *> queue;
int visited[201][201];

void release_queue()
{
    size_t ll = queue.size();
    for (int i = 0; i < ll; ++i)
        delete queue[i];
    queue.clear();
}

int dfs(int s_r, int s_c, int e_r, int e_c, int r, int c)
{
    release_queue();
    int qhead = 0;
    int qtail = 1;
    queue.push_back(new point_s(s_r, s_c, 0));
    visited[s_r][s_c] = 1;
    bool success = false;
    while (qhead != qtail) {
        point_s *current = queue[qhead];
        if (current->r == e_r && current->c == e_c){
            success = true;
            break;
        }
        //move right
        if (current->c != c) {
            if (!maze[current->r][current->c+1] && !visited[current->r][current->c+1]) {
                queue.push_back(new point_s(current->r, current->c+1, current->time+1));
                visited[current->r][current->c+1] = 1;
                qtail++;
            }
        }
        //move down
        if (current->r != r) {
            if ((!maze[current->r+1][current->c]) && (!visited[current->r+1][current->c]) ) {
                queue.push_back(new point_s(current->r+1, current->c, current->time+1));
                visited[current->r+1][current->c] = 1;
                qtail++;
            }
        }
        //move left
        if (current->c != 1) {
            if (!maze[current->r][current->c-1] && !visited[current->r][current->c-1] ) {
                queue.push_back(new point_s(current->r, current->c-1, current->time+1));
                visited[current->r][current->c-1] = 1;
                qtail++;
            }
        }
        //move up
        if (current->r != 1) {
            if (!maze[current->r-1][current->c] && !visited[current->r-1][current->c]) {
                queue.push_back(new point_s(current->r-1, current->c, current->time+1));
                visited[current->r-1][current->c] = 1;
                qtail++;
            }
        }
        qhead++;
    }
    int ret;
    if (success) {
        ret = queue[qhead]->time;
    } else {
        ret = -1;
    }
    return ret;
}

int main(int argc, const char *argv[])
{
    
    int n;
    int r, c;
    cin >> n;
    int s_r, s_c, e_r, e_c;
    char buff[201];
    for (int i = 0; i < n; ++i) {
        memset(maze, 0, sizeof(maze));
        memset(visited, 0, sizeof(visited));
        cin >> r >> c;
        // 输入maze
        for (int j = 1; j < r+1; ++j) {
            cin >> buff;
            for (int k = 1; k < c+1; ++k) {
                if (buff[k-1] == '#') {
                    maze[j][k] = 1;
                } else if (buff[k-1] == 'S'){
                    s_r = j;
                    s_c = k;
                } else if (buff[k-1] == 'E'){
                    e_r = j;
                    e_c = k;
                } else {
                    continue;
                }
            }
        }
        int time = dfs(s_r, s_c, e_r, e_c, r, c);
        if (time != -1) {
            cout << time << endl;
        } else {
            cout << "oop!" << endl;
        }
    }
    release_queue();
    return 0;
}
