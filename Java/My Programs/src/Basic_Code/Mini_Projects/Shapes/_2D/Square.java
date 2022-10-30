package Basic_Code.Mini_Projects.Shapes._2D;

public class Square implements Object_2D{

    private float length;

    public Square(float length) {
        this.length = length;
    }

    public void modifyLength(float length) {
        this.length = length;
    }

    public float getLength() {
        return length;
    }

    @Override
    public float getPerimeter() {
        return (4 * length);
    }

    @Override
    public double getArea() {
        return (length * length);
    }

    @Override
    public void displayProperties() {

        System.out.printf("\n");
        System.out.printf("\nObject Type: Square");
        System.out.printf("\nLength: ");
        System.out.print(this.getLength());
        System.out.printf("\nPerimeter: ");
        System.out.print(this.getPerimeter());
        System.out.printf("\nArea: ");
        System.out.print(this.getArea());
        System.out.printf("\n");
    }

    public static void main(String[] args) {
        System.out.printf("\nPublic Class: Square");
    }
}
