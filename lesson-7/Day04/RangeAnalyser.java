public class RangeAnalyser {
    private Range first;
    private Range second;

    public RangeAnalyser() {
    }
    public void rangesFromString(String string) {
        String[] asArray = string.split(",");
        this.first = new Range(asArray[0]);
        this.second = new Range(asArray[1]);
    }

    public boolean containEachOther() {
        return (this.first.contains(this.second)
                || this.second.contains(this.first));
    }
}
