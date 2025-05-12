/**
 * Student: Calvin Thang
 */
public class PolynomialLinkedListTC{

    private static class PNode{
        //instance variables
        private int coe;
        private int exp;
        private PNode next;

        //Non-default constructor
        public PNode(int c, int e){
            this(c, e, null);
        }
        //this constructor sets next to n rather than to null
        public PNode(int c, int e, PNode n){
            coe = c;
            exp = e;
            next = n;
        }

        //setter and getter methods
        public void setCoe(int c){ coe = c;}
        public void setExp(int e){ exp = e;}
        public void setNext(PNode n){ next = n;}
        public int getCoe(){ return coe;}
        public int getExp(){ return exp;}
        public PNode getNext(){ return next;}
    }

    private PNode head;
    //constructor for the PolynomialLinkedList
    public PolynomialLinkedListTC(){
        head = null;
    }

    /**
     * Adds a term into the PolynomialLinkedList (i.e. 2x^2 is added)
     * @param c
     * @param e
     * @return nothing
     */
    private void add(int c, int e){
        PNode tempn = new PNode(c, e, head);
        head = tempn;
    }

    /**
     * Add like terms of a polynomial
     * @param no parameters
     * @return nothing but method
     */

    public void removeDuplicate(){
        if (head == null) return;
        PNode lookUp, checkPrev;
        lookUp = checkPrev = head;
        while (lookUp.getNext() != null){
            while (checkPrev.getNext() != null){
                if (checkPrev.getNext().getExp() == lookUp.getExp()){//found a duplicate
                    //lookUp.coe += checkPrev.next.coe;
                    lookUp.setCoe(lookUp.getCoe() + checkPrev.getNext().getCoe()); //add the coe of lookUp and the node after it
                    checkPrev.setNext(checkPrev.getNext().getNext());
                }
                else checkPrev = checkPrev.getNext();
            }
            lookUp = lookUp.getNext();
            checkPrev = lookUp;
        }
    }

    /**
     * Computes the addition operation of two polynomials
     * @param pl
     * @return A new PolynomialLinkedList with the sum of two polynomials
     */
    public PolynomialLinkedListTC add(PolynomialLinkedListTC pl){
        PNode addTerm = this.head;
        PolynomialLinkedListTC ans = new PolynomialLinkedListTC();
        for (int i = 0; i < 2; i++){
            while (addTerm != null){
                ans.add(addTerm.getCoe(), addTerm.getExp());
                addTerm = addTerm.next;
                }
            addTerm = pl.head;
        }
        ans.removeDuplicate();
        return ans;
    }

    /** multiple two polynomials by:
     *  1) Multiplying the coefficients
     *  2) Adding the exponents
     * @param pl
     * @return PolynomialLinkedListTC
     */
    public PolynomialLinkedListTC multiply(PolynomialLinkedListTC pl){
        PolynomialLinkedListTC ans = new PolynomialLinkedListTC();
        PNode iterator = this.head;
        while (iterator != null) {
            PNode iterator2 = pl.head;
            while(iterator2 != null) {
                ans.add(iterator.getCoe() * iterator2.getCoe(), iterator.getExp() + iterator2.getExp());
                iterator2 = iterator2.getNext();
            }
            iterator = iterator.getNext();
        }
        ans.removeDuplicate();
        return ans;
    }

    /**
     * print method for the polynomials
     * @param nothing
     * @return nothing but prints out to console
     */
    public void print(){
        // if list is empty, print nothing and return
        if (head == null){
            System.out.println();
            return;
        }
        removeDuplicate();
        PNode temp = head;

        //iterate through the polynomial linked list starting from the beginning
        while (temp.getNext() != null) {
            if (temp.getCoe() != 0) {
                System.out.print("(" + temp.getCoe() + ")");
                if (temp.getExp() != 0) {
                    System.out.print("X^" + temp.exp);
                }
                System.out.print(" + ");
            }
            temp = temp.next;
        }
        if (temp != null){
            System.out.print(temp.coe);
            if (temp.exp != 0) System.out.print("X^" + temp.exp);
            System.out.println();
        }
    }

    public static void main(String argc[]){
        PolynomialLinkedListTC pn1 = new PolynomialLinkedListTC();
        PolynomialLinkedListTC pn2 = new PolynomialLinkedListTC();
        pn1.add(1, 2);
        pn1.add(2, 3);
        pn2.add(1, 0);
        pn2.add(5, 1);
        pn2.add(-6, 1);
        pn2.add(4, 2);
        System.out.print("Polynomial 1: ");
        pn1.print();
        System.out.print("Polynomial 2: ");
        pn2.print();
        PolynomialLinkedListTC sum = pn1.add(pn2);
        PolynomialLinkedListTC prod = pn1.multiply(pn2);
        System.out.print("Sum: ");
        sum.print();
        System.out.print("Product: ");
        prod.print();
    }
}