#include <iostream>
#include <stack>
#include <vector>
#include <cstring>
using namespace std;


int maze[5][5] = {
    0, 1, 0, 0, 0,
    0, 1, 0, 1, 0,
    0, 0, 0, 0, 0,
    0, 1, 1, 1, 0,
    0, 0, 0, 1, 0,
};

struct point_s {
    int r;
    int c;
    point_s *parent;
    point_s(){r=0; c=0; parent=0;}
    point_s(int row, int col, point_s *ptr){
        r = row;
        c = col;
        parent = ptr;
    }
} point_t;

vector<point_s *> queue;

int visited[32];

point_s*  bfs(  )
{
    int qhead = 0;
    int qtail = 1;
    queue.push_back(new point_s(0, 0, 0));
    while (qhead != qtail) {
        point_s *current = queue[qhead++];
        if (current->r == 4 && current->c == 4)
            break;
        visited[current->r * 5 + current->c] = 1;
        // move right
        if (current->c != 4)
            if (!visited[current->r * 5 + current->c + 1] && (!maze[current->r][current->c + 1])){
                queue.push_back(new point_s(current->r, current->c + 1, current));
                qtail++;
            }
        // move down
        if (current->r != 4)
            if (!visited[(current->r + 1)  * 5 + current->c] && (!maze[current->r + 1][current->c])){
                queue.push_back(new point_s(current->r+1, current->c, current));
                qtail++;
            }
        // move up
        if (current->r)
            if (!visited[(current->r - 1)  * 5 + current->c] && (!maze[current->r - 1][current->c])){
                queue.push_back(new point_s(current->r-1, current->c, current));
                qtail++;
            }
        // move left
        if (current->c)
            if (!visited[current->r * 5 + current->c - 1] && (!maze[current->r][current->c - 1])){
                queue.push_back(new point_s(current->r, current->c - 1, current));
                qtail++;
            }
    }
    return queue[--qhead];
}

void print_path(point_s *ptr)
{
    stack<point_s *> path;
    while (ptr) {
        path.push(ptr);
        ptr = ptr->parent;
    }
    while (!path.empty()) {
        point_s *current  = path.top();
        cout << "(" <<  current->r << "," << " " << current->c << ")" << endl;
        path.pop();
    }
}



int main(int argc, const char *argv[])
{
    memset(visited, 0, sizeof(visited));
    point_s *ptr = bfs();
    print_path(ptr);
    return 0;
}
