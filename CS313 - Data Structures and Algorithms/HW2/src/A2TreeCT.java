import java.util.*;

public class A2TreeCT {
    //beginning of TNode class
    private static class TNode {
        private int data;
        private TNode parent;
        private List<TNode> children;

        public TNode() {
            this(0, null);
        }

        public TNode(int e) {
            this(e, null);
        }

        public TNode(int e, TNode p) {
            data = e;
            parent = p;
            children = new ArrayList<TNode>();
        }

        public int getData() {
            return data;
        }

        public TNode getParent() {
            return parent;
        }

        public List<TNode> getChildren() {
            return children;
        }
    }

    //class Tree data members and methods
    private TNode root;
    private int size;

    A2TreeCT() {
        root = null;
        size = 0;
    }

    public TNode createNode(int e, TNode p) {
        return new TNode(e, p);
    }

    public TNode addChild(TNode n, int e) {
        TNode temp = createNode(e, n);
        n.children.add(temp);
        size++;
        return temp;
    }

    public TNode addRoot(int e) throws IllegalArgumentException {
        if (root != null) throw new IllegalArgumentException("Root is full");
        root = createNode(e, null);
        size++;
        return root;
    }

    public void levelOrder() {
        Queue<TNode> queue = new LinkedList<>();
        //create queue, add root to queue
        if (this.root != null) {
            queue.add(this.root);
        }
        System.out.print("levelOrder: ");
        TNode tempNode = queue.poll();
        while (tempNode != null) {
            System.out.print(tempNode.getData() + " ");
            queue.addAll(tempNode.getChildren());
            tempNode = queue.poll();
        }
//      levelOrderPrint(queue);
        System.out.println();
    }

    public void preOrder() {
        System.out.print("preOrder: ");
        preOrderPrint(root);
        System.out.println();
    }

    private void preOrderPrint(TNode n) {
        if (n == null) return;
        System.out.print(n.getData() + " ");
        for (TNode cn : n.getChildren())
            preOrderPrint(cn);
    }

    public void postOrder() {
        System.out.print("postOrder: ");
        postOrderPrint(root);
        System.out.println();
    }

    private void postOrderPrint(TNode n) {
        if (n.getChildren().isEmpty()) {
            System.out.print(n.getData() + " ");
        } else {
            for (TNode cn : n.getChildren()) {
                postOrderPrint(cn);
            }
            System.out.print(n.getData() + " ");
        }
    }

    public boolean isSubTree(TNode tn) {
        return true;
    }

    public void makeTree() {
        TNode rt = addRoot(0);
        buildTree(rt, 3);
    }

    public void makeTree2() {
        TNode rt = addRoot(0);
        buildTree(rt, 1);
    }

    public TNode getRoot() {
        return root;
    }

    public int height() {
        return height(root);
    }

    private int height(TNode tn) {
        if (tn == null) return 0;
        int counter = 0;
        for (TNode cn : tn.getChildren()) {
            int heightAttribute = height(cn) + 1;
            if (heightAttribute > counter) return heightAttribute;
        }
        return counter;
    }

    private void buildTree(TNode n, int i) {
        if (i <= 0) return;
        TNode fc = addChild(n, size);
        TNode sc = addChild(n, size);
        TNode tc = addChild(n, size);
        buildTree(fc, i - 1);
        buildTree(sc, i - 2);
        if (i % 2 == 0)
            buildTree(tc, i - 1);
    }

    public static void main(String[] args) {
        A2TreeCT t = new A2TreeCT();
        A2TreeCT t2 = new A2TreeCT();
        System.out.println("Tree t1 ");
        t.makeTree();
        System.out.println("Height: " + t.height());
        t.levelOrder();    //0 1 2 3 4 5 6 13 14 15 7 8 9 10 11 12
        t.preOrder();    //0 1 4 7 8 9 5 6 10 11 12 2 13 14 15 3
        t.postOrder();    //7 8 9 4 5 10 11 12 6 1 13 14 15 2 3 0
        TNode subT = t.getRoot().getChildren().get(1);
        t.isSubTree(subT);
        System.out.println("Tree t2 ");
        t2.makeTree2();
        System.out.println("Height: " + t2.height());
        t2.levelOrder();    //0 1 2 3
        t2.preOrder();    //0 1 2 3
        t2.postOrder();    //1 2 3 0
        t2.isSubTree(subT);
        t.isSubTree(t2.getRoot());
    }

}