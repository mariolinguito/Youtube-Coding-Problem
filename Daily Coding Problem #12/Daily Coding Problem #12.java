public class HelloWorld {
    public static boolean hasWord(char matrixChar[][], String wordToCheck) {
        // First of all, we need to confront the string with all the 
        // rows and columns of the matrix.
        boolean result = false; 

        for(int index = 0; index < matrixChar.length; index++) {
            // We declare two arrays of character that are the 
            // array of the current row and the array of the 
            // current column.
            char[] rowArray = new char[matrixChar.length]; 
            char[] colArray = new char[matrixChar.length]; 

            // With this instruction, we get the current 
            // row of the matrix with only the index. 
            rowArray = matrixChar[index];

            // We want also the current column, so we need a loop because 
            // there is not a single instruction to get it, instead of the row. 
            for(int rowIndex = 0; rowIndex < matrixChar.length; rowIndex++) {
                colArray[rowIndex] = matrixChar[rowIndex][index];
            }

            // After that we need to convert the array 
            // of characters in a string, to compare it 
            // with the string in the input. 
            String rowString = new String(rowArray); 
            String colString = new String(colArray);
            
            // So we compare the input string with the row, 
            // and then with the column. If the comparison 
            // results true, we break the loop and return 
            // the result. 
            if(rowString.equalsIgnoreCase(wordToCheck)) {
                result = true; 
                break; 
            } else {
                if(colString.equalsIgnoreCase(wordToCheck)) {
                    result = true; 
                    break; 
                } result = false; 
            }
        } 
        
        // Finally we return the result. 
        return result; 
    }

    public static void main(String[] args) {
	char[][] matrixChar = new char[][]{
            { 'F', 'A', 'C', 'I' },
            { 'O', 'B', 'Q', 'P' },
            { 'A', 'N', 'O', 'B' },
            { 'M', 'A', 'S', 'S' }
        };

        System.out.println(hasWord(matrixChar, "CQOS"));
    }
}
