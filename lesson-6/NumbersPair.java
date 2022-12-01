public class NumbersPair {
    private int a;
    private int b;

    public NumbersPair(int a, int b) {
        this.a = a;
        this.b = b;
    }

    public int max(){
        return this.a > this.b ? this.a : this.b;
    }

    public int min(){
        return this.a < this.b ? this.a : this.b;
    }

    public double avg(){
        return (float) this.a + (float)this.b/2.0;
    }
}
