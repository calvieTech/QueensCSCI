import java.util.ArrayList;

public class Main17
{
    public static void main(String[] args)
    {
        // Test cases
        Wallet wallet = new Wallet();
        wallet.add(new Penny());
        wallet.add(new Single());
        wallet.add(new Nickel());
        wallet.add(new Nickel());
        wallet.add(new Quarter());
        wallet.add(new Quarter());
        System.out.printf("Wallet value: %s\n", wallet);
        wallet.printContent(); // prints what the wallet currently holds
        
        Money m1 = new Dime();
        wallet.add(m1);
        System.out.printf("m1 is a: %s\n", m1.toString());

        m1 = new Nickel();
        wallet.add(m1);
        System.out.printf("m1 is a: %s\n", m1.toString());

        m1 = new Single();
        wallet.add(m1);
        System.out.printf("m1 is a: %s\n", m1.toString());

        System.out.println(wallet); // prints value 
    }
}

class Wallet 
{
    // TODO - Instance variables
   private int value;
   private ArrayList<Money> moneyList;

    // Default constructor
    public Wallet()
    {
       moneyList = new ArrayList<Money>();
       
    }

    public void add(Money money)
    {
        // TODO
       moneyList.add(money);
       this.value += money.getValue();
    }

    // Print the contents inside the wallet
    public void printContent()
    {
        // TODO
       int pennyCount = 0, nickelCount = 0, dimeCount = 0, quarterCount = 0, singleCount = 0;
       for (int i = 0; i < moneyList.size(); ++i) {
          Money m = moneyList.get(i);
          
          if (m instanceof Penny)
             pennyCount++;
          else if (m instanceof Nickel)
             nickelCount++;
          else if (m instanceof Dime)
             dimeCount++;
          else if (m instanceof Quarter)
             quarterCount++;
          else
             singleCount++;
       }
       System.out.printf("This wallet has: %d penny(s), %d nickel(s), %d dime(s), %d quarter(s), and %d single(s)\n", pennyCount, nickelCount, dimeCount, quarterCount, singleCount);
    }
    
    // Print a string in the format of: $13.32
    @Override
    public String toString()
    {
        return String.format("$%d.%d", this.value / 100, this.value % 100);
    }
}

abstract class Money 
{
    private int value;

    public Money(int value) 
    {
        this.value = value;
    }

    public int getValue() 
    {
        return this.value;
    }

    @Override
    public String toString()
    {
        return "money object";
    }
}

class Single extends Money 
{
    public Single() 
    {
        super(100);
    }

    @Override
    public String toString() 
    {
        return "single object";
    }
}

class Quarter extends Money 
{
    public Quarter() 
    {
        super(25);
    }

    @Override
    public String toString() 
    {
        return "quarter object";
    }
}

class Dime extends Money 
{
    public Dime() 
    {
        super(10);
    }

    @Override
    public String toString() 
    {
        return "dime object";
    }
}

class Nickel extends Money 
{
    public Nickel() 
    {
        super(5);
    }

    @Override
    public String toString()
    {
        return "nickel object";
    }
}

class Penny extends Money 
{
    public Penny() 
    {
        super(1);
    }

    @Override
    public String toString() 
    {
        return "penny object";
    }
}