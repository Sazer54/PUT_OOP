import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class Rucksack {
    private String firstItem;
    private String secondItem;
    private Character duplicate;

    public Rucksack(String line) {
        int mid = line.length();
        this.firstItem = line.substring(0, mid);
        this.secondItem = line.substring(mid);
        this.duplicate();
    }

    public void duplicate(){
        HashMap<Character, Integer> occurrences = new HashMap<>();
        for(Character c : this.firstItem.toCharArray()){
            if (occurrences.containsKey(c)) {
                occurrences.put(c, occurrences.get(c)+1);
            }
            else {
                occurrences.put(c, 1);
            }
        }
        for(Character c : this.secondItem.toCharArray()){
            if (occurrences.containsKey(c)) {
                occurrences.put(c, occurrences.get(c)+1);
            }
            else {
                occurrences.put(c, 1);
            }
        }
        for (Map.Entry<Character, Integer> entry : occurrences.entrySet()) {
            if (entry.getValue()>=1){
                this.duplicate = entry.getKey();
                break;
            }
        }
    }
    public int priorityOfDup() {
        if (this.duplicate >= 'a' && this.duplicate <= 'z') {
            return (int)this.duplicate - 96;
        }
        return (int)this.duplicate - 38;
    }

}
