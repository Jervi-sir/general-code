public class setThreadPriority2 extends Thread {
  
    public void run() {
      System.out.println("Thread " + Thread.currentThread().getName() + " started");
      System.out.println("Thread with priority " + Thread.currentThread().getPriority() + " is running");
    }
    public static void main(String[] args) {
      setThreadPriority2 t1 = new setThreadPriority2();
      setThreadPriority2 t2 = new setThreadPriority2();
      setThreadPriority2 t3 = new setThreadPriority2();
      
      t1.setPriority(9);
      t2.setPriority(6);
      //t3.setPriority(15);
      t3.setPriority(4);
      
      t1.start();
      t2.start();
      t3.start();
    }
  }