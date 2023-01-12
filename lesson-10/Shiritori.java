import java.io.IOException;
import java.util.ArrayList;
import java.util.List;

public final class Shiritori {
    private List<Word> words;
    private boolean gameOver;
    private final EnglishDictionary englishDictionary;

    public Shiritori() {
        this.words = new ArrayList<>();
        this.gameOver = false;
        this.englishDictionary = new EnglishDictionary();
    }

    void play(Word word) {
        this.englishDictionary.initialise();
        if (!this.gameOver) {
            try {
                if (word.valid(this.words, this.englishDictionary)) {
                    this.words.add(word);
                    this.printWords();
                }
            } catch (IOException e) {
                this.gameOver = true;
                System.out.println(e.getMessage());
            }
        } else {
            System.out.println("It's game over, please reset the game");
        }
    }

    void play(String word) {
        this.play(new Word(word));
    }

    void restart() {
        words.clear();
        this.gameOver = false;
        System.out.println("Game restarted");
    }

    void printWords() {
        StringBuilder response = new StringBuilder("[");
        this.words.forEach(
                w -> response.append(w.value()).append(", ")
        );
        response.deleteCharAt(response.toString().length() - 1);
        response.deleteCharAt(response.toString().length() - 1);
        response.append("]");
        System.out.println(response);
    }

}

