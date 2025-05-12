//Calvin Thang
//Lab 11A

//the sorted list inherits from the abstract list
public class SortedDate212List extends Date212List {
   
   //call the super constructor
   public SortedDate212List() {
      super();
   }

   //add the node into the proper position in the sorted list 
   public void add(Date212 data) {
      //create an iterator node that is first of the list
      Date212Node myNode = new Date212Node(data);
      Date212Node iterator = first;

      //keep iterating through the nodes until we can find which nodes to put the myNode between in
      while(iterator.next != null && data.compareTo(iterator.next.data) > 0) {
        iterator = iterator.next;
      }

      //insert the new node between the current node and the next node
      myNode.next = iterator.next;
      iterator.next = myNode;
      this.length++;

      //check if we have to update the last node of the list
      if (iterator == this.first || iterator == this.last) {
        this.last = myNode;
      }
   }
}
