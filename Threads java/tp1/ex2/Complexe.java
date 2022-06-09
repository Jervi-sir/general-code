package ex2;

//[x] create Complexe class
//[x] constructor of this class
//[x] toString, then print it
//[x] add two complexe numbers
//[x] substract two complexe numbers


public class Complexe {
    double real, img;

    Complexe(double r, double i) {
        this.real = r;
        this.img = i;
    }



    public static void main(String args[]) {
        /*************  Q3 ***************/
        /*
        Complexe number = new Complexe(0, 0);
        number.real = 5;
        number.img = 6;
        System.out.println(number.toString(number));
        */
        /*************  Q4 ***************/
        Complexe c1 = new Complexe(5.1, 4.6);
        Complexe c2 = new Complexe(4.20, 6.9);
        Complexe sumC = sum(c1, c2);
        Complexe subC = sub(c1, c2);
        System.out.println("Sum is: " + sumC.toString(sumC));
        System.out.println("Sum is: " + subC.toString(subC));

    }
    


    public String toString(Complexe num) {
        String result = num.real + " + " + num.img + "i";
        return result;
    }


    public static Complexe sum(Complexe c1, Complexe c2) {
        Complexe temp = new Complexe(0, 0);
        temp.real = c1.real + c2.real;
        temp.img = c1.img + c2.img;
        return temp;
    }

    public static Complexe sub(Complexe c1, Complexe c2) {
        Complexe temp = new Complexe(0, 0);
        temp.real = Math.floor(( c1.real - c2.real)* 100) / 100;
        temp.img = Math.floor(( c1.img - c2.img)* 100) / 100;
        return temp;
    }
    
    
}
