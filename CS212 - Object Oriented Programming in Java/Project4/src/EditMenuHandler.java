import javax.swing.*;
import javax.swing.JFileChooser;
import javax.swing.JOptionPane;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener; 
import java.io.File;
import java.util.TreeMap;

public class EditMenuHandler implements ActionListener{
   public Date212GUI emhGUI;
   public JOptionPane jOP;
   
   
   EditMenuHandler(Date212GUI gui) {
      jOP = new JOptionPane();
      emhGUI = gui;
      
   }
   
   @Override
   public void actionPerformed(ActionEvent event) {
      String itemName = new String();
      UnsortedDate212List unsorted = Project4.getUnsorted();
      TreeMap<Date212,Integer> sortedMap = Project4.getSortedMap();
      
      // get the name of the event
      itemName = event.getActionCommand();
      
      // repeatedly ask the user to put in a date until he or she types in done
      if (itemName.equals("Insert")) {
         while(true) {
            String insertDate = JOptionPane.showInputDialog(null, "Please type in a date (YYYY/MM/DD). Type in 'done' when finished");
            if (insertDate.equalsIgnoreCase("done")) 
               break;
            //call the method to update the Lists
            updateLists(unsorted, sortedMap, insertDate);
         }
         //make a new GUI with the unsorted/sortedMap
         Date212GUI gui = new Date212GUI(unsorted, sortedMap);
         gui.displayDates();
      }
   }
   
   // we want to update the unsortedList and sortedMap with the inputDate
   public static void updateLists(UnsortedDate212List unsorted, TreeMap<Date212, Integer> sortedMap, String inputDate) {

      try {
         //might give us an exception so its in a try-catch block
         Date212 myDate = new Date212(inputDate);
         // add myDate into unsorted
         unsorted.add(myDate);
         // if sortedMap already has myDate, put it in and +1 its occurances
         if (sortedMap.containsKey(myDate))
            sortedMap.put(myDate, sortedMap.get(myDate) + 1);
         else
            sortedMap.put(myDate, 1);
      } catch (Date212Exception e) {
         System.out.println(inputDate + " is not a valid date!");
      }
      //update the main unsorted/sortedMap
      Project4.setUnsorted(unsorted);
      Project4.setSortedMap(sortedMap);
   }
}