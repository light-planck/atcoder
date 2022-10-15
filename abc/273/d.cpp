#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <deque>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <string>
#include <tuple>
#include <utility>
#include <vector>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;


void print() { cout << '\n'; }
template<class T> void print(const T& value) { cout << value << '\n'; }
template<class T, class... A> void print(const T& first, const A&... tail) { cout << first << " "; print(tail...); }
template<class... A> void print(const A&... tail) { print(tail...); }
template<class T> void print(vector<T>& vec) { for (const auto& a : vec) { cout << a << " "; } print(); }
template<class T> void print(vector<vector<T>>& vec2d) { for (auto& vec : vec2d) { print(vec); } }
void print(vector<string>& grid) { for (const auto& row : grid) print(row); }
template<class T, class U> void print(const map<T, U>& mp) { for (const auto& [x, y] : mp) { print(x, y); } }
template<class T> void print(set<T>& st) { for (const auto& a : st) { cout << a << " "; } print(); }
void print(vector<pair<ll, ll>>& vp) { for (auto [x, y] : vp) print(x, y); }


int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);


  ll h, w, i, j;
  cin >> h >> w >> i >> j;
  --i; --j;

  ll n;
  cin >> n;

  map<ll, set<ll>> i_wall;
  map<ll, set<ll>> j_wall;

  vector<string> grid(h, string(w, '.'));

  rep(i, n) {
    ll r, c;
    cin >> r >> c;
    --r; --c;
    i_wall[r].emplace(c);
    j_wall[c].emplace(r);
    grid[r][c] = '#';
  }
  grid[i][j] = 'T';

  ll q;
  cin >> q;

  // cout << "___________" << '\n';

  while (q--) {
    char d; ll l;
    cin >> d >> l;

    if (d == 'L') {
      if (i_wall[i].size() == 0) j = max(0LL, j-l);
      else {
        auto itr = i_wall[i].lower_bound(j);

        if (itr == i_wall[i].begin()) j = max(0LL, j-l);
        else {
          if (itr == j_wall[j].end()) --itr;
          i = max(i-l, *itr+1);
        }
      }
    }
    else if (d == 'R') {
      if (i_wall[i].size() == 0) j = min(w-1, j+l);
      else {
        auto itr = i_wall[i].lower_bound(j);

        if (itr == i_wall[i].end()) j = min(w-1, j+l);
        else j = min(j+l, *itr-1);
      }
    }

    else if (d == 'U') {
      if (j_wall[j].size() == 0) i = max(0LL, i-l);
      else {
        auto itr = j_wall[j].lower_bound(i);
        if (itr == j_wall[j].begin()) i = max(0LL, i+l);
        else {
          if (itr == j_wall[j].end()) --itr;
          i = max(i-l, *itr+1);
        }
      }
    }
    else if (d == 'D') {
      if (j_wall[j].size() == 0) i = min(h-1, i+l);
      else {
        auto itr = j_wall[j].lower_bound(i);
        if (itr == j_wall[j].end()) i = min(h-1, i+l);
        else i = min(i+l, *itr-1);
      }
    }

    i = max(0LL, i); i = min(h-1, i);
    j = max(0LL, j); j = min(w-1, j);

    cout << i+1 << " " << j+1 << '\n';
  }

  // print(grid);
  return 0;
}