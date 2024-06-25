import java.io.*;
import java.util.*;

public class Main {
    static final int MOD = 1000000007;
    static void readArray(int[] a, BufferedReader br) throws IOException {
        String[] input = br.readLine().split(" ");
        for (int i = 0; i < a.length; i++) {
            a[i] = Integer.parseInt(input[i]);
        }
    }
    static long binaryExpo(long base, long exponent, long mod) {
        long result = 1;
        base %= mod;
        while (exponent > 0) {
            if (exponent % 2 != 0) {
                result = (result * base) % mod;
            }
            base = (base * base) % mod;
            exponent /= 2;
        }
        return result;
    }
    static void solve(BufferedReader br) throws IOException {
        String[] input = br.readLine().split(" ");
        int n = Integer.parseInt(input[0]);
        int h = Integer.parseInt(input[1]);
        int k = Integer.parseInt(input[2]);
        int m = Integer.parseInt(input[3]);

        int[] a = new int[n];
        readArray(a, br);

        Map<Long, Integer> mp = new HashMap<>();
        for (int i = 0; i < n; i++) {
            long key = binaryExpo(a[i], h, m);
            mp.put(key, mp.getOrDefault(key, 0) + 1);
        }

        int request = 0;
        int available = 0;
        for (int i = 0; i < m; i++) {
            int count = mp.getOrDefault((long)i, 0);
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
