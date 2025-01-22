lass Employee
{
        String name;
        int ID;
        String Address;
        int salary;

        Employee(){
                name=" ";
                ID=0;
                Address=" ";
                salary=0;
        }

        Employee(String n, int i, String a, int s){
                name=n;
                ID=i;
                Address=a;
                salary=s;
        }

        void read(){
                System.out.println("Name is: " + name);
                System.out.println("ID is: " + ID);
                System.out.println("Address is: " + Address);
                System.out.println("Salary is: " + salary);
        }
}

class Dept
{
        String dname;
        Employee emps[];
        int n;

        Dept(String s, int x){
                dname=s;
                n=x;
                emps = new Employee[n];
        }

        int i=0;

        void add(String n, int d, String a, int s){
                emps[i++] = new Employee(n,d,a,s);
        }

        void remove(int d){
                for (int j=0; j<n; j++){
                        if (emps[j].ID==d){
                                emps[j]=null;
                                return;
                        }
                }
                System.out.println("No employee with such ID");
        }

        int sum(){
                int su=0;
                for (int j=0;j<n;j++){
                        emps[j].read();
                        su+=emps[j].salary;
                }
                return su;
        }
}

class Demo
{
        public static void main(String args[]){
                Dept ob = new Dept("Information technology",5);

                ob.add("Riya",101,"Kolkata",1000);
                ob.add("Keya",102,"Birbhum",3500);
                ob.add("Raj",103,"Bangalore",7000);
                ob.add("Tina",104,"Delhi",5000);
                ob.add("Karan",105,"Mumbai",4000);

                int s = ob.sum();

                System.out.println("The yearly expenditure of the IT department is: " + (s*13));
        }
}
