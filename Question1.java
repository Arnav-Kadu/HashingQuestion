import java.io.*;
import java.util.*;

public class Main {
    static final long MOD = 1000000007;
    static long binaryExpo(long base, long exponent) {
        long result = 1;
        base %= MOD;
        while (exponent > 0) {
            if (exponent % 2 != 0) {
                result = (result * base) % MOD;
            }
            base = (base * base) % MOD;
            exponent /= 2;
        }
        return result;
    }
    static void solve(BufferedReader br) throws IOException {
        StringTokenizer st = new StringTokenizer(br.readLine());
        long n = Long.parseLong(st.nextToken());
        long h = Long.parseLong(st.nextToken());
        long k = Long.parseLong(st.nextToken());
        long m = Long.parseLong(st.nextToken());

        long[] a = new long[(int) n];
        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < n; i++) {
            a[i] = Long.parseLong(st.nextToken());
        }

        Map<Long, Long> mp = new HashMap<>();
        for (int i = 0; i < n; i++) {
            long key = binaryExpo(a[i], h) % m;
            mp.put(key, mp.getOrDefault(key, 0L) + 1);
        }

        long request = 0;
        long available = 0;
        for (long i = 0; i < m; i++) {
            long count = mp.getOrDefault(i, 0L);
            if (count <= k) {
                available += k - count;
            } else {
                request += count - k;
            }
        }

        if (available < request) {
            System.out.println(-1);
        } else {
            System.out.println(request);
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(br.readLine());
        while (t-- > 0) {
            solve(br);
        }
    }
}
