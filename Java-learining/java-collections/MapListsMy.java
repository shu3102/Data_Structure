import java.util.HashMap;
import java.util.Map;

public class MapListsMy {
    public static void main(String[] args) {
        Map<String, Integer> students = new HashMap<>();
    
        students.put("Shubham", 80);
        students.put("Harsh", 90);
        students.put("Sushil", 60);
        students.put("Kiran", 40);
        System.out.println(students);
        System.out.println(students.get("Shubham"));
        System.out.println(students.keySet());
    
    
    }
}
