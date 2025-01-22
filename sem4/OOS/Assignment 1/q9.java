import java.util.ArrayList;
import java.util.List;

class Person {
    private int age;
    private double weight;
    private double height;
    private String dateOfBirth;
    private String address;

    public Person(int age, double weight, double height, String dateOfBirth, String address) {
        this.age = age;
        this.weight = weight;
        this.height = height;
        this.dateOfBirth = dateOfBirth;
        this.address = address;
    }

    public int getAge() {
        return age;
    }

    public void setAge(int age) {
        this.age = age;
    }

    public double getWeight() {
        return weight;
    }

    public void setWeight(double weight) {
        this.weight = weight;
    }

    public double getHeight() {
        return height;
    }

    public void setHeight(double height) {
        this.height = height;
    }

    public String getDateOfBirth() {
        return dateOfBirth;
    }

    public void setDateOfBirth(String dateOfBirth) {
        this.dateOfBirth = dateOfBirth;
    }

    public String getAddress() {
        return address;
    }

    public void setAddress(String address) {
        this.address = address;
    }

    public void printDetails() {
        System.out.println("Age: " + age);
        System.out.println("Weight: " + weight);
        System.out.println("Height: " + height);
        System.out.println("Date of Birth: " + dateOfBirth);
        System.out.println("Address: " + address);
    }
}

class Employee extends Person {
    private double salary;
    private String dateOfJoining;
    private int experience;

    public Employee(int age, double weight, double height, String dateOfBirth, String address,
                    double salary, String dateOfJoining, int experience) {
        super(age, weight, height, dateOfBirth, address);
        this.salary = salary;
        this.dateOfJoining = dateOfJoining;
        this.experience = experience;
    }

    public double getSalary() {
        return salary;
    }

    public void setSalary(double salary) {
        this.salary = salary;
    }

    public String getDateOfJoining() {
        return dateOfJoining;
    }

    public void setDateOfJoining(String dateOfJoining) {
        this.dateOfJoining = dateOfJoining;
    }

    public int getExperience() {
        return experience;
    }

    public void setExperience(int experience) {
        this.experience = experience;
    }

    public void printDetails() {
        super.printDetails();
        System.out.println("Salary: " + salary);
        System.out.println("Date of Joining: " + dateOfJoining);
        System.out.println("Experience: " + experience + " years");
    }
}

class Student extends Person {
    private int roll;
    private List<String> listOfSubjects;
    private List<Double> marks;

    public Student(int age, double weight, double height, String dateOfBirth, String address, int roll,
                   List<String> listOfSubjects, List<Double> marks) {
        super(age, weight, height, dateOfBirth, address);
        this.roll = roll;
        this.listOfSubjects = listOfSubjects;
        this.marks = marks;
    }

    public double calculateGrade() {
        double total = 0;
        for (double mark : marks) {
            total += mark;
        }
        return total / marks.size();
    }

    public void printDetails() {
        super.printDetails();
        System.out.println("Roll: " + roll);
        System.out.println("Subjects: " + listOfSubjects);
        System.out.println("Marks: " + marks);
        System.out.println("Grade: " + calculateGrade());
    }
}

class Technician extends Employee {
    public Technician(int age, double weight, double height, String dateOfBirth, String address,
                      double salary, String dateOfJoining, int experience) {
        super(age, weight, height, dateOfBirth, address, salary, dateOfJoining, experience);
    }

    public void printDetails() {
        super.printDetails();
        System.out.println("Role: Technician");
    }
}

class Professor extends Employee {
    private List<String> courses;
    private List<String> listOfAdvisees;

    public Professor(int age, double weight, double height, String dateOfBirth, String address,
                     double salary, String dateOfJoining, int experience, List<String> courses,
                     List<String> listOfAdvisees) {
        super(age, weight, height, dateOfBirth, address, salary, dateOfJoining, experience);
        this.courses = courses;
        this.listOfAdvisees = listOfAdvisees;
    }

    public void addAdvisee(String advisee) {
        listOfAdvisees.add(advisee);
    }

    public void removeAdvisee(String advisee) {
        listOfAdvisees.remove(advisee);
    }

    public void printDetails() {
        super.printDetails();
        System.out.println("Courses: " + courses);
        System.out.println("Advisees: " + listOfAdvisees);
    }
}

class Demo {
    public static void main(String[] args) {
        Person person = new Person(30, 70, 175, "1993-05-15", "123 Main St");

        Employee employee = new Employee(40, 80, 180, "1983-09-20", "456 Elm St", 50000, "2010-06-01", 13);

        List<String> subjects = new ArrayList<>();
        subjects.add("Math");
        subjects.add("Physics");
        List<Double> marks = new ArrayList<>();
        marks.add(85.0);
        marks.add(90.0);
        Student student = new Student(20, 60, 165, "2003-11-15", "789 Maple St",101, subjects, marks);

        Technician technician = new Technician(35, 75, 170, "1988-02-14", "321 Oak St", 40000, "2015-03-12", 8);

        List<String> courses = new ArrayList<>();
        courses.add("Computer Science");
        courses.add("AI");
        List<String> advisees = new ArrayList<>();
        advisees.add("John");
        advisees.add("Jane");
        Professor professor = new Professor(50, 85, 180, "1973-12-25", "654 Pine St", 70000, "2000-08-15", 23, courses, advisees);

        System.out.println("Person Details:");
        person.printDetails();
        System.out.println();

        System.out.println("Employee Details:");
        employee.printDetails();
        System.out.println();

        System.out.println("Student Details:");
        student.printDetails();
        System.out.println();

        System.out.println("Technician Details:");
        technician.printDetails();
        System.out.println();

        System.out.println("Professor Details:");
        professor.printDetails();
    }
}
