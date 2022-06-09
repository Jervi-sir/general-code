import java.net.*;
import java.io.*;

public class server {
    public static void main(String[] args) throws IOException {
        //specify port of the server
        ServerSocket ss =new ServerSocket(4999);

        //waiting for connection
        Socket s = ss.accept();
        System.out.println("client connected");
    }
}