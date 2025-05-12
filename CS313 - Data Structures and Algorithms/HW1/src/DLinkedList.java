public class DLinkedList<E>{
    private static class DNode<E>{
        private E element;
        private DNode<E> prev;
        private DNode<E> next;
        public DNode() {
            prev = null;
            next = null;
        }
        public DNode(E e){
            this(e, null, null);
        }
        public DNode(E e, DNode<E> p, DNode<E> n){
            element = e;
            prev = p;
            next = n;
        }
        public E getE(){
            return element;
        }
        public DNode<E> getPrev(){
            return prev;
        }
        public DNode<E> getNext(){
            return next;
        }
        public void setE(E e){
            element = e;
        }
        public void setPrev(DNode<E> p){
            prev = p;
        }
        public void setNext(DNode<E> n){
            next = n;
        }
    }
    private DNode<E> head;
    private DNode<E> tail;
    private int size;
    public DLinkedList(){
        head = new DNode<E>();
        tail = new DNode<E>();

        tail.next = null;
        head.prev = null;
        tail.prev = head;
        head.next = tail;

        size = 0;
    }
    public void addFirst(E e){
        DNode<E> tempNode = new DNode<E>(e);
        tempNode.setNext(head.getNext());
        head.next.prev = tempNode;
        head.setNext(tempNode);
        tempNode.setPrev(head);
        size++;
}
    //fix
    public void addLast(E e){
        DNode<E> tempNode = new DNode<E>(e);
        tempNode.setNext(tail);
        tempNode.setPrev(tail.getPrev());
        tail.prev.next = tempNode;
        tail.setPrev(tempNode);
        size++;
    }
    public E at(int i) throws Exception{
        DNode<E> valueNode = new DNode<E>();
        int counter = 1;
        if(i < 0 || i >= size) {
            throw new Exception("Invalid Index");
        }

        if(i < size/2) {
            valueNode = head.getNext();
            while(counter <= i && valueNode != null) {
                valueNode = valueNode.getNext();
                counter++;
            }
            return valueNode.getE();
        } else {
            valueNode = tail.getPrev();
            counter = size;
            if(counter > i) {
                valueNode = valueNode.getPrev();
                counter--;
            }
            valueNode = valueNode.getPrev();
            return valueNode.getE();
        }
    }
    public void print(){
        DNode<E> temp = head.getNext();
        while (temp != tail){
            System.out.print(temp.getE() + ", ");
            temp = temp.getNext();
        }
        System.out.println();
    }

    public static void main(String argc[]){
        DLinkedList<String> ll = new DLinkedList<String>();
        ll.addFirst("Three");
        ll.addLast("Four");
        ll.addFirst("Two");
        ll.addFirst("One");
        ll.addLast("Five");
        ll.addFirst("Zero");
        ll.print();
        try {
            System.out.println("at 1: " + ll.at(1));
            System.out.println("at 2: " + ll.at(2));
            System.out.println("at 3: " + ll.at(3));
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}