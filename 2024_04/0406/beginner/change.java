import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int defaultMoney = 1000;
        int changesMoney = 0;
        int count = 0;
        int i = 0;
        int[] coin = {500, 100, 50, 10, 5, 1};

        changesMoney = scanner.nextInt();
        defaultMoney -= changesMoney;

        while (defaultMoney > 0) {
            if (defaultMoney >= coin[i]) {
                defaultMoney -= coin[i];
                count++;
            } else {
                i++;
            }
        }

        System.out.println(count);
        scanner.close();
    }
}
