class MyThread extends Thread
{
	MyThread(){
		System.out.println("In child thread");
	}
}

class Main
{
	public static void main(String args[]){
		System.out.println("In main thread");
		MyThread ob=new MyThread();
	}
}
