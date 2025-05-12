
//Calvin Thang
//Lab 11A

import java.util.StringTokenizer;
import java.util.ArrayList;
import javax.swing.*;
import java.awt.*;

public class Project2 {

   public static void main(String[] args) {
      //instantiates objects
      UnsortedDate212List unsortedList = new UnsortedDate212List();
      SortedDate212List sortedList = new SortedDate212List();
      Date212GUI myGUI = new Date212GUI();

      //let the user know that they must provide file name as input
      if (args.length < 1) {
         System.out.println("Need to type in a file name!");
         System.exit(1);
      }

      //creates a type TextFileInput using the user input
      TextFileInput file = new TextFileInput(args[0]);
      //puts the return value(s) from the method readFileInput into a string array
      String[] strArray = readFileInput(file);

      //loop through the strArray and use it to create a Date212 object
      for (int i = 0; i < strArray.length; ++i) {
         Date212 myDate = new Date212(strArray[i]);

         //add the Date212 object into both sorted and unsorted list
         unsortedList.add(myDate);
         sortedList.add(myDate);
      }

      //set an iterator node to the first node of the two lists
      int length = strArray.length;
      Date212Node it1 = unsortedList.first;
      Date212Node it2 = sortedList.first;
      
      //loop 
      for (int i = 0; i < length; ++i) {
         //go to the next node, it iterates through the nodes in the list
         it1 = it1.next;
         it2 = it2.next;
         //append the iterator nodes' data to the GUI
         myGUI.leftSide.append(it1.data.toString());
         myGUI.rightSide.append(it2.data.toString());
      }

      //show the GUI
      myGUI.showGUI();
   }

   public static String[] readFileInput(TextFileInput inputFromMain) {
      ArrayList<String> listString = new ArrayList<String>();

      String read = inputFromMain.readLine();
      StringTokenizer tokens;

      // break the line of text into tokens using ","
      int j = 0;
      // run as long as string is not empty
      while (read != null) {
         tokens = new StringTokenizer(read, ",");

         // validate method
         if (validateFileInput(read) == false)
            System.out.println("Illegal file argument");

         // add the broken up pieces of the entire string until there are no more pieces
         while (tokens.hasMoreTokens()) {
            listString.add(tokens.nextToken());
            j++;
         }

         // keep reading from the file
         read = inputFromMain.readLine();
      }

      int length = listString.size();
      String[] arrayOfDates = new String[length];

      for (int i = 0; i < length; ++i) {
         arrayOfDates[i] = listString.get(i);
      }
      return arrayOfDates;
   }

   // validation method to see if the string contains digits or not
   public static boolean validateFileInput(String readInput) {
      if (readInput == null)
         return false;
      for (int i = 0; i < readInput.length(); ++i) {
         char testing = readInput.charAt(i);
         if (testing == ',')
            continue;
         if (!Character.isDigit(testing)) {
            System.out.println("Date must be only digits");
            return false;
         }
      }
      return true;
   }
}
