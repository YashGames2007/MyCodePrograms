package Basic_Code.Mini_Projects.Bank;

class Account {

    String user_Name;

    private String email_ID;
    private String phone_Number;
    private String password;

    Account(String user_Name, String password) {
        this.user_Name = user_Name;
        this.password = password;
    }

    public void setDetails(String password, String email_ID, String phone_Number) {
        if (this.is_Correct_Password(password)) {
            this.email_ID = email_ID;
            this.phone_Number = phone_Number;
        }
    }

    public void getDetails(String password) {
        if (this.is_Correct_Password(password)) {
            System.out.printf("\nEmail: %s\nPhone: %s", this.email_ID, this.phone_Number);
        }
    }

    public String getEmail_ID(String password) {

        if (this.is_Correct_Password(password)) {
            return this.email_ID;
        }
        return null;
    }

    public String getPhone_Number(String password) {

        if (this.is_Correct_Password(password)) {
            return this.phone_Number;
        }
        return null;
    }

    public void setEmail_ID(String password, String email_ID) {
        if (this.is_Correct_Password(password)) {
            this.email_ID = email_ID;
        }
    }

    public void setPhone_Number(String password, String phone_Number) {
        if (this.is_Correct_Password(password)) {
            this.phone_Number = phone_Number;
        }
    }

    public boolean is_Correct_Password(String password) {
        if (this.password == password) {
            return true;
        }
        System.out.printf("\nIncorrect Password..!!");
        return false;
    }

    // private String get_Password() {
    // return this.password;
    // }

}

interface Bank {

    float interest_Rate = 4.5f;
    void deposit(int amount);

    int withdraw(String password, int amount);

    void getBank_Details(String password);
}

class Bank_Account extends Account implements Bank {

    int bank_Balance;

    @Override
    public void deposit(int amount) {
        System.out.printf("\nAmount Deposited Successfully..!!");
        this.bank_Balance += amount;
    }

    @Override
    public void getBank_Details(String password) {
        if (this.is_Correct_Password(password)) {
            System.out.printf("\n\nBank Account Details:::");
            System.out.printf("\nAccount Holder Name: %s", this.user_Name);
            getDetails(password);
            System.out.printf("\nBank Balance: %d\n", this.bank_Balance);
        }
    }

    @Override
    public int withdraw(String password, int amount) {
        if (this.is_Correct_Password(password)) {
           if (this.bank_Balance < amount) {
                System.out.printf("\nInsufficient Bank Balance, Transaction Failed..!!");
                return -1;
           }
           System.out.printf("\nAmount Withdrawn Successfully..!!");
           this.bank_Balance -= amount;
           return amount;
        }
        return -1;
    }

    Bank_Account(String username, String password) {
        super(username, password);
        this.bank_Balance = 0;
        System.out.printf("\nBank Account Generated Successfully..!!");
    }
    
}

public class banking {

    public static void main(String[] args) {

        System.out.printf("\nHello World!");    

        Bank_Account bank_Account = new Bank_Account("Yash Bhavsar", "yashgames");
        bank_Account.setDetails("yashgames", "yashbhavsar.dev2007@gmail.com", "9503354113");

        System.out.printf("\n");
        bank_Account.getBank_Details("yashgames");
        bank_Account.deposit(1000);

        System.out.printf("\n");
        bank_Account.getBank_Details("yashgames");
        bank_Account.withdraw("yashgames", 1000);

        System.out.printf("\n");
        bank_Account.getBank_Details("yashgames");
        bank_Account.withdraw("yashgames", 1);
    }
}
