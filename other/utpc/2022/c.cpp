#include<bits/stdc++.h>
using namespace std;

#define all(v) v.begin(),v.end()
using ll = long long;
using ull = unsigned long long;
using vll=vector<ll>;
using vvll = vector<vector<ll>>;
const ll INF=1ll<<60;
using P = pair<double,double>;



int main(){
    ll N;
    cin>>N;
    double ans=10000000;
    vector<P> A(N);
    for(int i=0;i<N;i++){
        cin>>A[i].first>>A[i].second;
    }
    sort(all(A));
    for(int i=0;i<N;i++){
        set<double> st;
        for(int j=0;j<i;j++) st.insert(A[j].second);
        for(int j=N-1;j>i;j--){
            // double x1=A[i].first,x2=A[j].first;
            
            st.insert(A[j].second);
        }
    }
    cout << fixed<<setprecision(10)<<ans << endl;
}