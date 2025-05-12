// Import libraries from the JDK so we can use them throughout the program
import java.util.StringTokenizer;
import java.util.Arrays;


public class Main08 
{
    // Global static variable
    public static int[][] myArray;

    public static void main(String[] args) 
    {
        // Initialize the global static variable, 'myArray'
        myArray = fillArray(args[0]);

        // Use methods to print out formatted output
        printArray(myArray);
    }

    private static void printArray(int[][] theArray) 
    {
        for (int i = 0; i < theArray.length; i++) 
        {
            for (int j = 0; j < theArray[i].length; j++)
                System.out.printf("%d\t", theArray[i][j]); // '\t' is short for 'tab'

            System.out.println(); // Go to next line after printing row
        }
    }

    private static int[][] fillArray(String myFile) 
    {
        // convert from file to a 2D array
       TextFileInput file = new TextFileInput(myFile);
       String rowsAndCols = file.readLine();
       
       //
       StringTokenizer tokens = new StringTokenizer(rowsAndCols, ",");
       int row = Integer.parseInt(tokens.nextToken(","));
       int col = Integer.parseInt(tokens.nextToken());
       int arraySolution[][] = new int[row][col];
       
       
       
       for (int r = 0; r < arraySolution.length; ++r) {
          String read = file.readLine();
          tokens = new StringTokenizer(read, ",");

          for (int c = 0; c < arraySolution[r].length; ++c) {
             try {
                int number = Integer.parseInt(tokens.nextToken(","));
                arraySolution[r][c] = number;
             } catch (NumberFormatException e) {
                e.printStackTrace();
             }
          }
       }
       
        return arraySolution;
    }

}