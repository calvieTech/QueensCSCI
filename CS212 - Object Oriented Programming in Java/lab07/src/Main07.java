import java.util.Arrays;
import java.util.Scanner;
import java.io.FileReader;


public class Main07 
{

    // Global static variable
    public static int[][] myArray;

    public static void main(String[] args) 
    {
        // Initialize the global static variable, 'myArray'
        myArray = fillArray(args[0]);
        
        // Use methods to print out formatted output
        printArray(myArray);
        System.out.println(); // To seperate output
        printArrayEven(myArray);
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

    private static void printArrayEven(int[][] theArray) 
    {
        for (int i = 0; i < theArray.length; ++i) {
           for (int r = 0; r < theArray[i].length; ++r) {
              if (theArray[i][r] % 2 != 0) {
                 System.out.print("*\t");
              } else {
                 System.out.print(theArray[i][r] + "\t");
              }
           }
           System.out.println();
        }
    }

    private static int[][] fillArray(String myFile) 
    {
       TextFileInput file = new TextFileInput(myFile);
       String read = file.readLine();
       
       int row = Integer.parseInt(read);
       read = file.readLine();
       int col = Integer.parseInt(read);
       int arrayOfIntegers[][] = new int[row][];
       
       for (int i = 0; i < row; ++i) {
          arrayOfIntegers[i] = new int[col];
       }
       
       try {
          
          for (int r = 0; r < arrayOfIntegers.length; r++) {
             for (int c = 0; c < arrayOfIntegers[r].length; c++) {
                read = file.readLine();
                arrayOfIntegers[r][c] = Integer.parseInt(read);
             }
          }
       } catch (IllegalArgumentException notInteger) {
          System.out.println("Not an integer");
          System.exit(1);
       }
       return arrayOfIntegers;
    }
    
    
    /*
    private static int[][] fillArrayAlternate(String fileName) {
       Scanner reader = new Scanner(System.in);
       
       FileReader file = new FileReader(fileName);
       
       
       
       
       
       
    }
    */
    
    
    
    
    
    
    
}