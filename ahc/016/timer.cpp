#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;


// struct Timer {
//     timespec start;

//     void begin() {
//       clock_gettime(CLOCK_REALTIME, &start);
//     }

//     double stopwatch() {
//       timespec end;
//       clock_gettime(CLOCK_REALTIME, &end);
//       double sec = end.tv_sec - start.tv_sec;
//       double nsec = end.tv_nsec - start.tv_nsec;
//       return sec + 1e-9 * nsec;
//     }
// };


using namespace std::chrono;
struct Timer {
  high_resolution_clock::time_point start;

  void begin() {
    start = high_resolution_clock::now();
  }

  double now() {
    return duration_cast<milliseconds>(high_resolution_clock::now() - start).count() / 1000.0;
  }
};


int main() {
  Timer timer;
  timer.begin();

  ll ans = 1;
  constexpr double time_limit = 1.99;
  while (timer.now() < time_limit) {
    ans *= 1;
  }
  return 0;
}