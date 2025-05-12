// Calvin Thang
// Lab 11A

import javax.swing.JOptionPane;

public class Project0 {
   public static void main(String args[]) {
	
		// ask user for input and store the sentence as a string
		String sentence = JOptionPane.showInputDialog(null, "Type in a sentence: ");
		
		// loop keeps going until user types "stop" regardless of case sensitivity
		while (!sentence.equalsIgnoreCase("Stop")) {
		   //initialize counter to 0 to get accurate counter
			int counterUpperCase = 0;
			int counterLowerCase = 0;
		
		   //iterate through user input string going from character to character
			for (int i = 0; i < sentence.length(); ++i) {
			   
			   //add 1 to counter if array index value matches the character e or E
				if (sentence.charAt(i) == 'E') {
					counterUpperCase += 1;
				}
				if (sentence.charAt(i) == 'e') {
					counterLowerCase += 1;
				}
			} // end of for loop
		
			//display message with the updated counter
			JOptionPane.showMessageDialog(null, "Number of lower-case e's: " + counterLowerCase + "\n" + "Number of upper-case e's: " + counterUpperCase);
			//ask user for input again and goes back to the start of the loop
			sentence = JOptionPane.showInputDialog(null, "Type in a sentence: ");
		}
		System.exit(0);
	}
}