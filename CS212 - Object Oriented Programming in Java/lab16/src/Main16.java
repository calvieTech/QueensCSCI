public class Main16
{
    public static void main(String[] args)
    {
        // Test cases
        LinkedList list = new LinkedList();
        System.out.printf("Contents of linked list before inserting: %s\n", list.toString());

        list.prepend("a");
        System.out.printf("Prepended 'a': %s\n", list.toString());

        list.append("b");
        System.out.printf("Appended  'b': %s\n", list.toString());

        list.append("c");
        System.out.printf("Appended  'c': %s\n", list.toString());

        list.prepend("d");
        System.out.printf("Prepended 'd': %s\n", list.toString());

        list.append("e");
        System.out.printf("Appended  'e': %s\n", list.toString());

        list.prepend("f");
        System.out.printf("Prepended 'f': %s\n", list.toString());

        list.prepend("g");
        System.out.printf("Prepended 'g': %s\n", list.toString());
    }
}