class Solution {
    public int[][] generateMatrix(int n) {

        int[][] result = new int[n][n];

        int left = 0;
        int right = n - 1;
        int top = 0;
        int bottom = n - 1;

        int num = 1;

        while (left <= right && top <= bottom) {

            // Fill top row (left → right)
            for (int col = left; col <= right; col++) {
                result[top][col] = num++;
            }
            top++;

            // Fill right column (top → bottom)
            for (int row = top; row <= bottom; row++) {
                result[row][right] = num++;
            }
            right--;

            // Fill bottom row (right → left)
            if (top <= bottom) {
                for (int col = right; col >= left; col--) {
                    result[bottom][col] = num++;
                }
                bottom--;
            }

            // Fill left column (bottom → top)
            if (left <= right) {
                for (int row = bottom; row >= top; row--) {
                    result[row][left] = num++;
                }
                left++;
            }
        }

        return result;
    }
}