
// Sieve of Eratosthenes
class Solution
{
public:
    int countPrimes(int n)
    {
        if (n <= 2)
            return 0;

        vector<bool> primes(n, true);
        primes[0] = false;
        primes[1] = false;

        for (int i = 2; i <= (int)sqrt(n); i++)
        {
            if (primes[i])
            {
                for (int j = i * 2; j < n; j += i)
                {
                    primes[j] = false;
                }
            }
        }

        int ans = 0;
        for (auto b : primes)
            ans += b ? 1 : 0;

        return ans;
    }
};