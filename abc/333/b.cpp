#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;

int main() {
  string S;
  cin >> S;
  ranges::sort(S);

  string T;
  cin >> T;
  ranges::sort(T);

  ll d = min(S[1] - S[0], 5 - (S[1] - S[0])) % 5;
  ll e = min(T[1] - T[0], 5 - (T[1] - T[0])) % 5;

  if (d == e) {
    cout << "Yes" << '\n';
  } else {
    cout << "No" << '\n';
  }
}
