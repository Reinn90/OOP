import java.util.Scanner;

/**
 *
 * @author dongmo
 */
public class Hello {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        String name;                  
       Scanner input = new Scanner(System.in);
       System.out.println("Enter your name:");  
       name = input.nextLine();                  
       System.out.println("Hello " + name +"!");
        input.close();
    }
}
