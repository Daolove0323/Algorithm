#include <iostream>
#include <algorithm>
#include <vector>
#include <memory.h>
#include <string>
#include <queue>
#include <set>
using namespace std;
typedef long long ll;
ll n, k,c;
multiset<ll> bag;
pair<ll, ll> p[300001];
int cmp(pair<ll, ll> a, pair<ll, ll> b) {
	if (a.second == b.second) {
		return a.first < b.first;
	}
	return a.second > b.second;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> k;
	for (ll i = 0; i < n; i++) {
		cin >> p[i].first >> p[i].second;
	}
	for (ll i = 0; i < k; i++) {
		ll num;
		cin >> num;
		bag.insert(num);
	}
	sort(p, p + n,cmp);
	ll ans = 0;
	ll _size = k;
	for (ll i = 0; i < n; i++) {
		auto it = bag.lower_bound(p[i].first);
		if (it != bag.end()) {
			ans += p[i].second;
			auto nxt = it;
			nxt++;
			bag.erase(it, nxt);
		}
	}
	cout << ans;
}