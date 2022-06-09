public class letters {
    static char L = 'a';

    public static void main(String[] args) {
        Thread th = new Thread(new Runnable() {
            @Override
            public void run() {
                while(L <= 'z') {
                    System.out.println(L + " ");
                    L++;
                }
            }
        });

        th.start();
    }
}