
import java.util.HashMap;
import java.util.Map;

class FrequencyCounter {

    public static <T> void findFrequency(T[] array) {
        // Create a Map to store element frequencies
        Map<T, Integer> frequencyMap = new HashMap<>();

        // Iterate through the array to count the frequency of each element
        for (T element : array) {
            frequencyMap.put(element, frequencyMap.getOrDefault(element, 0) + 1);
        }

	// Print the frequency of each element
        for (Map.Entry<T, Integer> entry : frequencyMap.entrySet()) {
                System.out.println(entry.getKey() + " : " + entry.getValue() + " time(s)");
        }
    }

    public static void main(String[] args) {
        // Test the findFrequency method with an Integer array
        Integer[] intArray = {1, 2, 2, 3, 3, 3, 4};
        System.out.println("Frequency of elements in Integer array : ");
        findFrequency(intArray);

        System.out.println();

        // Test the findFrequency method with a String array
        String[] strArray = {"apple", "banana", "apple", "kiwi", "banana", "apple"};
        System.out.println("Frequency of elements in String array:");
        findFrequency(strArray);
    }
}

