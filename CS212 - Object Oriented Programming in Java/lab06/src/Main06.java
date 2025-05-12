
// Import libraries from the JDK so we can use them throughout the program
import javax.swing.JOptionPane;
import java.util.ArrayList;
import java.util.Arrays;

public class Main06 
{
    public static void main(String[] args) 
    {
        // Declare our variables
        int[] inputArray;
        TextFileInput input;
        int sum, average;

        // Checks to see if user put in a file name
        if (args.length < 1) {
      	  System.out.println("Must type a file name");
      	  System.exit(1);
        }
        
        input = new TextFileInput(args[0]);
        inputArray = inputFromFile(input);
        
        
        System.out.println("Not sorted: " + Arrays.toString(inputArray));
        selectionSort(inputArray);
        System.out.println("Sorted: " + Arrays.toString(inputArray));
        
        sum = sum(inputArray);
        average = average(inputArray);
        System.out.println("Sum: " + sum);
        System.out.println("Average: " + average);
        
        
        
        
    }

    public static boolean wordIsThere(String findMe, String[] theList) 
    {
        for (int i = 0; i < theList.length; i++) 
        {
            if (findMe.equals(theList[i]))
                return true;
        }
        return false;
    }

    public static int sum(int[] input)
    {
        // Calculates the sum of the input parameter
   	 int length = input.length;
   	 int sum = 0;
   	 for (int i = 0; i < length; ++i) {
   		 sum += input[i];
   	 }
   	 return sum;
    }

    public static int average(int[] input)
    {
        // Calculates the average of the input parameter
   	 int total = sum(input);
   	 int length = input.length;
   	 return total / length;
    }

    public static int[] inputFromFile(TextFileInput input) 
    {
        // Returns an integer array from input
   	 ArrayList<Integer> stringArrayList = new ArrayList<Integer>();
   	 String read = input.readLine();
   	 
   	 while (read != null) {
   		 int num = Integer.parseInt(read);
   		 stringArrayList.add(num);
   		 read = input.readLine();
   	 }
   	 
   	 int length = stringArrayList.size();
   	 int integerArray[] = new int[length];
   	 for (int i = 0; i < length; ++i) {
   		 integerArray[i] = stringArrayList.get(i);
   	 }
   	return integerArray;
    }
    

    // Sort an integer array from least to greatest
    public static void selectionSort(int[] input) 
    {
        for (int i = 0; i < input.length; i++) 
        {
            int smallestIndex = i;
            for (int j = i + 1; j < input.length; j++) 
            {
                if (input[j] < input[smallestIndex]) 
                {
                    smallestIndex = j;
                }
            }
            swap(input, i, smallestIndex);
        }
    }

    // Swap elements in an integer array
    public static void swap(int[] input, int i, int j) 
    {
        int temp = input[i];
        input[i] = input[j];
        input[j] = temp;
    }
}