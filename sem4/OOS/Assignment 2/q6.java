import java.util.Arrays;

class ParallelBinarySearch extends Thread {
    private int[] subArray;
    private int element;
    private int startIndex;
    private static volatile int foundIndex = -1;

    public ParallelBinarySearch(int[] subArray, int element, int startIndex) {
        this.subArray = subArray;
        this.element = element;
        this.startIndex = startIndex;
    }

    private int binarySearch(int[] arr, int target) {
        int left = 0, right = arr.length - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (arr[mid] == target) {
                return mid + startIndex;
            } else if (arr[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return -1;
    }

    @Override
    public void run() {
        if (foundIndex == -1) { // Only search if the element isn't found yet
            int index = binarySearch(subArray, element);
            if (index != -1) {
                foundIndex = index;
            }
        }
    }

    public static int parallelBinarySearch(int[] arr, int element) {
        int n = arr.length;
        int numThreads = n / 10;
        ParallelBinarySearch[] threads = new ParallelBinarySearch[numThreads];

        for (int i = 0; i < numThreads; i++) {
            int start = i * 10;
            int[] subArray = Arrays.copyOfRange(arr, start, start + 10);
            threads[i] = new ParallelBinarySearch(subArray, element, start);
            threads[i].start();
        }

        for (ParallelBinarySearch thread : threads) {
            try {
                thread.join();
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
        return foundIndex;
    }

    public static void main(String[] args) {
        int[] arr = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19,
                     21, 23, 25, 27, 29, 31, 33, 35, 37, 39,
                     41, 43, 45, 47, 49, 51, 53, 55, 57, 59};
        int element = 27;

        int index = parallelBinarySearch(arr, element);

        if (index != -1) {
            System.out.println("Element found at index: " + index);
        } else {
            System.out.println("Element not found");
        }
    }
}
