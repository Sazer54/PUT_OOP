import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;

public class Main{
    public static void main(String[] args) {
        try {
            File inputFile = new File("Day03.txt");
            Scanner scanner = new Scanner(inputFile);
            int sum = 0;
            while(scanner.hasNextLine()) {
                Rucksack rucksack = new Rucksack(scanner.nextLine());
                sum += rucksack.priorityOfDup();
            }
            System.out.println(sum);
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        }
    }
}
