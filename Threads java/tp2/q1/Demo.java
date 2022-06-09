package q1;

public class Demo {
    static int i = 0;
    public static void main(String[] args) {
        Thread Th1 = new Thread(new Runnable() {
            public void run() {
                i++;
            }
        });

        for(int j = 1; j < 11; j++) {
            System.out.println("-> main() " + j);
        }
    }
}
