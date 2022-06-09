import java.net.*;
import java.util.Scanner;
import java.io.*;

public class client {
    public static void main(String[] args) throws IOException {
        Socket s = new Socket("localhost", 4999);

        PrintWriter pr = new PrintWriter(s.getOutputStream());

        System.out.println("Enter anythings: ");
        Scanner sc = new Scanner(System.in);
        String message = sc.next().toLowerCase();
        while(message.length() == 0) {
        }
        pr.println(sc);
        pr.flush();

        InputStreamReader in = new InputStreamReader(s.getInputStream());
        BufferedReader bf = new BufferedReader(in);

        String str = bf.readLine();
        System.out.println("server: " + str);
    }
}