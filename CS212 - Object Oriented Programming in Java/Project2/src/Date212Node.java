//Calvin Thang
//Lab 11A

//class for the Date212Node
public class Date212Node {

   //we make these protected so that user can't access them
   protected Date212 data;
   protected Date212Node next;

   //constructor for the Date212Node with a Date212 object parameter type
   public Date212Node(Date212 otherData) {
      //set this object's data to the other data that we passed
      data = otherData;
      //make the link point towards null
      next = null;
   }

}
