class Stack
{
        int size;
        int arr[];
        int top;

        Stack(int s){
                size=s;
                arr = new int[size];
                top=-1;
        }

        void push(int n){
                if (top==size-1){
                        System.out.println("Stack Overflow");
                        return;
                }
                top++;
                arr[top]=n;
        }

        int pop(){
                if (top==-1){
                        System.out.println("Stack Underflow");
                        return -1;
                }
                int v=arr[top];
                top--;
                return v;
        }

        void print(){
                if(top==-1){
                        System.out.println("Stack empty");
                        return;
                }
                System.out.println("The elements of the stack are : ");
                for (int i=top; i>-1; i--){
                        System.out.println(arr[i]);
                }
        }
}

class Demo{
        public static void main(String args[])
        {
                Stack s1=new Stack(30);

                s1.push(10);
                s1.push(20);
                s1.push(30);
                s1.push(15);
                s1.push(9);

                s1.print();

                System.out.println(s1.pop() + " popped");
                System.out.println(s1.pop() + " popped");
                System.out.println(s1.pop() + " popped");

                s1.print();
        }
}
