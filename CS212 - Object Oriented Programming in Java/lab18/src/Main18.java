public class Main18
{
    public static void main(String[] args)
    {
        // Test cases
        SortedLinkedList list = new SortedLinkedList();
        Money m = null;
        System.out.printf("Linked list before inserting: %s\n", list);
        
        m = new Money(2, 44);
        list.insert(m);
        System.out.printf("Inserting %s: %s\n", m, list);

        m = new Money(6, 01);
        list.insert(m);
        System.out.printf("Inserting %s: %s\n", m, list);

        m = new Money(3, 99);
        list.insert(m);
        System.out.printf("Inserting %s: %s\n", m, list);

        m = new Money(4, 50);
        list.insert(m);
        System.out.printf("Inserting %s: %s\n", m, list);

        m = new Money(0, 44);
        list.insert(m);
        System.out.printf("Inserting %s: %s\n", m, list);
    }
}