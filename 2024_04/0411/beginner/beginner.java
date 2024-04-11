import java.util.Scanner;
import java.util.ArrayList;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt();
        int M = scanner.nextInt();
        ArrayList<Integer> li = new ArrayList<>();

        for (int i = 0; i < M; ++i) {
            li.add(scanner.nextInt());
        }

        int res = 0;
        for (int i = 1; i <= N; ++i) {
            for (int j = 0; j < M; ++j) {
                if (i % li.get(j) == 0) {
                    res += i;
                    break;
                }
            }
        }

        System.out.println(res);
        scanner.close();
    }
}
