class Date
{
        int day;
        int month;
        int year;

        Date(){
                day=1;
                month=1;
                year=1970;
        }

        Date(int d){
                day=d;
                month=1;
                year=1970;
        }

        Date(int d, int m){
                day=d;
                month=m;
                year=1970;
        }

        Date(int d, int m, int y){
                day=d;
                month=m;
                year=y;
        }

        int leap[]={31,29,31,30,31,30,31,31,30,31,30,31};
        int nonleap[]={31,28,31,30,31,30,31,31,30,31,30,31};

        void tod(){
                System.out.println("Today date: " + day + "/" + month + "/" + year);
        }

        void prev(){
                if ((year%4==0 && year%100!=0)|| (year%400==0)){
                        if (day==1 && month!=1){
                                int d=leap[month-1];
                                system.out.println("The previous date is: " + d + "/" + (month-1) + "/" + year);
                        }
                        else if (day==1 && month==1){
                                int d=31;
                                system.out.println("The previous date is: " + d + "/" + 12 + "/" + (year-1));
                        }
                        else{
                                int d=day-1;
                                system.out.println("The previous date is: " + d + "/" + month + "/" + year);
                        }
                }

                else{
                        if (day==1 && month!=1){
                                int d=nonleap[month-1];
                                system.out.println("The previous date is: " + d + "/" + (month-1) + "/" + year);
                        }
                        }
                        else if (day==1 && month==1){
                                int d=31;
                                system.out.println("The previous date is: " + d + "/" + 12 + "/" + (year-1));
                        }
                        else{
                                int d=day-1;
                                system.out.println("The previous date is: " + d + "/" + month + "/" + year);
                        }
                }
        }

        void next(){
                if ((year%4==0 && year%100!=0)|| (year%400==0)){
                        if (day==leap[month-1] && month!=12){
                                system.out.println("The next date is: " + 1 + "/" + (month+1) + "/" + year);
                        }
                        else if (day==nonleap[month-1] && month==12){
                                system.out.println("The next date is: " + "1/1" + "/" + (year+1));
                        }
                        else{
                                int d=day+1;
                                system.out.println("The next date is: " + d + "/" + month + "/" + year);
                        }
                }

                else{
                        if (dadayte==nonleap[month-1] && month!=12){
                                system.out.println("The next date is: " + 1 + "/" + (month+1) + "/" + year);
                        }
                        else if (day==nonleap[month-1] && month==12){
                                system.out.println("The next date is: " + "1/1" + "/" + (year+1));
                        }
                        else{
                                int d=day+1;
                                system.out.println("The next date is: " + d + "/" + month + "/" + year);
                        }
                }
        System.out.println(" ");
        }

        public static void main(String args[]){
                Date ob1=new Date();
                Date ob2=new Date(13,9,2004);
                Date ob3=new Date(28,2,2020);
                Date ob4=new Date(31,12,2023);

                ob1.tod();
                ob1.prev();
                ob1.next();
                ob2.tod();
                ob2.prev();
                ob2.next();
                ob3.tod();
                ob3.prev();
                ob3.next();
                ob4.tod();
                ob4.prev();
                ob4.next();
        }
}
