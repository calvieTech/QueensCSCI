import java.util.Comparator;
import java.io.Serializable;
import java.lang.Comparable;

// to help us customize how to compare 
public class Date212Comparator implements Comparator<Date212>{
   
   @Override
   public int compare(Date212 obj1, Date212 obj2) {
      return obj1.compareTo(obj2);
   }
   
}