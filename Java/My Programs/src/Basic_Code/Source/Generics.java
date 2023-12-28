package Basic_Code.Source;

class My_Number <Type1, Type2> {
    Type1 rand1 (Type1 _1, Type1 _2) {
        return _1;
    }
    Type2 rand2 (Type2 _1, Type2 _2) {
        return _2;
    }
}

public class Generics {
    public static void main(String[] args) {
        My_Number<String, Integer> number = new My_Number<>();

        System.out.printf("\nHello World!");
        System.out.printf("\nType1: %s, Type2: %d", number.rand1("'", "null"), number.rand2(23, 32));
    }
}
