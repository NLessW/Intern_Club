import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int[] arr = new int[9];
        int sum = 0;
        
        for (int i = 0; i < 9; i++) {
            arr[i] = scanner.nextInt();
            sum += arr[i];
        }

        int height = sum - 100;
        int notD1 = 0;
        int notD2 = 0;

        for (int i = 0; i < 9; i++) {
            for (int j = i + 1; j < 9; j++) {
                if ((arr[i] + arr[j]) == height) {
                    notD1 = i;
                    notD2 = j;
                    break;
                }
            }
        }

        List<Integer> realDwarf = new ArrayList<>();
        for (int i = 0; i < 9; i++) {
            if (i != notD1 && i != notD2) {
                realDwarf.add(arr[i]);
            }
        }
        realDwarf.sort(null);

        for (int i = 0; i < 7; i++) {
            System.out.println(realDwarf.get(i));
        }

        scanner.close();
    }
}
