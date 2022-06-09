import java.io.IOException;

public class pingpong {

    public static void main(String[] args) {

        pingpong P = new pingpong();

        Thread ping = new Thread(new Runnable() {
            public void run() {
                try {
                    P.ping();
                } catch (InterruptedException e) {
                    // TODO Auto-generated catch block
                    e.printStackTrace();
                }
            }
        });


        Thread pong = new Thread(new Runnable() {
            public void run() {
                try {
                    P.pong();
                } catch (InterruptedException e) {
                    // TODO Auto-generated catch block
                    e.printStackTrace();
                }
            }
        });

        ping.start();
        pong.start();

    }

    public void ping() throws InterruptedException {
        Thread.sleep(100);
        synchronized(this) {
            while(true) {
                System.out.println("ping");
                notify();
                wait();
            }
        }
    }

    public void pong() throws InterruptedException {
        synchronized(this) {
            while(true) {
                wait();
                System.out.println("pong");
                notify();
            }
        }
    }
}
