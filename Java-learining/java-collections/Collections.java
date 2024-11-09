import java.util.HashSet;
import java.util.Set;
import java.util.TreeSet;

public class Collections {
    public static void main(String[] args) {
        // Defining the set 
        Set<Integer> nums = new HashSet<Integer>();

        nums.add(2);
        nums.add(6);
        nums.add(5);
        nums.add(8);
        nums.add(2);
        for (int n: nums) {
            System.out.println(n);
        }

        Set<Integer> nums1 = new TreeSet<Integer>();

        nums1.add(2);
        nums1.add(6);
        nums1.add(5);
        nums1.add(8);
        nums1.add(2);
        for (int n: nums1) {
            System.out.println(n);
        }

        
    }
}
