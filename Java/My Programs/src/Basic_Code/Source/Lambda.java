package Basic_Code.Source;

interface Prime {
    boolean isPrime(int n);
}

interface Number {
    boolean isOdd(int n);
    boolean isEven(int n);
}

public class Lambda {
    public static void main(String[] args) {
        System.out.printf("\nHello World!");

        Prime check = (n) -> {
            if (n <= 1) {
                return false;
            } else if (n == 2 || n == 3) {
                return true;
            } else if (n % 2 == 0) {
                return false;
            } else {
                for (int i = 3; i < ((n / 2) - 1); i += 2) {
                    for (int j = 3; (i * j) <= n; j += 2) {
                        // System.out.printf("\n%d X %d = %d", i, j, (i * j));
                        if ((i * j) == n) {
                            // System.out.printf("\nCount: %d", count);
                            return false;
                        }
                    }
                }
                // System.out.printf("\nCount: %d", count);
            }
            return true;
        };

        int num = 232;
        System.out.printf("\nThe Number %d is ", num);
        if (check.isPrime(num)) {
            System.out.printf("Prime Number.");
        } else {
            System.out.printf("not a Prime Number.");
        }
        // for (int i = 2; i < 20; i++) {
        // System.out.printf("\n%d: %b", i, check.isPrime(i));
        // }

        Number checkNumber = new Number() {
            @Override
            public boolean isOdd(int n) {
                return (n % 2) != 0;
            }

            @Override
            public boolean isEven(int n) {
                return (n % 2) == 0;
            }
        };

        System.out.printf("\nThe Number %d is an ", num);
        if (checkNumber.isEven(num)) {
            System.out.printf("Even Number.");
        } else if (checkNumber.isOdd(num)) {
            System.out.printf("Odd Number.");
        }
    }
}
