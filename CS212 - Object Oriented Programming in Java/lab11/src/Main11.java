
import java.awt.GridLayout;
import javax.swing.*;        

public class Main11 {
    
   public static void main(String[] args) {
        createAndShowGUI();
   }
   
   private static void createAndShowGUI() {
        //Create and set up the window.
        JFrame frame = new JFrame("HelloWorldSwing");
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setSize( 100,100);//width, height);
        frame.setLocation(200,200);//x, y);
        frame.setLayout(new GridLayout(2,1));

        JTextArea textArea = new JTextArea(5, 20);
        textArea.setEditable(false);
        JScrollPane scrollPane = new JScrollPane(textArea);
        frame.getContentPane().add(scrollPane);
        JLabel label = new JLabel("The sum of the numbers in the matrix is: ");
        frame.getContentPane().add(label);

        textArea.setText("The matrix should print here: \n");
        
        //Display the window.
        frame.pack();
        frame.setVisible(true);
        
        readAndDisplayMatrix(frame, textArea, label);
    }
   
   private static void readAndDisplayMatrix(JFrame myFrame, JTextArea myText,
                                            JLabel myLabel) {
   /*
    * Fill in this method.   
    * It should fill the text area with the matrix (as you did to a
    * message dialog in a previous lab, calculate the sum (code from
    * a previous lab) and set the text of the label to show the sum.
    * Re-display the JFrame using the setVisible(true) method. The
    * matrix is given here.
    */
   
   int[][] myMatrix = {{1,2,3,4},{4,5,6,7},{7,8,9,10}};
   
   
   int sum = 0;
   myText.append("\n");
   for (int i = 0; i < myMatrix.length; ++i) {
      for (int j = 0; j < myMatrix[i].length; ++j) {
         sum += myMatrix[i][j];
         String text = Integer.toString(myMatrix[i][j]);
         myText.append(text + "\t");
      }
      myText.append("\n");
   }
   
   
   myLabel.setText("The sum of the numbers in the matrix is: " + Integer.toString(sum));
   myFrame.setTitle("Main11");
   myFrame.pack();
   myFrame.setVisible(true);
   }

        
}