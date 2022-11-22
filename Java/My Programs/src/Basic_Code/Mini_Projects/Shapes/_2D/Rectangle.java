package Basic_Code.Mini_Projects.Shapes._2D;

public class Rectangle implements Object_2D {

    private float length;
    private float width;

    public Rectangle(float length, float width) {
        modifyDimensions(length, width);
    }

    public void modifyDimensions(float length, float width) {
        this.length = length;
        this.width = width;
    }

    public void modifyLength(float length) {
        this.length = length;
    }

    public void modifyWidth(float width) {
        this.width = width;
    }

    public float getLength() {
        return length;
    }

    public float getWidth() {
        return width;
    }

    @Override
    public float getPerimeter() {
        return ((2 * length) + (2 * width));
    }

    @Override
    public double getArea() {
        return (length * width);
    }

    @Override
    public void displayProperties() {

        System.out.printf("\n");
        System.out.printf("\nObject Type: Rectangle");
        System.out.printf("\nLength: ");
        System.out.print(this.getLength());
        System.out.printf("\nWidth: ");
        System.out.print(this.getWidth());
        System.out.printf("\nPerimeter: ");
        System.out.print(this.getPerimeter());
        System.out.printf("\nArea: ");
        System.out.print(this.getArea());
        System.out.printf("\n");
    }

    public static void main(String[] args) {
        System.out.printf("\nPublic Class: Rectangle");
    }
}
