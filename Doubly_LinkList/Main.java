package Doubly_LinkList;

public class Main {

    public static void main(String[] args) {

        DoublyLinkedList myDLL = new DoublyLinkedList(7);

        myDLL.getHead();
        myDLL.getTail();
        myDLL.getLength();

        System.out.println("\nDoubly Linked List:");

        myDLL.append(2);
        myDLL.append(5);
        // myDLL.removeLast();
        myDLL.prepend(0);
        // myDLL.removeFirst();
        myDLL.set(2, 99);
        myDLL.printList();
        System.out.println(myDLL.get(3).value);

        

    }

}
