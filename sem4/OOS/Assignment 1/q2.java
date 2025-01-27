class student
{
        String name;
        double s1m;
        double s2m;
        double s3m;

        void set(String s, double m1, double m2, double m3){
                name=s;
                s1m=m1;
                s2m=m2;
                s3m=m3;
        }

        double avg(){
                return ((s1m+s2m+s3m)/3);
        }

        void disp(){
                System.out.println("name is: " + name);
                System.out.println("Total marks is: " + (s1m+s2m+s3m));
        }
}

class Demo{
        public static void main(String args[])
        {
                student ob1=new student();
                ob1.set("Riya",70,80,90);
                student ob2=new student();
                ob2.set("Sam",65,85,75);
                ob1.disp();
                ob2.disp();
                System.out.println("Average of 1st student= " + ob1.avg());
                System.out.println("Average of 2nd student= " + ob2.avg());
        }
}
