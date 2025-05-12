import java.util.*;

public class A2Matchthca {
    public static boolean isMatch(String expressionLine) {
        ArrayDeque<Character> stack = new ArrayDeque<>();
        char testChar, compareChar;

        /**
         * Algorithm (from textbook):
         * Make an empty stack. Read characters until end of file.
         * If the character is an opening symbol, push it onto the stack.
         * If it is a closing symbol, then if the stack is empty report an error.
         * Otherwise, pop the stack.
         * If the symbol popped is not the corresponding opening symbol, then report an error.
         * At end of file, if the stack is not empty report an error.
          */

        for(int i = 0; i < expressionLine.length(); i++) {
            testChar = expressionLine.charAt(i);
            if(testChar == '(' || testChar == '{' || testChar == '[') {
                stack.push(testChar);
                continue;
            }
            if(stack.isEmpty()) {
                return false;
            }

            switch(testChar) {
                case ')':
                    compareChar = stack.peek();
                    stack.pop();
                    if(compareChar == '{' || compareChar == '[') {
                        return false;
                    }
                    break;

                case '}':
                    compareChar = stack.peek();
                    stack.pop();
                    if(compareChar == '(' || compareChar == '[') {
                        return false;
                    }
                    break;

                case ']':
                    compareChar = stack.peek();
                    stack.pop();
                    if(compareChar == '(' || compareChar == '{') {
                        return false;
                    }
                    break;
            }
        }
        return (stack.isEmpty());
    }

    public static void main(String[] args){
        String[] expression = new String[]{"{5*(x+2)+(y-1);}", "32*(20+(x[i]*3)-1",
                "((){([][])})", "({}((0))", "{([]})", "{}())", "{"};
        for (String st: expression)
            System.out.println(st + " is " + isMatch(st));
    }
}
