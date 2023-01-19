public class Main {
    public static void main(String[] args) {
        Sequence seq = new Substring(
                new Concatenated(
                    new Lowercased(
                        new Characters("HelloHELLO")
                    ), "Hi"), 5, 9);
        String string = seq.printedSeq();
        System.out.println(string);
    }
}