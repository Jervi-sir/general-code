 //Thread creation by implementing the Runnable Interface
 class ThreadImplement implements Runnable {
    static int fact = 1;
 
    // Overriding the run method
    // to find the factorial of
    // a number 5
    public void run()
    {
        // Loop to compute the factorial
        for (int i = 1; i <= 5; i++)
            fact = fact * i;
        System.out.println(fact);
    }
}
 
public class prodcons2 {
    public static void main(String[] args)
    {
 
        // Creating an object of the
        // thread class
        Thread t1
            = new Thread(new ThreadImplement());
 
        // Computing the above class
        t1.start();
    }
}