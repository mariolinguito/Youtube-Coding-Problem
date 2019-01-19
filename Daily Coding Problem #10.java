import java.util.ArrayList;
import java.util.List;

public class DailyCodingProblemFacebook {
    // The inputs of the method are the array of characters (the 
    // alphabet) and the string of the message to decode. 
    public static int decodeMessage(char elems[], String message) {
        int index               = 0; 
        
        // We define an object of type StringBuilder because 
        // in this way we can modify the string and append other 
        // characters or string. And after we declare a list of 
        // integers that is the list of the solutions (we have a 
        // loop that appends the solution to this list).
        StringBuilder couple    = new StringBuilder(); 
        List<Integer> arrayWays = new ArrayList<>();

        // We have the basic case when we have at least two elements into the message to decode. 
        // And these two elements are not equal to zero. If so, we create the couple (First Element, 
        // Second Element). When we have only one element, the solution is equal to 1, when we have 
        // two elements, so the solutions are 2 only if the couple is lower than array's dimension. 
        // Otherwise, the solution at the second position of the list is 1 again.
        if(message.length() >= 2 && message.charAt(index) != '0' && message.charAt(index+1) != '0') {
            couple.append(message.charAt(index)); 
            couple.append(message.charAt(index+1));

            arrayWays.add(0, 1); 

            if(Integer.parseInt(couple.toString()) < elems.length) {
                arrayWays.add(1, 2); 
            } else {
                arrayWays.add(1, 1); 
            }
        } else {
            return -1; 
        }

        couple.setLength(0);

        // After we compute the basic case, we need to compute 
        // the other elements of the message to decode, so the 
        // loop starts from the third element until the last element 
        // of the message. At this point, we need to create the couple 
        // again of the elements: the first of the index-1 and the second 
        // of the index, because is like to add another element (at every 
        // iteration) in the previous solution so we need to consider 
        // also this element, and the couple that it makes with the 
        // previous element of the message. 
        for(index = 2; index < message.length(); index++) {
            couple.append(message.charAt(index-1)); 
            couple.append(message.charAt(index)); 

            // So we check if the couple is lower than the array's 
            // dimension, if yes, the solution of the current iteration 
            // is the sum of the first and second previous elements. 
            // Otherwise, the solution is the same as the previous iteration.
            if(Integer.parseInt(couple.toString()) < elems.length) {
                arrayWays.add(index, (arrayWays.get(index-1) + arrayWays.get(index-2))); 
            } else {
                arrayWays.add(index, (arrayWays.get(index-1))); 
            }

            couple.setLength(0);
        }

        // The solution is stored, of course, in 
        // the last position of the list. 
        return arrayWays.get(arrayWays.size()-1); 
    }

	public static void main(String[] args) {
        char[] elems = new char[] {
            '-', 'A', 'B', 'C', 'D', 'E', 'F',
            'G', 'H', 'I', 'J', 'K', 'L', 'M',
            'N', 'O', 'P', 'Q', 'R', 'S', 'T',
            'U', 'V', 'W', 'X', 'Y', 'Z'
        };

        String message = "11111";

        /**
         * 11111
         * 
         * AAAAA
         * KAAA
         * AKAA
         * AAKA
         * AAAK
         * KKA
         * AKK
         * KAK
         */

        int w = decodeMessage(elems, message); 

        if(w > 0) {
            System.out.println("Decoded in " + decodeMessage(elems, message) + " ways!");
        } else {
            System.out.println("Error, there are some 0 in the message");
        }
    }
}
