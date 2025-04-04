import java.util.Comparator;

class GenericSorter {

    public static <T extends Comparable<T>> void sortArray(T[] array) {
        // Bubble Sort algorithm
        for (int i = 0; i < array.length - 1; i++) {
            for (int j = 0; j < array.length - i - 1; j++) {
                if (array[j].compareTo(array[j + 1]) > 0) {
                    // Swap the elements
                    T temp = array[j];
                    array[j] = array[j + 1];
                    array[j + 1] = temp;
                }
            }
	}
    }

    public static void main(String[] args) {
        // Test the sortArray method with an Integer array
        Integer[] intArray = {4, 2, 7, 1, 9, 3};
        sortArray(intArray);
        System.out.println("Sorted Integer Array: ");
        for (Integer num : intArray) {
            System.out.print(num + " ");
        }

	System.out.println();

        // Test the sortArray method with a String array
        String[] strArray = {"apple", "orange", "banana", "kiwi"};
        sortArray(strArray);
        System.out.println("Sorted String Array: ");
        for (String str : strArray) {
            System.out.print(str + " ");
        }
	System.out.println();
    }
}
