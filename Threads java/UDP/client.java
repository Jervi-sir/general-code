import java.io.ByteArrayOutputStream;
import java.io.DataOutputStream;
import java.net.DatagramPacket;
import java.net.DatagramSocket;
import java.net.InetAddress;

public class client {
    public static void main(String[] args)throws Exception {
        DatagramSocket socket = new DatagramSocket();
        InetAddress server = InetAddress.getByName("localhost");
        ByteArrayOutputStream a = new ByteArrayOutputStream();
        DataOutputStream b = new DataOutputStream(a);

        b.writeInt(10);
        b.writeBoolean(true);
        b.writeUTF("this is a string");
        b.writeDouble(10);
        byte[] buffer = a.toByteArray();
        DatagramPacket packet = new DatagramPacket(buffer, buffer.length, server, 2000);
        socket.send(packet);
        System.out.println("client a envoye 10 true bonjour 1.2 au server");

        socket.close();
    }
}
