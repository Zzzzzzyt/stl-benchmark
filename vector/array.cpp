#include <chrono>
#include <iostream>
#include <vector>

#include <unistd.h>

using namespace std;
using namespace chrono;

int a[100000001];

int main(int argc, char *argv[]) {
    if (argc < 2)
        return 0;
    register int n = atoi(argv[1]);

    steady_clock::time_point start, end;
    steady_clock::duration duration;

    start = steady_clock::now();
    for (int i = 0; i < n; i += 10) {
        a[i] = i;
        a[i + 1] = i + 1;
        a[i + 2] = i + 2;
        a[i + 3] = i + 3;
        a[i + 4] = i + 4;
        a[i + 5] = i + 5;
        a[i + 6] = i + 6;
        a[i + 7] = i + 7;
        a[i + 8] = i + 8;
        a[i + 9] = i + 9;
    }
    end = steady_clock::now();
    duration = duration_cast<nanoseconds>(end - start);
    cout << duration.count() << endl;

    register int x = 0;
    start = steady_clock::now();
    for (int i = 0; i < n; i += 10) {
        x += a[i];
        x += a[i + 1];
        x += a[i + 2];
        x += a[i + 3];
        x += a[i + 4];
        x += a[i + 5];
        x += a[i + 6];
        x += a[i + 7];
        x += a[i + 8];
        x += a[i + 9];
    }
    end = steady_clock::now();
    duration = duration_cast<nanoseconds>(end - start);
    cout << duration.count() << endl;

    start = steady_clock::now();
    for (int i = 0; i < n; i += 10) {
        a[i] = i;
        a[i + 1] = i + 1;
        a[i + 2] = i + 2;
        a[i + 3] = i + 3;
        a[i + 4] = i + 4;
        a[i + 5] = i + 5;
        a[i + 6] = i + 6;
        a[i + 7] = i + 7;
        a[i + 8] = i + 8;
        a[i + 9] = i + 9;
    }
    end = steady_clock::now();
    duration = duration_cast<nanoseconds>(end - start);
    cout << duration.count() << endl;

    start = steady_clock::now();
    for (int i = 0; i < n; i += 10) {
        x += a[i];
        x += a[i + 1];
        x += a[i + 2];
        x += a[i + 3];
        x += a[i + 4];
        x += a[i + 5];
        x += a[i + 6];
        x += a[i + 7];
        x += a[i + 8];
        x += a[i + 9];
    }
    end = steady_clock::now();
    duration = duration_cast<nanoseconds>(end - start);
    cout << duration.count() << endl;

    // ensure x isn't optimized away
    cerr << x << endl;

    return 0;
}