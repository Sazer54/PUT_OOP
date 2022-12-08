import java.util.List;

public class Range {
    private String asString;
    private int beginningTime;
    private int endingTime;

    public Range(String asString) {
        this.asString = asString;
        this.analyseString();
    }

    private void analyseString(){
        String[] asParts = this.asString.split("-");
        this.beginningTime = Integer.parseInt(asParts[0]);
        this.endingTime = Integer.parseInt(asParts[1]);
    }

    public boolean contains(Range range) {
        return (this.beginningTime <= range.beginningTime
                && this.endingTime >= range.endingTime);
    }
}
