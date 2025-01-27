class Complex
{
        int real;
        int imag;

        Complex(){
                real=0;
                imag=0;
        }

        Complex(int r){
                real=r;
        }

        Complex(int r, int i){
                real=r;
                imag=i;
        }

        void add(Complex ob){
                int r=real+ob.real;
                int i=imag+ob.imag;
                System.out.println("The sum is: " + r+" + "+i+"i");
        }

        void product(Complex ob){
                int r=real*ob.real;
                int a=r-imag*ob.imag;
                int i=(real*ob.imag)+(imag*ob.real);
                System.out.println("The product is: " + a+" + "+i+"i");
        }
}

class Demo{
        public static void main(String args[]){
                Complex c1= new Complex(3,2);
                Complex c2= new Complex(4,-2);
                c1.add(c2);
                c1.product(c2);
        }
}
