import java.util.Stack;

public class Solution {
    public String removeDuplicateLetters(String s) {
        int[] lastOccurrence = new int[26];
        for (int i = 0; i < s.length(); i++) {
            lastOccurrence[s.charAt(i) - 'a'] = i;
        }
        Stack<Character> stack = new Stack<>();
        boolean[] inStack = new boolean[26];  
        
        for (int i = 0; i < s.length(); i++) {
            char currentChar = s.charAt(i);
            
            if (inStack[currentChar - 'a']) {
                continue;
            }

 
            while (!stack.isEmpty() && stack.peek() > currentChar 
                   && i < lastOccurrence[stack.peek() - 'a']) {
                inStack[stack.pop() - 'a'] = false;
            }

            stack.push(currentChar);
            inStack[currentChar - 'a'] = true;
        }

        StringBuilder result = new StringBuilder();
        while (!stack.isEmpty()) {
            result.append(stack.pop());
        }
        
      
        return result.reverse().toString();
    }

    public static void main(String[] args) {
        Solution solution = new Solution();
        String s = "cbacdcbc";
        System.out.println(solution.removeDuplicateLetters(s));
    }
}
