import java.util.*;
import java.lang.*;
import java.io.*;

class Main {
    public static void main(String[] args) {
        int fact=1;
        Scanner scanner = new Scanner(System.in);
        int a = scanner.nextInt();

        for(int i=1;i<=a;i++)
            fact*=i;
        System.out.print(fact);
    }
}
