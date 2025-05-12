public class LinkedList
{
    // Internal nodes of linked list should be private so users of this class
    // cannot make grave changes to this linked list
    private Node head;
    private Node tail;

    // The length of the linked list may be public
    public int length;

    public LinkedList()
    {
        this.head = new Node("dummy"); 
        this.tail = this.head;
        this.length = 0;
    }

    // Add to the end of the linked list
    public void append(String data)
    {
        // Create new node
        Node newNode = new Node(data); 
        
        // Make the tail node's next node point to the new node
        this.tail.next = newNode;

        // Set the tail node to point to the new node
        this.tail = newNode; 

        // Increment the length property of this linked list
        this.length++;
    }

    // Add to the beginning of the linked list
    public void prepend(String data)
    {
        // Create new node
        Node newNode = new Node(data); 

        // Set the new node's next node to point to whatever the head node's next node is
        newNode.next = this.head.next; 

        // Make the head's next node point to the new node
        this.head.next = newNode; 

        // If tail == head, then we need to move tail as well.
        // This only happens if linked list is empty
        if (tail == head) tail = newNode;

        // Increment the length property of this linked list
        this.length++;
    }

    // Override the toString method we inherit from class Object
    @Override
    public String toString()
    {
        // Create the StringBuilder we'll use to append every node's data to
        StringBuilder sb = new StringBuilder();

        // Iterate through linked list until we hit null, adding the string 
        // that's inside each node to the StringBuilder
        for (Node i = head.next; i != null; i = i.next)
        {
            sb.append(i.toString() + "->");
        }
    
        // Add to the StringBuilder the last string
        sb.append("null");

        // Return the string representation of the StringBuilder
        return sb.toString();
    }
}