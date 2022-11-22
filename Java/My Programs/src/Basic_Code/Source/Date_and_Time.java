package Basic_Code.Source;

import java.lang.Long;
import java.util.Date;

public class Date_and_Time {
    public static void main(String[] args) {
        System.out.printf("\nHello World!");
        System.out.printf("\nLong: %d", Long.MAX_VALUE);
        System.out.printf("\nTime: %d", System.currentTimeMillis());
        Date d = new Date();
        System.out.printf("\n");
        System.out.println(d);
    }
}
