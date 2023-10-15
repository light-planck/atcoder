#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;

int main() {
  ll N, M;
  cin >> N >> M;

  string S;
  cin >> S;

  string T;
  cin >> T;

  if (T.starts_with(S) and T.ends_with(S))
    cout << 0 << '\n';
  else if (T.starts_with(S))
    cout << 1 << '\n';
  else if (T.ends_with(S))
    cout << 2 << '\n';
  else
    cout << 3 << '\n';
}
