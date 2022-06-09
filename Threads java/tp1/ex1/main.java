import java.util.*;

//[x] print hello world
//[x] print 10 odds sup of n, n is already declared
//[x] user input ask, and same things as previous

public class main{  
    public static void main(String args[]){
        /************** Q1  ***************/
        System.out.println("Hello Java");  
        
        /************** Q2  ***************/
        //int n = 4;
        //new main().userInput(n);

        /************** Q3  ***************/
        Scanner inputObj = new Scanner(System.in);
        try {
            System.out.println("Enter integer, to show even numbers superior of it: ");
            int num = inputObj.nextInt();

            //ask for result
            new main().userInput(num);
            
        } finally {
            inputObj.close();
        }
    } 

    //For Q2 and Q3
    void userInput(int num) {
        //if input is odd 
        if(num % 2 != 0) {
            new main().printEven(num);
        } else {
            new main().printEven(num + 1);
        }
    }

    //For Q2
    void printEven(int num) {
        for(int i = 0; i < 10; i++)
        {
            int additional = i + ( i + 1); //like an additional number concluded from remark 
            System.out.println(num + additional);  
        }
    }

}  