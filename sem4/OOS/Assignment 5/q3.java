class User
{
    private String name;
    User(String name)
    {
        this.name = name;
    }
    public String getName()
    {
        return this.name;
    }
    public void setName(String name)
    {
        this.name = name;
    }
    public void sendMessage(String message)
    {
        System.out.println("@"+name+" : "+message);
    }
}
interface Mediator
{
    void showMessage(User user,String msg);
}
class ChatRoom implements Mediator
{
    public void showMessage(User user,String msg)
    {
        user.sendMessage(msg);
    }
}
class MediatorPatternDemo
{
    public static void main(String[] args)
    {
        User user1 = new User("Rahul");
        User user2 = new User("Mahi");
        User user3 = new User("Vivek");
        Mediator chatRoom = new ChatRoom();
        chatRoom.showMessage(user1,"Hi, Nice to meet you all");
        chatRoom.showMessage(user2,"Shubho Noboborso");
        chatRoom.showMessage(user3,"Hello, Hi I am fine");
    }
}
