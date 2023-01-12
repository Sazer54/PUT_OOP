import java.io.File;
import java.io.FileNotFoundException;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class EnglishDictionary {
    private boolean initialised;
    private List<String> dictionary;

    public EnglishDictionary() {
        this.initialised = false;
        this.dictionary = new ArrayList<>();
    }

    public void initialise() {
        if (!this.initialised) {
            try {
                File file = new File("eng_dict.txt");
                Scanner scanner = new Scanner(file);
                while (scanner.hasNext()) {
                    this.dictionary.add(scanner.nextLine());
                }
                this.initialised = true;
            } catch (FileNotFoundException e) {
                System.out.println("Could not find dictionary");
            }
        }
    }

    public boolean contains(Word word) throws FileNotFoundException{
        return this.dictionary.contains(word.value());
    }

}
