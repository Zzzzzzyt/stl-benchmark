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

    // v.reserve(n);

    start = steady_clock::now();
    for (int i = 0; i < n; i += 10) {
        v.insert(v.begin(), i);
        v.insert(v.begin(), i + 1);
        v.insert(v.begin(), i + 2);
        v.insert(v.begin(), i + 3);
        v.insert(v.begin(), i + 4);
        v.insert(v.begin(), i + 5);
        v.insert(v.begin(), i + 6);
        v.insert(v.begin(), i + 7);
        v.insert(v.begin(), i + 8);
        v.insert(v.begin(), i + 9);
    }
    end = steady_clock::now();
    duration = duration_cast<nanoseconds>(end - start);
    cout << duration.count() << endl;

    start = steady_clock::now();
    for (int i = 0; i < n; i += 10) {
        v.erase(v.begin());
        v.erase(v.begin());
        v.erase(v.begin());
        v.erase(v.begin());
        v.erase(v.begin());
        v.erase(v.begin());
        v.erase(v.begin());
        v.erase(v.begin());
        v.erase(v.begin());
        v.erase(v.begin());
    }
    end = steady_clock::now();
    duration = duration_cast<nanoseconds>(end - start);
    cout << duration.count() << endl;

    return 0;
}