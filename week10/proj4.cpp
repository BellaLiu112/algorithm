#include <iostream>
using namespace std;

int sph[1001];

void fun()
{
    int minarea;
    int maxw, area;
    for (int v = 1; v <= 1000; ++v) {
        minarea = 1 << 30;
        for (int l = 1; l <= v; ++l) {
            if (!(v % l)) {
                maxw = v / l;
                for (int w = 1; w <= maxw; ++w) {
                    if (!(maxw % w)) {
                        int h = maxw / w;
                        area = (l * w + l*h + w*h) * 2;
                        minarea = minarea < area ? minarea : area;
                        sph[v] = minarea;
                    }
                }
            }
        }
        
    }
}

int main() {
    fun();
    int c;
    cin >> c;
    int i;
    while(c--) {
        cin >> i;
        cout << sph[i] << endl;
    }
    return 0;
}
