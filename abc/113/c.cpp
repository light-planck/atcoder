#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); i++)
using namespace std;
using ll = long long;
using P = pair<ll, ll>;


int main() {
  ll n, m;
  cin >> n >> m;

  vector<pair<ll, ll>> py;
  rep(i, m) {
    ll p, y;
    cin >> p >> y;
    py.emplace_back(p, y);
  }

  // years[i]:県iに属する市が誕生した年の配列
  unordered_map<ll, vector<ll>> years;
  for (auto [p, y] : py) {
    years[p].emplace_back(y);
  }

  // 市の誕生年を昇順にソート
  for (auto& [p, vec] : years) {
    sort(vec.begin(), vec.end());
  }

  // 認識番号を作成
  for (auto [p, y] : py) {
    // 認識番号 = 県番号 + 市が何番目に誕生したか

    // 県番号
    string p_id = to_string(p);
    // 6桁未満は0で埋める
    ll padding_size = 6 - p_id.size();
    p_id = string(padding_size, '0') + p_id;

    // 何番目に誕生したか市か二分探索で求める
    ll idx = lower_bound(years[p].begin(), years[p].end(), y) - years[p].begin();
    string y_id = to_string(idx + 1);
    // 6桁未満は0で埋める
    padding_size = 6 - y_id.size();
    y_id = string(padding_size, '0') + y_id;

    // 認識番号を出力
    cout << p_id << y_id << '\n';
  }
}