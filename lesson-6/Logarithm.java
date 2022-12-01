public class Logarithm implements Number{
    private double base;
    private double argument;

    @Override
    public double doubleValue() throws IllegalArgumentException{
        if (!(this.base > 0)) {
            throw new IllegalArgumentException(
                    "Base has to be positive"
            );
        }
        if (!(this.argument > 0)) {
            throw new IllegalArgumentException(
                    "Argument has to be positive"
            );
        }
        if (this.base == 1) {
            throw new IllegalArgumentException(
                    "Base cannot be 1"
            );
        }
        return Math.log(this.argument) / Math.log(this.base);
    }

    public Logarithm(double base, double argument) {
        this.base = base;
        this.argument = argument;
    }
}
