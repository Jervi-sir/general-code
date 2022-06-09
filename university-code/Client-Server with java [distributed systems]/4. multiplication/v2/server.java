import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.net.ServerSocket;
import java.net.Socket;

public class server {
    public static void main(String[] args) throws IOException {
        ServerSocket serverSocket = null; //listen for a port
        Socket socket = null; //create a socket
        InputStreamReader din = null; //read from server
        OutputStreamWriter dout = null; //wrap client in an output object
        BufferedReader br = null; //a bloc of input stream at once;
        BufferedWriter bw = null; //a bloc of output  stream at once;


        serverSocket = new ServerSocket(6666);

        while(true) {
            //create connection session
            socket = serverSocket.accept();
            din = new InputStreamReader(socket.getInputStream());
            dout = new OutputStreamWriter(socket.getOutputStream());
            br = new BufferedReader(din);
            bw = new BufferedWriter(dout);
            
            while(true) {
                //get data from client
                String msgFromClient = br.readLine();
                int number;
                
                try {
                    number = Integer.parseInt(msgFromClient);
                } catch (Exception e) {
                    //sence if client want to quit
                    break;
                }

                System.out.println("client: " + number);

                //process the calculation
                for(int i = 0; i <= 10; i++) {
                    String result = number + " x " + i + " = " + (number * i) + "\n";
                    bw.write(result);
                    //System.out.println(result);
                }
                bw.newLine();
                bw.flush();
                
            }

            //close the connection
            socket.close();
            din.close();
            dout.close();
            br.close();
            bw.close();
            serverSocket.close();
        }
    }
}
