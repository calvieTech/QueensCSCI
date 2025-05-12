// Calvin Thang
// 11A

import javax.swing.*;
import java.awt.*;
import java.io.File;

public class Date212GUI {
   
   // declare variables
   public JFrame myDate212GUI;
   public Container myContentPane;
   public TextArea myLeft;
   public TextArea myRight;
   public JMenuBar myMenuBar;
   public JMenu myFileMenu;
   public JMenuItem myItem;
   public FileMenuHandler fmh;

   //constructor
   public Date212GUI() {
      //instantiate some objects to be used
      myDate212GUI = new JFrame();
      myContentPane = new Container();
      myLeft = new TextArea();
      myRight = new TextArea();
      
      //methods to create the GUI
      myDate212GUI.setTitle("myDate212GUI");
      myDate212GUI.setSize(500, 500);
      myDate212GUI.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
      myDate212GUI.setLocation(250, 250);
      
      // create text area on the left and right side 
      myContentPane = myDate212GUI.getContentPane();
      myContentPane.add(myLeft, BorderLayout.WEST);
      myContentPane.add(myRight, BorderLayout.EAST);
      myLeft.setEditable(false);
      myRight.setEditable(false);
      
      // method will create menu bar along with the menu items
      createMenu();
      // make the GUI appear
      setVisible();
   }
   
   //create menu
   private void createMenu() {
      myMenuBar = new JMenuBar();
      // create a new FileMenuHandler with a Date212GUI as its argument
      fmh = new FileMenuHandler(this);
      myFileMenu = new JMenu("File");
      
      // fileMenu is added onto the menu bar
      myMenuBar.add(myFileMenu);
      // myMenuBar is set as the menu bar for the GUI
      myDate212GUI.setJMenuBar(myMenuBar);
      
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
   }
   
   // method that will show the GUI
   public void setVisible() {
      myDate212GUI.pack();
      myDate212GUI.setVisible(true);
   }
   
   
   
   
   
}
