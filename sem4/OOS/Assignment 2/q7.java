import java.util.ArrayList;
import java.util.List;
import java.util.concurrent.Callable;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;
import java.util.concurrent.Future;

class SearchResult {
    int threadIndex;
    int location;
    boolean found;

    SearchResult(int threadIndex, int location, boolean found) {
        this.threadIndex = threadIndex;
        this.location = location;
        this.found = found;
    }
}

class SearchTask implements Callable<SearchResult> {
    private int[] array;
    private int target;
    private int threadIndex;
    private int startOffset;

    SearchTask(int[] array, int target, int threadIndex, int startOffset) {
        this.array = array;
        this.target = target;
        this.threadIndex = threadIndex;
        this.startOffset = startOffset;
    }

    private int binarySearch() {
        int left = 0;
        int right = array.length - 1;

        while (left <= right) {
            int mid = (left + right) / 2;
            if (array[mid] == target) {
                return mid + startOffset;
            }
            if (array[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return -1;
    }

    @Override
    public SearchResult call() {
        int location = binarySearch();
        return new SearchResult(threadIndex, location, location != -1);
    }
}

 class ParallelBinarySearch {
    private static List<SearchTask> createSearchTasks(int[] array, int target, int numThreads) {
        List<SearchTask> tasks = new ArrayList<>();
        int chunkSize = array.length / numThreads;

        for (int i = 0; i < numThreads; i++) {
            int[] subArray = new int[chunkSize];
            int startIndex = i * chunkSize;
            System.arraycopy(array, startIndex, subArray, 0, chunkSize);
            tasks.add(new SearchTask(subArray, target, i, startIndex));
        }

        return tasks;
    }

    public static void main(String[] args) {
        int[] array = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19,
                      21, 23, 25, 27, 29, 31, 33, 35, 37, 39};
        int target = 25;
        int numThreads = array.length / 10;

        ExecutorService executor = Executors.newFixedThreadPool(numThreads);
        List<SearchTask> tasks = createSearchTasks(array, target, numThreads);

        try {
            List<Future<SearchResult>> futures = executor.invokeAll(tasks);
            boolean elementFound = false;

            for (Future<SearchResult> future : futures) {
                SearchResult result = future.get();
                if (result.found) {
                    elementFound = true;
                    System.out.printf("Element %d found by Thread %d at location %d%n",
                                    target, result.threadIndex, result.location);
                }
            }

            if (!elementFound) {
                System.out.printf("Element %d not found in array%n", target);
            }

        } catch (Exception e) {
            e.printStackTrace();
        } finally {
            executor.shutdown();
        }
    }
}
