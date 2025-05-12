import java.util.Arrays;

public class Main14
{
    public static void main(String[] args)
    {
        // Test cases
        Money m1 = new Money();
        Money m2 = new Money(6,5);
        Money m3 = new Money(-3, 32);
        Money m4 = new Money(6, 52);
        System.out.printf("m1: %s\nm2: %s\nm3: %s\nm4: %s\n", m1, m2, m3, m4);
        System.out.printf("m1 cents: %d\n", m1.getCents());
        System.out.printf("m2 dollars: %d\n", m2.getDollars());
        System.out.printf("m1.compareTo(m2): %d\n", m1.compareTo(m2));
        System.out.printf("m2.compareTo(m4): %d\n", m2.compareTo(m4));
        System.out.printf("m1.equals(m2): %b\n", m1.equals(m2));
        
        //bonus
        Money[] moneyArray = new Money[4];
        moneyArray[0] = m1;
        moneyArray[1] = m2;
        moneyArray[2] = m3;
        moneyArray[3] = m4;
        
        System.out.printf("before sorting: %s\n", Arrays.toString(moneyArray));
        Money.selectionSort(moneyArray);
        System.out.printf("after sorting: %s\n", Arrays.toString(moneyArray));

    }
}

// Definition of a custom class
class Money
{
   private int dollars, cents;
   
   public Money() {
      this(0, 0);
   }
   
   public Money(int dollarInput, int centInput) {
      dollars = dollarInput;
      cents = centInput;
      
   }
   
   public int getDollars() {
      return dollars;
   }
   
   public int getCents() {
      return cents;
   }
   
   private void setDollars(int dollarIn) {
      if (dollarIn < 0) throw new IllegalArgumentException("Cannot accept negative values");
      dollars = dollarIn;
   }
   
   private void setCents(int centIn) {
      if (centIn < 0) throw new IllegalArgumentException("Cannot accept negative values");
      cents = centIn;
   }
   
   public int compareTo(Money other) {
      if (this.dollars != other.dollars)
      {
          return this.dollars - other.dollars;
      }
      else if (this.cents != other.cents)
      {
          return this.cents - other.cents;
      }
      return 0;
   }
   
   @Override
   public boolean equals(Object other) {
      if (!(other instanceof Money)) return false;
      if (other == this) return true;
      
      Money newMoney = (Money) other;
      if (this.dollars == newMoney.dollars && this.cents == newMoney.cents)
         return true;
      else
         return false;
   }
   
   @Override
   public String toString() {
      String formattedCents = Integer.toString(this.cents);
      if (this.cents < 10) formattedCents = "0" + formattedCents;
      return String.format("$%d.%s", this.dollars, formattedCents);
   }
   
   public static void selectionSort(Money[] moneyArray) {
      int size = moneyArray.length;
      
      for (int i = 0; i < size; i++) {
         Money min = moneyArray[i];
         int minIndex = i;
         
         for (int j = i + 1; j < size - 1; ++j) {
            if (min.compareTo(moneyArray[j]) > 0) {
               min = moneyArray[j];
               minIndex = j;
            }
         }
         swap(moneyArray, i, minIndex);
      }
   }
   
   public static void swap(Money[] moneyArrayIn, int i, int j) {
      Money temp = moneyArrayIn[i];
      moneyArrayIn[i] = moneyArrayIn[j];
      moneyArrayIn[j] = temp;
   }
   
}