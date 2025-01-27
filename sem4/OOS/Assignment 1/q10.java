import java.util.*;

class Book {
   String author;
   String title;
   String publisher;
   double cost;
   int stock;


   Book(String title, String author, String publisher, double cost, int stock) {
       this.title = title;
       this.author = author;
       this.publisher = publisher;
       this.cost = cost;
       this.stock = stock;
   }


   boolean matches(String title, String author) {
       return (this.title).equalsIgnoreCase(title) && (this.author).equalsIgnoreCase(author);
   }


   void displayDetails() {
       System.out.println("Title: " + title);
       System.out.println("Author: " + author);
       System.out.println("Publisher: " + publisher);
       System.out.println("Cost: " + cost);
       System.out.println("Stock: " + stock);
   }


   void processPurchase(int requestedCopies) {
       if (requestedCopies <= stock) {
           System.out.println("Total Cost: " + (cost * requestedCopies));
           stock -= requestedCopies;
       } else {
           System.out.println("Required copies not in stock");
       }
   }
}
class Demo {


   public static void main(String[] args) {
       Scanner sc = new Scanner(System.in);
       Book[] inventory = {
               new Book("Book 1", "author 1", "publisher 1", 500, 5),
               new Book("Book 2", "author 2", "publisher 2", 300, 10),
               new Book("Book 3", "author 3", "publisher 3", 400, 8),
               new Book("Book 4", "author 4", "publisher 4", 350, 6)
       };
       boolean found = false;


       String title, author;
       System.out.print("Enter the title: ");
       title = sc.nextLine();
       System.out.print("Enter the author: ");
       author = sc.nextLine();


       for (Book book : inventory) {
           if (book.matches(title, author)) {
               found = true;
               System.out.println("Book is available. Details:");
               book.displayDetails();


               System.out.print("Enter the number of copies required: ");
               int requestedCopies = sc.nextInt();


               book.processPurchase(requestedCopies);
               break;
           }
       }


       if (!found) {
           System.out.println("Book not available.");
       }
   }
}
