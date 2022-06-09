import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.net.Socket;
import java.util.Scanner;

public class client {
    public static void main(String[] args) throws IOException {

        Socket socket = null; //create a socket
        InputStreamReader din = null; //read from server
        OutputStreamWriter dout = null; //wrap client in an output object
        BufferedReader br = null; //a bloc of input stream at once;
        BufferedWriter bw = null; //a bloc of output  stream at once;

        //create socket and data handlers
        socket = new Socket("localhost", 6666);
        din = new InputStreamReader(socket.getInputStream());
        dout = new OutputStreamWriter(socket.getOutputStream());
        br = new BufferedReader(din);
        bw = new BufferedWriter(dout);

        while(true) {
            //client input
            System.out.println("enter: ");
            Scanner sc = new Scanner(System.in);

            //send to server
            String msgToSend = sc.nextLine();
            bw.write(msgToSend);
            bw.newLine();
            bw.flush();

            //sence if client want to quit
            try {
                Integer.parseInt(msgToSend);
            } catch (Exception e) {
                //sence if client want to quit
                break;
            }

            //wait for server response
            for(int i = 0; i <= 10; i++) {
                System.out.println(br.readLine());
                //System.out.println("->" + i);
            }

            sc.close();

        }

        //close the connection
        socket.close();
        din.close();
        dout.close();
        bw.close();
    }
}
