public class letterNumbers {
    static char L = 'a';
    static int c = 1;

    public static void main(String[] args) {
        Thread letter = new Thread(new Runnable() {
            @Override
            public void run() {
                while(L <= 'z') {
                    System.out.println(L + " ");
                    L++;
                }
            }

        });

        Thread digit = new Thread(new Runnable() {
            @Override
            public void run() {
                while(c <= 'z') {
                    System.out.println(c + " ");
                    c++;
                }
            }

        });


        letter.start();
        digit.start();
    }
}
