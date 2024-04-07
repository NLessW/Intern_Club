import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int count = 0;
        int[] a1 = new int[26];
        int[] b1 = new int[26];

        String a2 = scanner.next();
        String b2 = scanner.next();

        for (char c : a2.toCharArray()) {
            if (c >= 'a' && c <= 'z') {
                a1[c - 'a']++;
            }
        }

        for (char c : b2.toCharArray()) {
            if (c >= 'a' && c <= 'z') {
                b1[c - 'a']++;
            }
        }

        for (int i = 0; i < 26; i++) {
            count += Math.abs(a1[i] - b1[i]);
        }

        System.out.println(count);
        scanner.close();
    }
}
