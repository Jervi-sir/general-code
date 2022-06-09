 //Thread creation by extending the Thread class
class ThreadImplement extends Thread {
    static int fact = 1;
 
    public void run()
    {
 
        for (int i = 1; i <= 5; i++)
            fact = fact * i;
        System.out.println(fact);
    }
}
 
public class prodcons1 {
    public static void main(String[] args)
    {
        Thread t1
            = new Thread(new ThreadImplement());
 
        t1.start();
    }
}