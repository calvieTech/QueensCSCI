// Calvin Thang
// 11A
import java.util.TreeMap;
import javax.swing.*;
import java.awt.*;
import java.io.File;
import java.util.Map;

public class Date212GUI extends JFrame{
   
   // declare variables
   public JFrame myDate212GUI;
   public Container myContentPane;
   public TextArea myLeft;
   public TextArea myRight;
   public JMenuBar myMenuBar;
   public JMenu myFileMenu;
   public JMenu myEditMenu;
   public JMenuItem myItem;
   public FileMenuHandler fmh;
   public EditMenuHandler emh;
   UnsortedDate212List unsorted;
   TreeMap<Date212, Integer> sortedMap;

   //constructor
   public Date212GUI(){
      
      //methods to create the GUI
      setTitle("my Date212GUI");
      setSize(500,500);
      setLocation(400,200);
      setDefaultCloseOperation(WindowConstants.EXIT_ON_CLOSE);
      
      // method will create menu bar along with the menu items
      createFileAndEditMenu();
      setVisible(true);

   }
   
   // setter method
   public Date212GUI(UnsortedDate212List unsorted, TreeMap<Date212, Integer> sortedMap) {
      this.unsorted = unsorted;
      this.sortedMap = sortedMap;
   }
   
   public void displayDates() {
      //instantiate some objects to be used
      myDate212GUI = new JFrame();
      myContentPane = new Container();
      myLeft = new TextArea();
      myRight = new TextArea();
      
      // customize the GUI
      myDate212GUI.setSize(500,500);
      myDate212GUI.setLocation(400,200);
      myDate212GUI.setDefaultCloseOperation(WindowConstants.EXIT_ON_CLOSE);
      
      // create text area on the left and right side 
      myContentPane = myDate212GUI.getContentPane();
      myContentPane.add(myLeft, BorderLayout.WEST);
      myContentPane.add(myRight, BorderLayout.EAST);
      myLeft.setEditable(false);
      myRight.setEditable(false);
      
      // we need an iterator node to go through the unsorted list
      Date212Node iteratorNode = unsorted.first;
      
      // loop through the unsortedList with the iteratorNode 
      // and append its data to the myLeft text area
      for (int i = 0; i < unsorted.length; ++i) {
         iteratorNode = iteratorNode.next;
         myLeft.append(iteratorNode.data.toString() +"\n");
      }

      //get the key and value
      for (Map.Entry<Date212, Integer> start:  sortedMap.entrySet()) {
         myRight.append(start.getKey().toString() + "\t occurs " + start.getValue() + " times." + "\n");
      }
      
      //pack in the window size and set visible
      myDate212GUI.pack();
      myDate212GUI.setVisible(true);
      
      
   }
   
   //create menu
   private void createFileAndEditMenu() {
      myMenuBar = new JMenuBar();
      // create a new FileMenuHandler with a Date212GUI as its argument
      fmh = new FileMenuHandler(this);
      emh = new EditMenuHandler(this);
      myFileMenu = new JMenu("File");
      myEditMenu = new JMenu("Edit");
      
      
      
      // fileMenu is added onto the menu bar
      myMenuBar.add(myFileMenu);
      myMenuBar.add(myEditMenu);
      
      
      // create items "open" and "quit"
      myItem = new JMenuItem("Open");
      // add the item open onto the file Menu
      myFileMenu.add(myItem);
      // the fileMenuHandler will handle the events triggered by the user clicking on Open
      myItem.addActionListener(fmh);
      myFileMenu.addSeparator();
      myItem = new JMenuItem("Quit");
      myFileMenu.add(myItem);
      // the fileMenuHandler will handle the events triggered by the user clicking on Open
      myItem.addActionListener(fmh);
      
      //create item called Insert
      myItem = new JMenuItem("Insert");
      // Insert will be in myEditMenu
      myEditMenu.add(myItem);
      // emh will be the action listener for Insert
      myItem.addActionListener(emh);
      // set myMenuBar as the JMenuBar
      setJMenuBar(myMenuBar);
      
   }
   
   
   
   
   
   
}
