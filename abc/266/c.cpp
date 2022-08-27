#include <bits/stdc++.h>
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


struct Vector {
  ll x;
  ll y;
};


int main() {
  vector<Vector> vec(4);
  rep(i, 4) {
    cin >> vec[i].x;
    cin >> vec[i].y;
  }
  
  rep(i, 4) {
    ll j = (i + 1) % 4;
    ll k = (i - 1 + 4) % 4;
    ll l = (i + 2) % 4;

    Vector a;
    a.x = vec[j].x - vec[i].x;
    a.y = vec[j].y - vec[i].y;

    Vector b;
    b.x = vec[k].x - vec[i].x;
    b.y = vec[k].y - vec[i].y;

    Vector c;
    c.x = vec[l].x - vec[i].x;
    c.y = vec[l].y - vec[i].y;

    if ((c.x-a.x < b.x) or (c.y-a.y < b.y)) {
      cout << "No" << '\n';
      return 0;
    }
  }

  cout << "Yes" << '\n';
  return 0;
}