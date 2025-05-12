/***************************************************************
 * 
 * @author K. Lord A program that works with two-dimension arrays.
 *
 */
public class Main10 
{
    private static int[][] matrix;

    public static void main(String[] args) 
    {
        matrix = new int[6][4];
        fillMatrix(matrix, 5);
        System.out.println(sumMatrix(matrix));
    }

    /**
     * Each cell of an integer matrix is filled with the given value.
     * 
     * @param m The matrix to be filled
     * @param v The value to fill in each cell
     */
    public static void fillMatrix(int[][] m, int v) 
    {
        for (int i = 0; i < m.length; i++)
            for (int j = 0; j < m[i].length; j++)
                m[i][j] = v;
    }
    
    /**
     * Will increase the value of each cell in the matrix
     * 
     * @param m The matrix that we are adding to
     * @param v The value we are adding to the matrix
     * 
     */
    
    public static void fillMatrixSeq(int[][] m, int v) 
    {
        for (int i = 0; i < m.length; i++)
            for (int j = 0; j < m[i].length; j++)
                m[i][j] = v;
    }
    
    /**
     * Adding the values of all of the cells in the matrix
     * @param m The matrix whos values we will add up
     * @return An integer representing the sum of the matrix cells
     */

    public static int sumMatrix(int[][] m) 
    {
        int sum = 0;
        for (int i = 0; i < m.length; i++)
            for (int j = 0; j < m[i].length; j++)
                sum += m[i][j];
        return sum;
    }

    /**
     * Returns the sum of every entry of a given row
     * 
     * @param m The matrix to run the sum on
     * @param row The row to be summed from the matrix
     * @return An integer representing the sum of a row
     */
    public static int sumMatrixRow(int[][] m, int row) 
    {
        int sum = 0;
        for (int i = 0; i < m.length; i++)
            sum += m[row][i];
        return sum;
    }
}