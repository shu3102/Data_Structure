package Linked_List;

public class Main {
    public static void main(String[] args) {
        System.out.println("This is link list data structure");

        LinkedList myLinkedList = new LinkedList(1);

        // myLinkedList.getHead();
        // myLinkedList.getTail();
        // myLinkedList.getLength();


        myLinkedList.append(2);
        myLinkedList.append(5);
        // System.out.println(myLinkedList.removeLast().data);
        // myLinkedList.prepend(0);
        // System.out.println(myLinkedList.removeFirst().data);
        System.out.println(myLinkedList.get(1).data);
        System.out.println();
        myLinkedList.printList();

        System.out.println("LL before reverse():");
        myLinkedList.printList();

        myLinkedList.reverse();

        System.out.println("\nLL after reverse():");
        myLinkedList.printList();
        
    }


}
