public class threadPriorityDemo extends Thread{
  
    public void run() {
      System.out.println("Thread " + Thread.currentThread().getName() + " running");
    }
    public static void main(String[] args) {
      
      threadPriorityDemo th1 = new threadPriorityDemo();
      threadPriorityDemo th2 = new threadPriorityDemo();
      threadPriorityDemo th3 = new threadPriorityDemo();
      
      th1.start();
      th2.start();
      th3.start();
      
      System.out.println("Priority of thread " + th1.getName() + " : " + th1.getPriority());
      System.out.println("Priority of thread " + th2.getName() + " : " + th2.getPriority());
      System.out.println("Priority of thread " + th3.getName() + " : " + th3.getPriority());
      
    }
  }