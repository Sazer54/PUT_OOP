import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class Main {
    public static void main(String[] args) {
        NumbersPair pair = new NumbersPair(1,2);
        System.out.println(pair.max());
        System.out.println(pair.min());
        System.out.println(pair.avg());

        List<Logarithm> logs = new ArrayList<>(Arrays.asList(
                new Logarithm(2, 8),
                new Logarithm(-1, 8),
                new Logarithm(2, -1),
                new Logarithm(1, 8)
        )
        );
        
        for(Logarithm log : logs) {
            try {
                System.out.println(log.doubleValue());
            } catch (IllegalArgumentException e) {
                System.out.println("Exception was found: " + e.getMessage());
            }
        }
    }
}
