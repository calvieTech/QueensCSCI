/**
 * Student: Calvin Thang
 */
public class DLinkedListTC<E>{

    // DNode class
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
    //DLinkedList instance variables
    private DNode<E> header;
    private DNode<E> trailer;
    private int size;

    //DLinkedList constructor
    public DLinkedListTC(){
        header = new DNode<E>(null);
        trailer = new DNode<E>(null, header, null);
        header.setNext(trailer);
        size = 0;
    }

    //adds a Node to the front of the list
    public void addFirst(E e){
        DNode<E> headerNext = header.getNext();
        DNode<E> tempN = new DNode <E>(e, header, headerNext);
        headerNext.setPrev(tempN);
        header.setNext(tempN);
        size++;
    }

    //adds a Node to the end of the list
    public void addLast(E e){
        DNode<E> trailerPrev = trailer.getPrev();
        DNode<E> temp = new DNode<E>(e, trailerPrev, trailer);
        trailer.setPrev(temp);
        trailerPrev.setNext(temp);
        size++;
    }

    // get data at the index i
    public E get(int i) throws Exception{
        DNode<E> valueNode = new DNode<E>();
        int counter = 1;

        // if index is invalid, throw exception
        if(i < 0 || i >= size) {
            throw new Exception("Invalid Index");
        }

        //traverse from the head if i is less than half of the size of the list
        // else, traverse from the end of the tail
        if(i < size/2) {
            valueNode = header.getNext();
            while(counter <= i && valueNode != null) {
                valueNode = valueNode.getNext();
                counter++;
            }
            return valueNode.getE();
        } else {
            valueNode = trailer.getPrev();
            counter = size;
            if(counter > i) {
                valueNode = valueNode.getPrev();
                counter--;
            }
            valueNode = valueNode.getPrev();
            return valueNode.getE();
        }
    }

    //print method
    //TODO: print from highest degree to lowest
    public void print(){
        DNode<E> temp = header.getNext();
        while (temp != trailer){
            System.out.print(temp.getE() + ", ");
            temp = temp.getNext();
        }
        System.out.println();
    }

    //main method, begin here
    public static void main(String argc[]){
        DLinkedListTC<String> l = new DLinkedListTC<String>();
        l.addFirst("Three");
        l.addLast("Four");
        l.addFirst("Two");
        l.addFirst("One");
        l.addLast("Five");
        l.addFirst("Zero");
        l.print();
        try {
            System.out.println("at 1: " + l.get(1));
            System.out.println("at 2: " + l.get(2));
            System.out.println("at 3: " + l.get(3));

            System.out.println("at 6: " + l.get(6));
        }
        catch (Exception e) {
            System.out.println(e.getMessage());
        }
    }
}