import java.util.ArrayList;
import java.util.List;

class Account {
    private int accountNumber;
    private String holderName;
    private double balance;

    public Account(int accountNumber, String holderName, double balance) {
        this.accountNumber = accountNumber;
        this.holderName = holderName;
        this.balance = balance;
    }
    
    public int getAccountNumber() {
        return accountNumber;
    }

    public void setAccountNumber(int accountNumber) {
        this.accountNumber = accountNumber;
    }

    public String getHolderName() {
        return holderName;
    }

    public void setHolderName(String holderName) {
        this.holderName = holderName;
    }

    public double getBalance() {
        return balance;
    }

    public void setBalance(double balance) {
        this.balance = balance;
    }

    public void printDetails() {
        System.out.println("Account Number: " + accountNumber);
        System.out.println("Holder Name: " + holderName);
        System.out.println("Balance: $" + balance);
    }
}

class SavingsAccount extends Account {
    private double interestRate;

    public SavingsAccount(int accountNumber, String holderName, double balance, double interestRate) {
        super(accountNumber, holderName, balance);
        this.interestRate = interestRate;
    }

    public double getInterestRate() {
        return interestRate;
    }

    public void setInterestRate(double interestRate) {
        this.interestRate = interestRate;
    }

    public double calculateYearlyInterest() {
        return getBalance() * (interestRate / 100);
    }

    public void printDetails() {
        super.printDetails();
        System.out.println("Account Type: Savings Account");
        System.out.println("Interest Rate: " + interestRate + "%");
        System.out.println("Yearly Interest: $" + calculateYearlyInterest());
    }
}

class CurrentAccount extends Account {
    public CurrentAccount(int accountNumber, String holderName, double balance) {
        super(accountNumber, holderName, balance);
    }

    public void printDetails() {
        super.printDetails();
        System.out.println("Account Type: Current Account");
    }
}

class Manager {
    private List<Account> accounts;

    public Manager() {
        accounts = new ArrayList<>();
    }

    public void addAccount(Account account) {
        accounts.add(account);
    }

    public void printAllAccounts() {
        for (Account account : accounts) {
            account.printDetails();
            System.out.println();
        }
    }
}

class Demo {
    public static void main(String[] args) {
        Manager manager = new Manager();

        SavingsAccount savings1 = new SavingsAccount(1001, "John Doe", 5000.0, 2.5);
        SavingsAccount savings2 = new SavingsAccount(1002, "Jane Smith", 8000.0, 3.0);

        CurrentAccount current1 = new CurrentAccount(2001, "Alice Johnson", 10000.0);
        CurrentAccount current2 = new CurrentAccount(2002, "Bob Brown", 12000.0);
        CurrentAccount current3 = new CurrentAccount(2003, "Eve Lee", 15000.0);

        manager.addAccount(savings1);
        manager.addAccount(savings2);
        manager.addAccount(current1);
        manager.addAccount(current2);
        manager.addAccount(current3);

        System.out.println("Details of All Accounts:");
        System.out.println("--------------------------");
        manager.printAllAccounts();
    }
}
