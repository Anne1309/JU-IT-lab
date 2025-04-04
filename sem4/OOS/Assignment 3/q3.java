
import java.util.HashMap;
import java.util.Map;
import java.util.Set;
import java.util.HashSet;

class DuplicateFinder {

    // Generic method to find and print duplicate elements
    public static <T> void printDuplicates(T[] array) {
        // Create a Map to store the frequency of each element
        Map<T, Integer> elementCount = new HashMap<>();

        // Count occurrences of each element
        for (T element : array) {
            elementCount.put(element, elementCount.getOrDefault(element, 0) + 1);
        }

	// Set to store duplicates
        Set<T> duplicates = new HashSet<>();

        // Iterate over the map and find elements with a count greater than 1 (duplicates)
        for (Map.Entry<T, Integer> entry : elementCount.entrySet()) {
            if (entry.getValue() > 1) {
                duplicates.add(entry.getKey());
            }
	}

	// Print the duplicate elements
        if (duplicates.isEmpty()) {
            System.out.println("No duplicates found.");
        } else {
            for (T duplicate : duplicates) {
                System.out.println(duplicate);
            }
	}
    }

    public static void main(String[] args) {
        // Test with an Integer array
        Integer[] intArray = {1, 2, 2, 3, 4, 5, 3};
        System.out.println("Duplicates in Integer array:");
        printDuplicates(intArray);

        System.out.println();

        // Test with a String array
        String[] strArray = {"apple", "banana", "apple", "kiwi", "banana", "orange"};
        System.out.println("Duplicates in String array:");
        printDuplicates(strArray);
    }
}
