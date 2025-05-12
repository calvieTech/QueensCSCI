
//Calvin Thang
//Lab 11A

import javax.swing.*;
import java.awt.*;
import java.util.ArrayList;

public class Date212 {

   // create some variables so we can use them later
   private int year, month, day;
   public static ArrayList<Integer> arrayOfDates = new ArrayList<Integer>();
   public int size;

   // must use non-default constructor with a string parameter
   public Date212() {
      throw new Date212Exception("Must have a string parameter");
   }

   // constructor for Date212
   public Date212(String date) {
      // extract from the string date
      year = Integer.parseInt(date.substring(0, 4));
      month = Integer.parseInt(date.substring(4, 6));
      day = Integer.parseInt(date.substring(6, 8));

      // check if input is valid, if not - throw a Date212Exception
      if (!isValid(month, day)) {
         throw new Date212Exception("Illegal date.");
      } else {
         // add it to the array
         arrayOfDates.add(Integer.parseInt(date));
      }
   }

   // get and set methods with validation for input
   public int getYear() {
      return year;
   }

   public int getMonth() {
      return month;
   }

   public int getDay() {
      return day;
   }

   public void setYear(int yearInput) {
      year = yearInput;
   }

   public void setMonth(int monthInput) {
      if (monthInput <= 0 || monthInput > 12)
         throw new Date212Exception("invalid month");
      month = monthInput;
   }

   public void setDay(int dayInput) {
      if (dayInput <= 0 || dayInput > 31)
         throw new Date212Exception("invalid day");
      day = dayInput;
   }

   // returns false if month or day is not valid
   // returns true if month and day are valid
   private boolean isValid(int monthInput, int dayInput) {
      if (monthInput <= 0 || monthInput > 12 || dayInput <= 0 || dayInput > 31)
         return false;
      else
         return true;
   }

   // we want to compare the year, month, and day between this object and another
   // Date212 object
   public int compareTo(Date212 other) {
      if (this.year != other.year) {
         return this.year - other.year;
      } else {
         if (this.month != other.month) {
            return this.month - other.month;
         } else {
            if (this.day != other.day)
               return this.day - other.day;
            else
               return 0;
         }
      }
   }

   // convert attributes to type String using get methods
   @Override
   public String toString() {
      String dateYear = Integer.toString(this.getYear());
      String dateMonth = Integer.toString(this.getMonth());
      String dateDay = Integer.toString(this.getDay());
      return (dateMonth + "/" + dateDay + "/" + dateYear + "\n");
   }

}
