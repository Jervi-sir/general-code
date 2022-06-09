package ex1.withClass;
//[x] print 1 to 10 with single thread
//[x] create two instances
 
public class Demo {
    public static void main(String[] args) {
            Thex thread1 = new Thex();
            thread1.start();
            //thread1.run();

            Thex thread2 = new Thex();
            thread2.start();
            //thread2.run();
    }
}

class Thex extends Thread{

        public void run() {
            for(int i = 1; i < 1000; i++) {
                System.out.println(Thread.currentThread().getName() + " value: " + i);
            }

        }
}
