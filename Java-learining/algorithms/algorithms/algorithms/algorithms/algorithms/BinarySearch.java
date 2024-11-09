

public class BinarySearch {
    public static void main(String[] args) {
        
        int nums[] = {5, 7, 9, 11, 13};
        int target = 17;

        int index = binarySearch(nums, target);
        if(index > 0) {
            System.out.println("Element found at index: " + index);
        }
        else {
            System.out.println("Element not found in nums");
        }

    }

    private static int binarySearch(int[] nums, int target) {
        
        int left = 0;
        int right = nums.length - 1;

        while (left <= right) {
            int mid = (left + right) /2;
            if(nums[mid] == target) {
                return mid;
            }
            else if(nums[mid] < target) {
                left = mid + 1;
            }
            else if(nums[mid] > target) {
                right = mid - 1;
            }
        }
        return -1;

    }
}
