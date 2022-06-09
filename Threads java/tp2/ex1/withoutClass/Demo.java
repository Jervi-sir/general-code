package ex1.withoutClass;

public class Demo {
    public static void main(String[] args) {
        new Thread(new Runnable() {
            public void run() {
                for(int i = 1; i < 11; i++) {
                    System.out.println("-> run() " + i);
                }
            }
        }).start();

        for(int j = 1; j < 11; j++) {
            System.out.println("-> main() " + j);
        }
    }
}
