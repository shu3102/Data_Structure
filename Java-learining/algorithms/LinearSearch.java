package algorithms;

public class LinearSearch {
    public static void main(String[] args) {
        // Search an element



        int nums[] = {5, 7, 9, 11, 13};
        int target = 11;

        int index = linearSearch(nums, target);
        if(index > 0) {
            System.out.println("Element found at index: " + index);
        }
        else {
            System.out.println("Element not found in nums");
        }
    }

    private static int linearSearch(int[] nums, int target) {
        for(int i = 0; i < nums.length; i ++) {
            if(target == nums[i]) {
                return i;
            }
        }    
        return -1;
    }
}
