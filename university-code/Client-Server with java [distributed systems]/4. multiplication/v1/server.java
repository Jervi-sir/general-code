import java.net.*;
import java.io.*;

public class server {
    public static void main(String[] args) throws IOException {
        ServerSocket ss =new ServerSocket(4999);
        Socket s = ss.accept();

        System.out.println("client connected");

        InputStreamReader in = new InputStreamReader(s.getInputStream());
        BufferedReader bf = new BufferedReader(in);

        int num = bf.read();
        System.out.println("client has sent: " + num);
        
        PrintWriter pr = new PrintWriter(s.getOutputStream());
        for(int i = 0; i <= 10; i++) { 
            pr.println(num + " * " + i + " = " + num*i);
        }
        pr.flush();

    }
}