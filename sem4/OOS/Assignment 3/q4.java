import java.lang.reflect.Constructor;
import java.lang.reflect.Field;
import java.lang.reflect.Method;
import java.lang.reflect.Modifier;

class Person {
    private String name;
    private int age;

    // Constructor
    public Person(String name, int age) {
        this.name = name;
        this.age = age;
    }

    // Public method
    public void introduce() {
        System.out.println("Hello, my name is " + name + " and I am " + age + " years old.");
    }

    // Private method
    private void setName(String name) {
        this.name = name;
    }

    // Private field
    private String address;
}

class ReflectionTest {

    public static void main(String[] args) throws Exception {
        // Step 1: Create an object of the Person class
        Person person = new Person("John", 30);

        // Step 2: Using getClass() to get the Class object
        Class<?> personClass = person.getClass();
        System.out.println("Class Name: " + personClass.getName());

        // Step 3: Using getMethods() to get all public methods
        System.out.println("\nPublic Methods:");
        Method[] methods = personClass.getMethods();
        for (Method method : methods) {
            System.out.println(method.getName());
        }

	      // Step 4: Using getConstructors() to get all public constructors
        System.out.println("\nPublic Constructors:");
        Constructor<?>[] constructors = personClass.getConstructors();
        for (Constructor<?> constructor : constructors) {
            System.out.println(constructor.getName());
        }

	      // Step 5: Using getDeclaredMethod() to get a private method
        System.out.println("\nPrivate Method (using getDeclaredMethod):");
        Method privateMethod = personClass.getDeclaredMethod("setName", String.class);
        System.out.println("Method Name: " + privateMethod.getName());

        // Step 6: Using setAccessible() to access a private method
        privateMethod.setAccessible(true);
        privateMethod.invoke(person, "Alice");
        System.out.println("Private method invoked successfully.");

        // Step 7: Using getDeclaredField() to access a private field
        System.out.println("\nPrivate Field (using getDeclaredField):");
        Field privateField = personClass.getDeclaredField("address");
        privateField.setAccessible(true);  // Set the field accessible
        privateField.set(person, "123 Main St");
        System.out.println("Private field 'address' value: " + privateField.get(person));

        // Step 8: Modify a private field using reflection
        System.out.println("\nModifying private field 'name':");
        Field nameField = personClass.getDeclaredField("name");
        nameField.setAccessible(true);
        System.out.println("Initial name: " + nameField.get(person));
        nameField.set(person, "Bob");
        System.out.println("Modified name: " + nameField.get(person));

        // Step 9: Call a public method using reflection
        System.out.println("\nCalling public method 'introduce':");
        Method introduceMethod = personClass.getMethod("introduce");
        introduceMethod.invoke(person);
    }
}
