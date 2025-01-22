class BankAccount
{
        int AccountNumber;
        double balance;
        String name;

        BankAccount(){
                AccountNumber=0;
                balance=0;
                name=" ";
        }

        BankAccount(int n, String s, double b){
                AccountNumber=n;
                balance=b;
                name=s;
        }

        void balance(){
                System.out.println("balance is: " + balance);
        }

        void add(double n){
                balance+=n;
        }

        void subtract(double n){
                balance-=n;
        }

        void disp(){
                System.out.println("Account Number: " + AccountNumber);
                System.out.println("Name of Account holder: " + name);
                System.out.println("Balance is: " + balance);
        }
}

class AccountManager
{
        int n;
        BankAccount Accts[];

        AccountManager(int x){
                n=x;
                Accts = new BankAccount[x];
        }

        int i=0;

        void create(int N, String s, double b){
                if (i>=n){
                        System.out.println("Full");
                        return;
                }
                Accts[i++] = new BankAccount(N,s,b);
        }

        void delete(int N){
                for (int j=0;j<n;j++){
                        if (Accts[j].AccountNumber==N){
                                Accts[j]=null;
                                return;
                        }
                }
                System.out.println("No account with this account number");
        }

        void deposit(int N, int b){
                for (int j=0;j<n;j++){
                        if (Accts[j].AccountNumber==N){
                                Accts[j].add(b);
                                System.out.println("Deposited");
                                return;
                        }
                }
                System.out.println("No account with this account number");
        }

        void withdraw(int N, int b){
                for (int j=0;j<n;j++){
                        if (Accts[j].AccountNumber==N){
                                Accts[j].subtract(b);
                                System.out.println("Withdrawn");
                                return;
                        }
                }
                System.out.println("No account with this account number");
        }

        void show(){
                for (int j=0;j<n;j++){
                        Accts[j].disp();
                }
        }
}

class Bank
{
        public static void main(String args[])
        {
                AccountManager am = new AccountManager(5);

                am.create(1001,"Riya",6537);
                am.create(1002,"Sam",5462);
                am.create(1003,"Mani",6378);
                am.create(1004,"Raj",4342);
                am.create(1005,"Abhi",56234);

                am.show();
        }
}
