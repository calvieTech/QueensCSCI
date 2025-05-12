//Calvin Thang
//Lab 11A

import java.util.StringTokenizer;
import java.util.ArrayList;
import javax.swing.*;
import java.awt.*;


public class Project1 {
   public static Date212[] unsortedDates, sortedDates;
   public static int length;
   public static String[] stringDates;
   
   
   
   
   public static void main(String[] args) {
      
      //so user knows to put in an argument
      if (args.length < 1) {
         System.out.println("Must type in a file name");
         System.exit(1);
      }
      
      //user input argument is inside the var input
      TextFileInput input = new TextFileInput(args[0]);
      
      //create arrays to store data in
      stringDates = new String[length];
      stringDates = readFileInput(input);
      
      
      unsortedDates = new Date212[length];
      sortedDates = new Date212[length];
      
      //store the return array in a Date212[] array
      unsortedDates = storeUnsortedDates(unsortedDates);
      sortedDates = storeSortedDates(sortedDates);

      //call the constructor for class DateGUI
      DateGUI myGUI = new DateGUI();
      
      //call on the method DisplayOnGUI using what we know
      displayOnGUI(myGUI, unsortedDates, sortedDates, length);
      
      
      
      
      
      
      
      
      
   }
   
   //reads line from file and puts it in a array of strings
   public static String[] readFileInput(TextFileInput inputFromMain) {
      ArrayList<String> listString = new ArrayList<String>();
      
      String read = inputFromMain.readLine();
      StringTokenizer tokens;
      
      //break the line of text into tokens using ","
      int j = 0;
      //run as long as string is not empty
      while (read != null) {
         tokens = new StringTokenizer(read, ",");
         
         //validate method
         if (validateFileInput(read) == false) {
            throw new IllegalArgumentException("Illegal file argument");
         }
         
         //add the broken up pieces of the entire string until there are no more pieces
         while (tokens.hasMoreTokens() ) {
            listString.add(tokens.nextToken());
            j++;
         }
         
         //keep reading from the file
         read = inputFromMain.readLine();
      }
      
      length = 0;
      length = listString.size();
      String[] arrayOfDates = new String[length];
      
      for (int i = 0; i < length; ++i) {
         arrayOfDates[i] = listString.get(i);
         
      }
      return arrayOfDates;
      
   }
   
   
  // validation method to see if the string contains digits or not 
   public static boolean validateFileInput(String readInput) {
      if (readInput == null) return false;
      for (int i = 0; i < readInput.length(); ++i) {
        char testing = readInput.charAt(i);
        if (testing == ',') continue;
        if (!Character.isDigit(testing)) {
           System.out.println("Date must only be digits");
           return false;
        }
      }
      return true;
   }
   
   //store unsorted dates and return a array of Date212 objects
   public static Date212[] storeUnsortedDates(Date212[] unsortedDatesInput) {
      for (int i = 0; i < length; ++i) {
         Date212 date = new Date212(stringDates[i]);
         unsortedDatesInput[i] = date;
      }
      return unsortedDatesInput;
   }
   
   
   //store sorted dates and return a array of Date212 objects
   public static Date212[] storeSortedDates(Date212[] sortedDatesInput) {
      for (int i = 0; i < length; ++i) {
         Date212 date = new Date212(stringDates[i]);
         sortedDatesInput[i] = date;
      }
      
      //selection sort
      for (int j = 0; j < length; j++) {
         int indexLowest = j;
         
         for (int k = j + 1; k < length; k++) {
            
            if (sortedDatesInput[k].getYear() < sortedDatesInput[indexLowest].getYear())
               indexLowest = k;
            
         }
         
         if (sortedDatesInput[indexLowest].getYear() != sortedDatesInput[j].getYear()) {
            int temp = sortedDatesInput[indexLowest].getYear();
            sortedDatesInput[indexLowest].setYear(sortedDatesInput[j].getYear());
            sortedDatesInput[j].setYear(temp);
         }
      }
      

      return sortedDatesInput;
   }
   
   
   //display unsortedDatesInput on left
   //display sortedDatesInput on right
   public static void displayOnGUI(DateGUI input, Date212[] unsortedDatesInput, Date212[] sortedDatesInput, int size) {
      input.left.append("Unsorted Dates:\n");
      input.right.append("Sorted Dates:\n");
      
      for (int i = 0; i < size; ++i) {
         input.left.append(unsortedDatesInput[i].toString() + "\n");
         input.right.append(sortedDatesInput[i].toString() + "\n");
      }
      
      //show the GUI results
      input.myFrame.pack();
      input.myFrame.setVisible(true);
   }
}