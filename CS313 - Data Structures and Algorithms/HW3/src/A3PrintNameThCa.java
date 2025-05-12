/**
 * Student: Calvin Thang
 *
 */

import java.io.*;
import java.util.*;

public class A3PrintNameThCa{
    public static List<String> readInFile(String filename){
        List<String> input = new ArrayList<>();
        try (Scanner sin = new Scanner(new FileReader(filename))){
            while (sin.hasNextLine()){
                input.add(sin.nextLine());
            }
        } catch (FileNotFoundException e){
            e.printStackTrace();
        }
        return input;
    }
    public static void main(String[] args){
        List<String> names = readInFile("/Users/calvin/Desktop/School/CS313/HW3/src/A3Input.txt");

        // let key be the length of each name and the values be a list of names
        Map<Integer, List<String>> myMap = new TreeMap<>();
        for(Iterator<String> it = names.iterator(); it.hasNext();) {
            String myName = it.next();
            List<String> myTree = myMap.containsKey(myName.length()) ? myMap.get(myName.length()) : new ArrayList<>();
            myTree.add(myName);
            if(myName.length() > 0) myMap.put(myName.length(), myTree);
        }
        for(Map.Entry<Integer, List<String>> myEntry : myMap.entrySet()) {
            List<String> tempList = myEntry.getValue();
            String myString = "";

            for(String s : tempList) {
                myString += (s +  "\t");
            }
            System.out.println("String length " + myEntry.getKey() + ": " + myString);
        }
    }
}
