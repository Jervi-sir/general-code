public class setThreadPriority1 extends Thread {
  
    public void run() {
      System.out.println("Thread " + Thread.currentThread().getName() + " started");
      System.out.println("Thread with priority " + Thread.currentThread().getPriority() + " is running");
    }
    public static void main(String[] args) {
      setThreadPriority1 t1 = new setThreadPriority1();
      setThreadPriority1 t2 = new setThreadPriority1();
      setThreadPriority1 t3 = new setThreadPriority1();
      
      t1.setPriority(MIN_PRIORITY);
      t2.setPriority(NORM_PRIORITY);
      t3.setPriority(MAX_PRIORITY);
      
      t1.start();
      t2.start();
      t3.start();
    }
  }
  