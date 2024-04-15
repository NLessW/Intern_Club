import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int a = scanner.nextInt();
        scanner.nextLine(); 

        String[] b = new String[a];
        String c = "";

        for (int i = 0; i < a; i++) {
            b[i] = scanner.nextLine();
        }

        int length = b[0].length();
        c = b[0];

        for (int i = 1; i < a; i++) {
            for (int j = 0; j < length; j++) {
                if (c.charAt(j) != '?' && c.charAt(j) != b[i].charAt(j)) {
                    char[] cArr = c.toCharArray();
                    cArr[j] = '?';
                    c = String.valueOf(cArr);
                }
            }
        }

        System.out.println(c);
        scanner.close();
    }
}
