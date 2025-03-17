class PrintNumbers {
    private static int counter = 1;
    private static final int MAX = 8;

    private static final Object lock = new Object();

    static class EvenThread extends Thread {
        public void run() {
            while (counter <= MAX) {
                synchronized (lock) {
                    if (counter % 2 == 0) {
                        System.out.print(counter + " ");
                        counter++;
                    }
                    lock.notify();
                    try {
                        if (counter <= MAX) {
                            lock.wait();
                        }
                    } catch (InterruptedException e) {
                        e.printStackTrace();
                    }
                }
            }
        }
    }

    static class OddThread extends Thread {
        public void run() {
            while (counter <= MAX) {
                synchronized (lock) {
                    if (counter % 2 != 0) {
                        System.out.print(counter + " ");
                        counter++;
                    }
                    lock.notify();
                    try {
                        if (counter <= MAX) {
                            lock.wait();
                        }
                    } catch (InterruptedException e) {
                        e.printStackTrace();
                    }
                }
            }
        }
    }

    public static void main(String[] args) {
        EvenThread evenThread = new EvenThread();
        OddThread oddThread = new OddThread();

        evenThread.start();
        oddThread.start();

        try {
            evenThread.join();
            oddThread.join();
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
    }
}

