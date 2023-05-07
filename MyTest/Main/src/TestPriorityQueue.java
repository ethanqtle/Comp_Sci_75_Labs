import java.util.PriorityQueue;
import java.util.Set;
import java.util.HashSet;

public class TestPriorityQueue {

    public static void main(String[] args) {
        
        // create two priority queues
        PriorityQueue<String> queue1 = new PriorityQueue<>();
        PriorityQueue<String> queue2 = new PriorityQueue<>();
        
        // add names to queue1
        queue1.offer("Alice");
        queue1.offer("Bob");
        queue1.offer("Charlie");
        
        // add names to queue2
        queue2.offer("Charlie");
        queue2.offer("David");
        queue2.offer("Emily");
        
        // check for names in queue1 only
        System.out.println("Names in queue1 only:");
        Set<String> set1 = new HashSet<>(queue1);
        set1.removeAll(queue2);
        for (String name : set1) {
            System.out.println(name);
        }

        // check for names in queue2 only
        System.out.println("\nNames in queue2 only:");
        Set<String> set2 = new HashSet<>(queue2);
        set2.removeAll(queue1);
        for (String name : set2) {
            System.out.println(name);
        }

        // check for names in both queues
        System.out.println("\nNames in both queues:");
        Set<String> set3 = new HashSet<>(queue1);
        set3.retainAll(queue2);
        for (String name : set3) {
            System.out.println(name);
        }
    }

}
