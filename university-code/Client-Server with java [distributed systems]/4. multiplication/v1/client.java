import java.net.*;
import java.util.Scanner;
import java.io.*;

public class client {
    public static void main(String[] args) throws IOException {
        Socket s = new Socket("localhost", 4999);

        PrintWriter pr = new PrintWriter(s.getOutputStream());

        System.out.println("Enter number for multip: ");
        Scanner sc = new Scanner(System.in);

        while (!sc.hasNextInt()) sc.next();
        int number = sc.nextInt();

        pr.println(number);
        pr.flush();

        InputStreamReader in = new InputStreamReader(s.getInputStream());
        BufferedReader bf = new BufferedReader(in);

        String result;
        while ((result = bf.readLine()) != null) {
            System.out.println(result);
        }

        s.close();

    }
}
