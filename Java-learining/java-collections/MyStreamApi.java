import java.util.Arrays;
import java.util.List;
import java.util.stream.Stream;

public class MyStreamApi {
    public static void main(String[] args) {
        
        // Creating a arya using the Arrays.aslist
        List<Integer> nums = Arrays.asList(4, 5, 1, 9, 11, 10, 6, 3, 20);
        
        // System.out.println(nums);

        // need to print the sume of all the even numbers making them double.

        Stream<Integer> s1 = nums.stream();
        Stream<Integer> s2 = s1.filter(n -> n%2 == 0);
        Stream<Integer> s3 = s2.map(n -> n*2);
        int ans = s3.reduce(0, (c, e) -> c+e);

        // s3.forEach(n -> System.out.println(n));
        System.out.println(ans);


        // or the same logic as above in one line
        int andOneLine = nums.stream()
                                .filter(n -> n%2 == 0)
                                .map(n -> n*2)
                                .reduce(0, (c, e) -> c + e);

        System.out.println(andOneLine);
    }
}
