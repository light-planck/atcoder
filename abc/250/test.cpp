#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;


struct custom_hash {
  static ll splitmix64(ll x) {
    x += 0x9e3779b97f4a7c15;
    x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
    x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
    return x ^ (x >> 31);
  }

  ll operator() (ll x) const {
      static const ll FIXED_RANDOM =    
          chrono::steady_clock::now().time_since_epoch().count();
      return splitmix64(x + FIXED_RANDOM);
    }
} rng;


int main() {
  // vector<ll> a = {1, 2, 3};
  // vector<ll> b = {1, 2, 3};

  // vector<ll> hash_a(4);
  // rep(i, 3) {
  //   set<ll> st;
  //   if (st.count(a[i])) hash_a[i + 1] = hash_a[i];
  //   else {
  //     st.emplace(a[i]);
  //     hash_a[i + 1] = hash_a[i] ^ a[i];
  //   }
  // }

  // vector<ll> hash_b(4);
  // rep(i, 3) {
  //   set<ll> st;
  //   if (st.count(b[i])) hash_b[i + 1] = hash_b[i];
  //   else {
  //     st.emplace(b[i]);
  //     hash_a[i + 1] = hash_b[i] ^ b[i];
  //   }
  // }

  ll n = 3;
  auto hashing = [&]() {
    vector<ll> hash(n + 1);
    set<ll> st;

    rep(i, n) {
      ll x;
      cin >> x;

      if (st.count(x)) hash[i + 1] = hash[i];
      else {
        st.emplace(x);
        hash[i + 1] = hash[i];
      }
    }

    return hash;
  };

  auto hash_a = hashing();
  auto hash_b = hashing();

  if (hash_a[n] == hash_b[n]) cout << "Yes" << '\n';
  return 0;
}