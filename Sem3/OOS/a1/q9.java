class Person
{
        int age;
        float weight;
        float height;
        String dateOfBirth;
        String address;

        Person(){
                age=0;
                weight=0;
                height=0;
                dateOfBirth="0/0/0";
                address="";
        }

        Person(int a, float w, float h, String dt, String add){
                age=a;
                weight=w;
                height=h;
                dateOfBirth=dt;
                address=add;
        }

        void write(int a, float w, float h, String dt, String add){
                 age=a;
                weight=w;
                height=h;
                dateOfBirth=dt;
                address=add;
        }

        void read(){
                System.out.println("age is: " + age);
                System.out.println("weight is: " + weight);
                System.out.println("height is: " + height);
                System.out.println("date of birth is: " + dateOfBirth);
                System.out.println("Address is: " + address);
        }
}

class Employee extends Person
{
        int salary;
        String dateOfJoin;
        int experience;

        Employee(){
                salary=0;
                dateOfJoin="0/0/0";
                experience=0;
        }

        Employee(int s, String d, int e){
                salary=s;
                dateOfJoin=d;
                experience=e;
        }
}

class Student extends Person
{
        int roll;
        String subs[3];
        int marks[3];

        Student(int r, int m1, int m2, int m3){
                roll=r;
                marks[0]=m1;
                marks[1]=m2;
                marks[2]=m3;
                subs[0]="maths";
                subs[1]="english";
                subs[2]="science";
        }

        int calculategrade(){
                return (m1+m2+m3)/3;
        }
}

class Technician extends employee
{
}

class Professor extends employee
{
}

class Demo
{
        public static void main(String args[]){
        }
}
