package ex2.q2;

import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;

class Counter implements Runnable {
    private static int counter = 10000;
    private static final int limit = 100000;
    private static final int nbThread = 2;
    private static final Object lock = new Object();

    public static void main(String[] args) {
        ExecutorService executorService = Executors.newFixedThreadPool(nbThread);
        for (int i = 0; i < nbThread; i++) {
            executorService.submit(new Counter());
        }
        executorService.shutdown();
    }

    @Override
    public void run() {
        while (counter < limit) {
            increaseCounter();
        }
    }

    private void increaseCounter() {
        synchronized (lock) {
            System.out.println(Thread.currentThread().getName() + " : " + counter);
            counter++;
        }
    }
}