package Basic_Code.Source;

class Number extends Thread {

    private long number;
    private boolean isPrime;
    private boolean isChecked;

    public Number(long number) {
        this.number = number;
        this.isPrime = false;
        this.isChecked = false;
    }

    @Override
    public void run() {
        if (!isChecked) {

            if (number <= 1) {
                isPrime = false;

            } else if (number == 2) {
                isPrime = true;

            } else if (number % 2 == 0) {
                isPrime = false;

            } else {
                long multiple = number / 3;

                if (multiple % 2 == 0) {
                    multiple--;
                }

                isPrime = true;
                while (multiple != 1) {

                    for (int factor = 3; (multiple * factor) <= number; factor += 2) {

                        if ((multiple * factor) == number) {
                            isPrime = false;
                            break;
                        }
                    }
                    if (isPrime == false) {
                        break;
                    }
                    multiple -= 2;
                }
            }
            isChecked = true;
            System.out.printf("\n%d::%b", number, isPrime);
        }
    }

    public long getNumber() {
        return number;
    }

    public boolean isPrime() {
        return isPrime;
    }

    public boolean isChecked() {
        return isChecked;
    }

    public void changeNumber(long number) {
        this.number = number;
    }
}

public class ThreadExperiment {

    public static void main(String[] args) {

        System.out.printf("\nHello World!");

        // int start, end;
        // start = 1;
        // end = 100;

        // Number []numbers = new Number[end - start + 1];

        // for (int index = 0, current = start; current < end; index++, current++) {
        // numbers[index] = new Number(current);
        // numbers[index].run();
        // }

        int start = 1;
        int end = 100;
        int primes = 0;

        for (int current = start; current < end; current++) {
            {
                Number number = new Number(current);
                number.start();

                while (number.isChecked()) {
                }

                if (number.isPrime()) {
                    primes++;
                }
                number = null;
            }

        }
        while (Thread.activeCount() != 1) {}

        System.out.printf("\nTotal: %d", primes);
    }
}