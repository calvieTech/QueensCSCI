public class LinkedListTest<E> {
    private Node<E> first, last;
    private int size = 0;

    // Creates an empty list.  It's your choice whether or not to use a dummy node.
    public LinkedListTest() {
        first = last = null;
    }

    // Adds the element to the end of the list.
    public void addLast(E e) {
        Node<E> temp = new Node<>(e, null);
        if(first == null) {
            first = temp;
        } else {
            last.next = temp;
            last = last.next;
        }


    }

    // Removes the first occurrence of the specified element, if it is present.
//    public void remove(E e) {
//
//
//
//
//
//
//    }

    public void print(){
        Node<E> temp = first;
        while (temp != null){
            System.out.print(temp.getE() + ", ");
            temp = temp.next;
        }
        System.out.println();
    }

    private static class Node<E> {
        E data;
        Node<E> next;
        Node(E data, Node<E> next) {
            this.data = data;
            this.next = next;
        }

        public E getE() {
            return data;
        }
    }

    public static void main(String[] args) {
        LinkedListTest<String> test = new LinkedListTest<String>();
        test.addLast("Calvin");
        test.addLast("Thang");
        test.print();



    }
}