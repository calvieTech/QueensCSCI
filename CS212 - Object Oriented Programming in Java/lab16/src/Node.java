public class Node
{
    // Public instance variables
    public String data;
    public Node next;

    // Default constructor
    public Node()
    {
        this("dummy node!", null);
    }

    // Constructor that takes only the data as a parameter
    public Node(String data)
    {
        this(data, null);
    }

    // Constructor that takes in the data and another node as parameters
    public Node(String data, Node next)
    {
        this.data = data;
        this.next = next;
    }

    // Override the toString method we inherit from class object
    @Override
    public String toString()
    {
        return String.format("(%s)", this.data);
    }
}