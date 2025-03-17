class NumSum {
    public static double sum=0;
    public static boolean ready=false;
    static final Object lock = new Object();
    
    static class OddSum extends Thread{
        
        public void run()
        {   double os=0;
            for (int i=1;i<=100;i+=2)
            {
                os+=i;
            }
            synchronized(lock) {
                sum+=os;
                ready = true;
                lock.notify();
                while(ready) {
                    try { lock.wait(); } 
                    catch (InterruptedException e) {}
                }
            }
        }
    }

    static class EvenSum extends Thread{
        
        public void run()
        {   double es=0;
            for (int j=2;j<=100;j+=2)
            {
                es+=j;
            }
            synchronized(lock) {
                while(!ready) {
                    try { lock.wait(); }                        
                    catch (InterruptedException e) {}
                }
                sum+=es;
                ready = false;
                lock.notify();
            }
        }
    }

    public static void main(String args[]){
        OddSum o1=new OddSum();
        EvenSum o2=new EvenSum();
        o1.start();
        o2.start();
        
        try {
            o1.join();
            o2.join();
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
        
        System.out.println("The final sum is: " + sum);
    }
}
