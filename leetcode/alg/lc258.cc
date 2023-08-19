// leetcode 258
// Add Digits

class Solution
{
public:
    int next(int x)
    {
        int y = 0;
        while (x)
        {
            y += x % 10;
            x /= 10;
        }
        return y;
    }

    int addDigits(int num)
    {
        if (num < 9)
            return num;

        while (num > 9)
            num = next(num);

        return num;
    }
};

class Solution
{
public:
    int addDigits(int num)
    {
        int n = num;
        
        // round 代表当前轮次的各个数位的和
        // 初始化为0
        int round = 0;

    ONCE:
        while (n > 0)
        {
            int t = n % 10;
            n /= 10;
            round += t;
        }
        // 这里代表当前的n已经被处理完了
        // 如果round >= 10
        // 证明各个数位的和还需要在处理

        if (round >= 10)
        {
            n = round;
            // 注意reset round
            round = 0;
            goto ONCE;
        }

        return round;
    }
};