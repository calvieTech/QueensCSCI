// Calvin Thang
// 11A
import javax.swing.*;
import javax.swing.JFileChooser;
import javax.swing.JOptionPane;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener; 
import java.io.File;
import java.util.StringTokenizer;

// ActionListener is an interface that we need to do actionPerformed
public class FileMenuHandler implements ActionListener{
   // declare some variables
   private Date212GUI fileGUI;
   public JOptionPane jOP;

   // constructor
   public FileMenuHandler(Date212GUI gui) {
      jOP = new JOptionPane();
      // the fileGUI is set as the gui in the parameter
      fileGUI = gui;
   }
   
   // do something when the an event happens
   @Override
   public void actionPerformed(ActionEvent event) {
      String menuName = new String();
      // get the name of the item that was called
      menuName = event.getActionCommand();
      
      // open file if user clicks open, quit program if user clicks quit
      if (menuName.equals("Open")) {
         this.openFile();
      } else if (menuName.equals("Quit")) {
         jOP.showMessageDialog(null, "You clicked on Quit!");
         System.exit(0);
      }
   }
   
   // method that is performed when user clicks on Open
   public void openFile() {
      int returnVal;
      // to help us allow the user to have options to choose from
      JFileChooser chooser = new JFileChooser();
      // show the files that the user can choose from
      returnVal = chooser.showOpenDialog(null);
      
      // if user clicks on a file, read the file that the user selected
      if (returnVal == JFileChooser.APPROVE_OPTION) {
         readFile(chooser.getSelectedFile());  
         // if user clicks cancel option, show a message saying that the action was cancelled
      } else if (returnVal == JFileChooser.CANCEL_OPTION) {
         jOP.showMessageDialog(null, "Action Cancelled");
      }
   }
   
   //method to read the file that user selected
   private void readFile(File selectedFile) {
      //declare some variables
      String newDate = new String();
      int index = 0;
      StringTokenizer tokens;
      UnsortedDate212List unsortedList = new UnsortedDate212List();
      SortedDate212List sortedList = new SortedDate212List();
      String userSelectedFile = selectedFile.getName();
      // we want the file that the user selected
      TextFileInput myFile = new TextFileInput(userSelectedFile);
      // make that file into a String
      String date = myFile.readLine(); 

      
      //loop until the end of the string
      while (date != null) {
         tokens = new StringTokenizer(date, ",");
         // loop until there are no more tokens
         while (tokens.hasMoreTokens()) {
            try {
               // get the next token in the list of tokens
               newDate = tokens.nextToken();
               // create a Date212 object from the tokens
               Date212 myDate = new Date212(newDate);
               // add into the sorted/unsorted list
               unsortedList.add(myDate);
               sortedList.add(myDate);
               // if you catch an exception, print to console
            } catch (Date212Exception e) {
               System.out.println(newDate + " is not a valid date");
            }
         }
         
       //date keeps reading lines
         date = myFile.readLine();
      }
      
      //create iterator nodes
      Date212Node iteratorNode1 = unsortedList.first;
      Date212Node iteratorNode2 = sortedList.first;
      
      //loop 
      for (int i = 0; i < unsortedList.length; ++i) {
         //go to the next node, it iterates through the nodes in the list
         iteratorNode1 = iteratorNode1.next;
         iteratorNode2 = iteratorNode2.next;
         //append the iterator nodes' data to the GUI
         fileGUI.myLeft.append(iteratorNode1.data.toString());
         fileGUI.myRight.append(iteratorNode2.data.toString());
      }
   }
   
}