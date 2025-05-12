//Calvin Thang
//Lab 11A

//the class inherits from the super class Date212List
public class UnsortedDate212List extends Date212List {

   //constructor for this object calls the super class constructor
   public UnsortedDate212List() {
        super();
   }
   
   //this method calls the super class' method append
   public void add(Date212 item) {
      super.append(item);
   }
}
