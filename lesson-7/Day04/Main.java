import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        try {
            File inputFile = new File("Day04.txt");
            Scanner scanner = new Scanner(inputFile);
            RangeAnalyser analyser = new RangeAnalyser();
            int counter = 0;
            while(scanner.hasNextLine()) {
                analyser.rangesFromString(scanner.nextLine());
                counter += (analyser.containEachOther()) ? 1 : 0;
            }
            System.out.println(counter);
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        }
    }
}
