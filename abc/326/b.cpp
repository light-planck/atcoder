#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;

int main() {
  ll N;
  cin >> N;

  for (ll i = N; i < 1000; ++i) {
    string S = to_string(i);

    if ((S[0] - '0') * (S[1] - '0') == S[2] - '0') {
      cout << i << '\n';
      break;
    }
  }
}
