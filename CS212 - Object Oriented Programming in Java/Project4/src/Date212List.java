//Calvin Thang
//Lab 11A

//abstract class so we can't instantiate any objects from it
abstract public class Date212List {
   protected Date212Node first;
   protected Date212Node last;
   public int length;

   // constructor for the Date212List
   public Date212List() {
      // creates a new Node that has empty data
      Date212Node head = new Date212Node(null);
      // set the first and last of the list to the Node with empty data
      first = head;
      last = head;
      length = 0;
   }

   // appends a node at the end of the list
   public void append(Date212 data) {
      // creates a new Node that has the data which is of Date212 type
      Date212Node myNode = new Date212Node(data);
      // set the link of the last node in this list to point towards the new Node
      last.next = myNode;
      // the last node in this list becomes the new node we created in line 23
      last = myNode;
      // increase the length by 1
      length++;
   }
   

}
