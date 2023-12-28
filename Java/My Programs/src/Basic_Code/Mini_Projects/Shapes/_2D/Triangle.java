package Basic_Code.Mini_Projects.Shapes._2D;

public class Triangle implements Object_2D {

    private float base;
    private float height;
    private float side1 = 0;
    private float side2 = 0;

    public Triangle(float base, float height) {
        modifyDimensions(base, height);
    }

    public void modifyDimensions(float base, float height) {
        this.base = base;
        this.height = height;
    }
    
    public void modifySides(float side1, float side2) {
        this.side1 = side1;
        this.side2 = side2;
    }

    public void modifyBase(float base) {
        this.base = base;
    }

    public void modifyHeight(float height) {
        this.height = height;
    }

    public float getBase() {
        return base;
    }

    public float getHeight() {
        return height;
    }

    public float getSide1() {
        return side1;
    }

    public float getSide2() {
        return side2;
    }
    
    @Override
    public float getPerimeter() {
        return (base + side1 + side2);
    }

    @Override
    public double getArea() {
        return (0.5 * base * height);
    }

    @Override
    public void displayProperties() {

        System.out.printf("\n");
        System.out.printf("\nObject Type: Triangle");
        System.out.printf("\nBase: ");
        System.out.print(this.getBase());
        System.out.printf("\nHeight: ");
        System.out.print(this.getHeight());
        System.out.printf("\nSide 1: ");
        System.out.print(this.getSide1());
        System.out.printf("\nSide 2: ");
        System.out.print(this.getSide2());
        System.out.printf("\nPerimeter: ");
        System.out.print(this.getPerimeter());
        System.out.printf("\nArea: ");
        System.out.print(this.getArea());
        System.out.printf("\n");
    }

    public static void main(String[] args) {
        System.out.printf("\nPublic Class: Triangle");
    }
}
