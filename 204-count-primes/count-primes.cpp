class Solution {
public:
    int countPrimes(int n) {
        if (n <= 2)
            return 0;

        vector<bool> prime(n, true);

        prime[0] = prime[1] = false;

        for (int i = 4; i < n; i += 2) {
            prime[i] = false;
        }

        for (int i = 3; 1LL * i * i < n; i += 2) {
            if (prime[i]) {
                for (long long j = 1LL * i * i; j < n; j += 2LL * i) {
                    prime[j] = false;
                }
            }
        }

        int cnt = 1;  // prime number 2

        for (int i = 3; i < n; i += 2) {
            if (prime[i])
                cnt++;
        }

        return cnt;
    }
};