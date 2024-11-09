import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.List;


class Student
{
    int age;
    String name;

    public Student(int age, String name) {
        this.age = age;
        this.name = name;
    }
    
    public String toString() {
        return "Student [age=" + age + ", name=" + name + "]";
    }

    
}


public class Sorting {
    public static void main(String[] args) {

        List<Integer> nums = new ArrayList<>();
        
        nums.add(43);
        nums.add(443);
        nums.add(3);
        nums.add(7);
        nums.add(9);

        Collections.sort(nums);
        System.out.println(nums);

        Comparator<Integer> com = new Comparator<Integer>() {
            public int compare(Integer i, Integer j) {
                if(i%10 > j%10) {
                    return 1;
                }
                else 
                    return -1;
            }
        };
        Collections.sort(nums, com);
        System.out.println(nums);

        // Ceating a student list and trying to sort it 
        List<Student> students = new ArrayList<>();
        students.add(new Student(10, "Gopal"));
        students.add(new Student(20, "Raj"));
        students.add(new Student(15, "Rohit"));
        students.add(new Student(25, "Anya"));
        students.add(new Student(12, "Shubh"));
        students.add(new Student(21, "Padya"));

        System.out.println("Printing Students before sort");
        for (Student st : students) {
            System.out.println(st);
        }

        Comparator<Student> compare_age = new Comparator<Student>() {
            public int compare(Student i, Student j) {
                if(i.age > j.age) {
                    return 1;
                }
                else 
                    return -1;
            }
        };
        Collections.sort(students, compare_age);

        System.out.println("Printing Students After sort");
        for (Student st : students) {
            System.out.println(st);
        }
    }
}
