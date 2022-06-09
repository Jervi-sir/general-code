package ex2.q1;
 
public class Demo {
    public static void main(String[] args) {
            ThLetters thread1 = new ThLetters();
            ThNumbers thread2 = new ThNumbers();
            thread1.start();
            thread2.start();
    }
}

class ThLetters extends Thread{
        public void run() {
            for(int i = 0; i < 26; i++) {
                String str = String.valueOf(Character.toChars(65 + i)); // str <- "A"
                System.out.println(Thread.currentThread().getId() + " Letter: " + str);
                try {
                    Thread.sleep(100);
                } catch (InterruptedException e) {
                    e.printStackTrace();
                }
            }
        }
}

class ThNumbers extends Thread{

    public void run() {
        for(int i = 0; i < 26; i++) {
            System.out.println(Thread.currentThread().getId() + " value: " + (i + 1));
            try {
                Thread.sleep(100);
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
    }
}
