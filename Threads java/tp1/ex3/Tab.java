import java.util.Scanner;

//[x] input user array
//[x] show array data
//[x] input message of the user

public class Tab {


    public static void main(String[] args) {
        Scanner intS = new Scanner(System.in);
        System.out.println("enter number of elements");
        int size = intS.nextInt();

        int arr[]=new int[size];

        System.out.println("enter elements");

        //Ready input
        for(int i = 0; i < size; i++){
            arr[i] = intS.nextInt();
        }

        System.out.println();
        //print array
        for(int i: arr){ 
            System.out.println(i);
        }

        Scanner stringS = new Scanner(System.in);
        System.out.println("enter a message");
        String message = stringS.nextLine();
        System.out.println(message);

    }


}
