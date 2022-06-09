public class pingpong extends Thread {

    public void run(){  
        int turn = 0;
        while(true) {
            synchronized(this) {
                if(turn == 0) {
                    System.out.println("ping");
                    turn = 1;
                }
                else if(turn == 1) {
                    System.out.println("pong");
                    turn = 0;
                }
            }
        }
    }  

    public static void main(String[] args) {
        pingpong p1 = new pingpong();
        pingpong p2 = new pingpong();

        p1.start();
        p2.start();
    }
}
