import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Shiritori shiritori = new Shiritori();
        Scanner scanner = new Scanner(System.in);
        boolean wantsToPlay = true;
        System.out.println("INSTRUCTIONS:\nq - leave\nr - reset\nOtherwise, type a word to play");
        String userInput;

        while(wantsToPlay) {
            System.out.println("Input: ");
            userInput = scanner.nextLine();
            switch (userInput) {
                case "r":
                    shiritori.restart();
                    break;
                case "q":
                    wantsToPlay = false;
                    break;
                default:
                    shiritori.play(userInput);
            }
        }
    }
}