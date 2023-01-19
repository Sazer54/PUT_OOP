public class Lowercased implements Sequence{
    private Sequence s;

    public Lowercased(Sequence s) {
        this.s = s;
    }

    @Override
    public String printedSeq() {
        return s.printedSeq().toLowerCase();
    }
}
