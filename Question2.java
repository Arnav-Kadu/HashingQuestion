import java.util.*;

public class Main {
    static final int base1 = 304933, base2 = 4395853;
    static final int p1 = 1000000007, p2 = 1000000009;
    static int[] pow1 = new int[1010], pow2 = new int[1010];

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        pow1[0] = pow2[0] = 1;
        for (int i = 1; i < 1010; ++i) {
            pow1[i] = (int) ((long) pow1[i - 1] * base1 % p1);
            pow2[i] = (int) ((long) pow2[i - 1] * base2 % p2);
        }

        int t = sc.nextInt();
        while (t-- > 0) {
            solve(sc);
        }
        sc.close();
    }

    static void solve(Scanner sc) {
        int n = sc.nextInt();
        int[] a = new int[1010];
        Map<Pair, Integer> m = new HashMap<>();
        List<Map<Pair, Integer>> checker = new ArrayList<>(Collections.nCopies(1010, null));
        for (int i = 0; i < 1010; ++i) {
            checker.set(i, new HashMap<>());
        }

        for (int i = 0; i < n; i++) {
            int x = sc.nextInt();
            int y = sc.nextInt();
            if (x > y) {
                int temp = x;
                x = y;
                y = temp;
            }
            Pair p = new Pair(x, y);
            m.putIfAbsent(p, m.size());
            a[i] = m.get(p);
        }

        int ans = 0;
        for (int i = 0; i < n; ++i) {
            long hsh1 = 0, hsh2 = 0;
            for (int j = i; j < n; ++j) {
                hsh1 = (hsh1 + pow1[a[j]]) % p1;
                hsh2 = (hsh2 + pow2[a[j]]) % p2;
                Pair hshPair = new Pair((int) hsh1, (int) hsh2);
                ans += checker.get(j - i).getOrDefault(hshPair, 0);
                checker.get(j - i).put(hshPair, checker.get(j - i).getOrDefault(hshPair, 0) + 1);
            }
        }
        System.out.println(ans);
    }
}

class Pair {
    int x, y;

    Pair(int x, int y) {
        this.x = x;
        this.y = y;
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (o == null || getClass() != o.getClass()) return false;
        Pair pair = (Pair) o;
        return x == pair.x && y == pair.y;
    }

    @Override
    public int hashCode() {
        return Objects.hash(x, y);
    }
}
