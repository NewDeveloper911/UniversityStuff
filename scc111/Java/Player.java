import java.util.Scanner;

public class Player {
    String name;
    Scanner keyboard = new Scanner(System.in);

    public int makeGuess(){
        int guess = 0;
        System.out.println(name + ", make a guess between 1 and 6");
        guess = keyboard.nextInt();
        return guess;
    }



}
