class Solution {
    public int longestBalanced(String s) {
        return Math.max(solve(s), solve(new StringBuilder().append(s).reverse().toString()));
    }

    public int solve(String s) {
        int n = s.length();
        int zero = 0;
        int one = 0;

        for (char c : s.toCharArray())
            if (c == '0')
                zero++;
            else
                one++;

        if (zero == one)
            return n;

        Map<Integer, Integer> map = new HashMap<>();
        map.put(0, 0);

        int ans = 0;
        int prefSum = 0;

        for (int r = 1; r <= n; r++) {
            prefSum += s.charAt(r - 1) == '1' ? 1 : -1;

            if (map.containsKey(prefSum))
                ans = Math.max(ans, r - map.get(prefSum));

            if (map.containsKey(prefSum - 2)) {
                int len = r - map.get(prefSum - 2);
                if (len % 2 == 0 && len / 2 <= zero)
                    ans = Math.max(ans, len);
            }

            if (map.containsKey(prefSum + 2)) {
                int len = r - map.get(prefSum + 2);
                if (len % 2 == 0 && len / 2 <= one)
                    ans = Math.max(ans, len);
            }

            map.putIfAbsent(prefSum, r);
        }

        return ans;
    }
}