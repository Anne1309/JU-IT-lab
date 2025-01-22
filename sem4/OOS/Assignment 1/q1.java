class Room
{
        int height, width, breadth;
        Room(int h, int w, int b){
                height=h;
                width=w;
                breadth=b;
        }

        int volume(){
                return (height*breadth*width);
        }
}

class RoomDemo
{
        public static void main(String args[])
        {
                Room R1=new Room(1,2,3);
                Room R2=new Room(3,4,5);
                System.out.println("Volume of room 1 is: " + R1.volume());
                System.out.println("Volume of room 2 is: " + R2.volume());
        }
}
