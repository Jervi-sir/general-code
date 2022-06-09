import java.io.ByteArrayInputStream;
import java.io.DataInputStream;
import java.net.DatagramPacket;
import java.net.DatagramSocket;

public class server {
    public static void main(String[] args)  throws Exception{
        DatagramSocket socket = new DatagramSocket(2000);
        DatagramPacket packet = new DatagramPacket(new byte[1024], 1024);
        socket.receive(packet);
        byte[] data = packet.getData();
        ByteArrayInputStream a = new ByteArrayInputStream(data);
        DataInputStream b = new DataInputStream(a);
        System.out.println("entier received:" + b.readInt());   
        System.out.println("boolean received:" + b.readBoolean());   
        System.out.println("string received:" + b.readUTF());   
        System.out.println("double received:" + b.readDouble());   

        socket.close();
    }
}
