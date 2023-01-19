public class Concatenated implements Sequence{

    private Sequence a;
    private String b;

    public Concatenated(Sequence a, String b) {
        this.a = a;
        this.b = b;
    }

    @Override
    public String printedSeq() {
        return this.a.printedSeq() + this.b;
    }

}
