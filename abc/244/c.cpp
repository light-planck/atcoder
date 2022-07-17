#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
#define all(x) (x).begin(),(x).end()
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }


int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  int n;
  cin >> n;

  set<int> st;
  rep(i, 2*n + 1) st.insert(i + 1);

  while (true) {
    int taka = *begin(st);
    cout << taka << endl;
    st.erase(taka);

    int aoki;
    cin >> aoki;
    if (aoki == 0) break;
    st.erase(aoki);
  }
  return 0;
}