// Calvin Thang
// 11A

import java.util.TreeMap;

public class Project4 {
   private static Date212GUI myGUI;
   private static UnsortedDate212List unsortedList = new UnsortedDate212List();
   private static TreeMap<Date212, Integer> sortedMap = new TreeMap<>(new Date212Comparator());
   
   // program starts from here
   public static void main(String[] args) {
      //create a Date212GUI named object
      myGUI = new Date212GUI();
   }

//getter methods
public static UnsortedDate212List getUnsorted() {
   return unsortedList;
}

public static TreeMap<Date212, Integer> getSortedMap() {
   return sortedMap;
}

//setter methods
public static void setUnsorted(UnsortedDate212List unsorted) {
   unsortedList = unsorted;
}

public static void setSortedMap(TreeMap<Date212,Integer> sorted) {
   sortedMap = sorted;
}









}

