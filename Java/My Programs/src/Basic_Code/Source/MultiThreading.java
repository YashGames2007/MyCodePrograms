package Basic_Code.Source;

class NewThread1 extends Thread {

    @Override
    public void run() {
        System.out.printf("\nHello Thread!");
        for (int i = 0; i < 100; i++) {
            System.out.printf("\nThread 1...");
        }

    }
}

class NewThread2 extends Thread {

    @Override
    public void run() {
        System.out.printf("\nHello Thread!");
        for (int i = 0; i < 100; i++) {
            System.out.printf("\nThread 2...");
        }

    }
}

class RunThread1 implements Runnable {
    public void run() {
        System.out.printf("\nHello Runnable!");
        for (int i = 0; i < 100; i++) {
            System.out.printf("\nRunnable Thread 1...");
        }
    }
}

class RunThread2 implements Runnable {
    public void run() {
        System.out.printf("\nHello Runnable!");
        for (int i = 0; i < 100; i++) {
            System.out.printf("\nRunnable Thread 2...");
        }
    }
}

// class RunnableThread1 extends Thread implements Runnable {

//     public void run() {
//         System.out.printf("\nHello Dynamic Runnable Thread");
//         for (int i = 0; i < 100; i++) {
//             System.out.printf("\nDynamic Thread 1...");
//         }
//     }
// }

// class RunnableThread2 extends Thread implements Runnable {

//     public void run() {
//         System.out.printf("\nHello Dynamic Runnable Thread");
//         for (int i = 0; i < 100; i++) {
//             System.out.printf("\nDynamic Thread 2...");
//         }
//     }
// }

public class MultiThreading {

    public static void main(String[] args) {

        NewThread1 thread1 = new NewThread1();
        NewThread2 thread2 = new NewThread2();

        RunThread1 runner1 = new RunThread1();
        RunThread2 runner2 = new RunThread2();

        Thread thread3 = new Thread(runner1);
        Thread thread4 = new Thread(runner2);

        // RunnableThread1 thread5 = new RunnableThread1();
        // RunnableThread2 thread6 = new RunnableThread2();

        thread1.start();
        thread2.start();
        thread3.start();
        thread4.start();
        // thread5.start();
        // thread6.start();
    }
}
