#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
using ll = long long;

int main() {
  int n, m;
  cin >> n >> m;

  // mp<number, penal>
  map<int, int> mp;

  int ac = 0;
  int wa = 0;

  // ACした問題番号
  set<int> st;

  rep(i, m) {
    int p;
    string s;
    cin >> p >> s;

    // ACした問題はスキップ
    if (st.count(p)) continue;

    if (s == "WA") mp[p]++;
    else {
      wa += mp[p];
      st.insert(p);
    }
  }

  ac = st.size();
  cout << ac << " " << wa << endl;
  return 0;
}