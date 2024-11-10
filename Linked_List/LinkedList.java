package Linked_List;

public class LinkedList {
    
    private Node head;
    private Node tail;
    private int length;

    class Node {
        int data;
        Node next;

        Node(int data) {
            this.data = data;
            this.next = null;
        }
    }

    public LinkedList(int data) {
        Node temp = new Node(data);

        this.head = temp;
        this.tail = temp;
        this.length = 1;
    }

   	
    public void printList() {
        Node temp = head;
        System.out.print("[ ");
        while (temp != null) {
            System.out.print(temp.data);
            System.out.print(" ");
            temp = temp.next;
        }
        System.out.print("]");
    }

    public void getHead() {
        if (head == null) {
            System.out.println("Head: null");
        } else {
            System.out.println("Head: " + head.data);
        }
    }

    public void getTail() {
        if (head == null) {
            System.out.println("Tail: null");
        } else {
            System.out.println("Tail: " + tail.data);
        }
    }

    public void getLength() {
        System.out.println("Length: " + length);
    }

    public void append(int data) {
        Node temp = new Node(data);
        
        if(head == null) {
            this.head = temp;
            this.tail = temp;
            this.length = 1;
        }
        else {
            tail.next = temp;
            tail = temp;
        }
        length++;
    }

    public Node removeLast() {
        if(length == 0) {
            return null;
        }
        Node temp = head;
        Node pre = temp;

        while(temp.next != null) {
            pre = temp;
            temp = temp.next;
        }
        tail = pre;
        tail.next = null;
        length--;
        if (length == 0) {
            head = null;
            tail = null;
        }
        return temp;
    }

    public void prepend(int data) {
        Node temp = new Node(data);

        if(length == 0) {
            head = temp;
            tail = temp;
        }
        else {
            temp.next = head;
            head = temp;
        }

        length++;
    }
    
    public Node removeFirst() {
        if(length == 0) return null;

        Node temp = head;
        head = head.next;
        temp.next = null;
        length--;
        if(length == 0) {
            tail = null;
        }
        return temp;
    }

    public Node get(int index) {
        if(index < 0 || index >= length) {
            return null;
        }
        Node temp = head;
        int t = 0;
        while(t < index) {
            temp = temp.next;
            t += 1;
        }
        return temp;
    }
    public boolean set(int index, int value) {
        Node temp = get(index);
        if (temp != null) {
            temp.data = value;
            return true;
        }
        return false;
    }

    public boolean insert(int index, int value)  {
        if (index < 0 || index > length) return false;
        if (index == 0) {
            prepend(value);
            return true;
        }
        if (index == length) {
            append(value);
            return true;
        }
        Node newNode = new Node(value);
        Node temp = get(index - 1);
        newNode.next = temp.next;
        temp.next = newNode;
        length++;
        return true;
    }

    public Node remove(int index) {
        if (index < 0 || index >= length) return null;
        if (index == 0) return removeFirst();
        if (index == length - 1) return removeLast();

        Node prev = get(index - 1);
        Node temp = prev.next;

        prev.next = temp.next;
        temp.next = null;
        length--;
        return temp;
    }

    public void reverse() {
        Node temp = head;
        head = tail;
        tail = temp;
        Node after = temp.next;
        Node before = null;
        for (int i = 0; i < length; i++) {
            after = temp.next;
            temp.next = before;
            before = temp;
            temp = after;
        }
    }


}
