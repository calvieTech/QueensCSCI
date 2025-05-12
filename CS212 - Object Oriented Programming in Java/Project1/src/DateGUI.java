//Calvin Thang
//Lab 11A

import javax.swing.*;
import java.awt.*;

public class DateGUI {
   //instance variables that we may want to refer to
   public JFrame myFrame;
   public Container cPane;
   public TextArea left, right;
   

   
   
   //Constructor for DateGUI object
   public DateGUI() {
      myFrame = new JFrame();
      cPane = new Container();
      left = new TextArea();
      right = new TextArea();
      cPane = myFrame.getContentPane();
      
      //build the JFrame
      myFrame.setSize(500, 500);
      myFrame.setLocation(200, 200);
      myFrame.setTitle("Project 1");
      //1 row, 2 cols
      cPane.setLayout(new GridLayout(1,2));
      
      //so user doesn't change textbox
      left.setEditable(false);
      right.setEditable(false);
      //add the left/right text area in content pane
      cPane.add(left);
      cPane.add(right);
      
      myFrame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

   }
   
   public Container getContentPane() {
      return cPane;
   }
   

   
   
   
   
   
   
}