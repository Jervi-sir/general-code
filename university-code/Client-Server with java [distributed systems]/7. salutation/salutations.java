public class salutations {
    static int i = 1;
    static int j = 1;

    public static void main(String[] args) {
        Thread hi = new Thread(new Runnable() {
            @Override
            public void run() {
                try {
                    System.out.println("Hi");
                    Thread.sleep(4000);
                } catch (InterruptedException e) {
                    // TODO Auto-generated catch block
                    e.printStackTrace();
                };
            }
        });

        Thread bruh = new Thread(new Runnable() {
            @Override
            public void run() {
                while(j <= 5) {

                    try {
                        System.out.println("Hi2");
                        Thread.sleep(4000);
                    } catch (InterruptedException e) {
                        // TODO Auto-generated catch block
                        e.printStackTrace();
                    }
                }
            }
        });

        hi.start();
        bruh.start();
    }
}