// Complexity of sieve ->  O(N * Log(LogN)) 

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vb = vector<bool>;
using vvb = vector<vb>;
using vi = vector<int>;
using vvi = vector<vi>;
using vl = vector<ll>;
using vvl = vector<vl>;
using vc = vector<char>;
using vvc = vector<vc>;
using vs = vector<string>;
const ll mod = 1e9 + 7,inf = 1e18;

#define pb push_back
#define fr(a,b) for(int i=0;i<b;i++)


const int N = 2e5;
// int sieve[N+1] -> max length can be 10^7
bool sieve[N+1]; // max length can be 10^8 

void computeSieve(int n = N) {
	for(int i=2;i<=n;i++) {
		sieve[i] = true;
	}

	// Complexity of this loop is O(n*Log(Logn))
	for(int i=2;i*i<=n;i++){
		if(sieve[i] == false) continue;
		
		for(int j=i*i;j<=n;j+=i){
			sieve[j] = false;
		}
	} 
}


vector<int> getPrimes(int n) {
	computeSieve(n);
	vector<int> primes;

	for(int i=2;i<=n;i++) 
		if(sieve[i] == true) primes.push_back(i);
	
	return primes;
}








