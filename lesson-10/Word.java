import java.io.IOException;
import java.util.List;

public class Word {
    private final String value;

    public Word(String value) {
        this.value = value.toLowerCase();
    }

    String value() {
        return this.value;
    }
    boolean valid (List<Word> wordList, EnglishDictionary englishDictionary) throws IOException {
        //Check for invalid chars
        for (char c : this.value.toCharArray()) {
            //System.out.println(c);
            if (!(c >= 'a' && c <= 'z')) {
                String errorMessage = String.format("The word \"%s\" contains an invalid character: \"%c\"", this.value, c);
                throw new IOException(errorMessage);
            }
        }

        //Check if word exists in the english dictionary
        if (!englishDictionary.contains(this)) {
            String errorMessage = String.format("The word \"%s\" does not exist in the English language", this.value);
            throw new IOException(errorMessage);
        }

        if (wordList.isEmpty()) {
            return true;
        }

        // Check for last letter
        String lastPlayedWord = wordList.get(wordList.size()-1).value;
        if (lastPlayedWord.charAt(lastPlayedWord.length()-1) != this.value.charAt(0)) {
            String errorMessage = String.format(
                    "Last letter of the word \"%s\" is not equal to the first letter of the word \"%s\"",
                    lastPlayedWord, this.value);
            throw new IOException(errorMessage);
        }

        // Check for repeats
        for (Word word : wordList) {
            if (word.value.equals(this.value)) {
                String errorMessage = String.format("The word \"%s\" has already been played\n", this.value);
                throw new IOException(errorMessage);
            }
        }
        return true;
    }
}
