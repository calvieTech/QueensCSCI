//Calvin Thang
//Lab 11A

//need to import these files to create a GUI
import javax.swing.*;
import java.awt.*;


public class Date212GUI {
   // declare these variables that we will use
   public JFrame myDate212GUI;
   public Container myContentPane;
   public TextArea leftSide;
   public TextArea rightSide;

   public Date212GUI() {
      // instantiates the objects
      myDate212GUI = new JFrame();
      myContentPane = new Container();
      leftSide = new TextArea();
      rightSide = new TextArea();

      // changes attributes for the myDate212GUI
      myDate212GUI.setSize(500, 500);
      myDate212GUI.setLocation(200, 300);
      myDate212GUI.setTitle("Date212 GUI");
      myDate212GUI.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

      // creates a left side and right side in the content pane
      myContentPane = myDate212GUI.getContentPane();
      myDate212GUI.setLayout(new GridLayout(1, 2));
      myContentPane.add(leftSide);
      myContentPane.add(rightSide);
   }

   // method that shows the GUI
   public void showGUI() {
      myDate212GUI.pack();
      myDate212GUI.setVisible(true);
   }

}
