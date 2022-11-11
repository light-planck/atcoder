#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;


mt19937_64 engine(0);
uniform_int_distribution<> dist(0, INT_MAX);

int randint(int l, int r) {
    // return random integer in [l, r]
    return l + dist(engine) % (r - l + 1);
}


struct Timer {
    timespec start;

    void begin() {
        clock_gettime(CLOCK_REALTIME, &start);
    }

    double stopwatch() {
        timespec end;
        clock_gettime(CLOCK_REALTIME, &end);
        double sec = end.tv_sec - start.tv_sec;
        double nsec = end.tv_nsec - start.tv_nsec;
        return sec + 1e-9 * nsec;
    }
};


int main() {
  Timer timer;
  timer.begin();

  // ll ans = 1;
  // constexpr double time_limit = 1.9;
  // // double end_time = timer.stopwatch() + 0.9*(time_limit-timer.stopwatch());
  // while (timer.stopwatch() < time_limit) {
  //   ans *= 1;
  // }
  cout << randint(1, 10) << '\n';
  return 0;
}