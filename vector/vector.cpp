#include <chrono>
#include <iostream>
#include <vector>

using namespace std;
using namespace chrono;

vector<int> v;

int main(int argc, char *argv[]) {
    if (argc < 2)
        return 0;
    register int n = atoi(argv[1]);

    steady_clock::time_point start, end;
    steady_clock::duration duration;

    start = steady_clock::now();
    for (int i = 0; i < n; i += 10) {
        v.push_back(i);
        v.push_back(i + 1);
        v.push_back(i + 2);
        v.push_back(i + 3);
        v.push_back(i + 4);
        v.push_back(i + 5);
        v.push_back(i + 6);
        v.push_back(i + 7);
        v.push_back(i + 8);
        v.push_back(i + 9);
    }
    end = steady_clock::now();
    duration = duration_cast<nanoseconds>(end - start);
    cout << duration.count() << endl;

    start = steady_clock::now();
    for (int i = 0; i < n; i += 10) {
        v[i] = i;
        v[i + 1] = i + 1;
        v[i + 2] = i + 2;
        v[i + 3] = i + 3;
        v[i + 4] = i + 4;
        v[i + 5] = i + 5;
        v[i + 6] = i + 6;
        v[i + 7] = i + 7;
        v[i + 8] = i + 8;
        v[i + 9] = i + 9;
    }
    end = steady_clock::now();
    duration = duration_cast<nanoseconds>(end - start);
    cout << duration.count() << endl;

    register int x = 0;
    start = steady_clock::now();
    for (int i = 0; i < n; i += 10) {
        x += v[i];
        x += v[i + 1];
        x += v[i + 2];
        x += v[i + 3];
        x += v[i + 4];
        x += v[i + 5];
        x += v[i + 6];
        x += v[i + 7];
        x += v[i + 8];
        x += v[i + 9];
    }
    end = steady_clock::now();
    duration = duration_cast<nanoseconds>(end - start);
    cout << duration.count() << endl;

    // ensure x isn't optimized away
    cerr << x << endl;

    return 0;
}