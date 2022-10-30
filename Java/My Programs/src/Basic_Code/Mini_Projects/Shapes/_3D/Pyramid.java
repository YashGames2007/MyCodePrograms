package Basic_Code.Mini_Projects.Shapes._3D;

import Basic_Code.Mini_Projects.Shapes._2D.Square;

public class Pyramid extends Square implements Object_3D {

    private float height;

    public Pyramid(float length, float height) {
        super(length);
        this.height = height;
    }

    public void modifyHeight(float height) {
        this.height = height;
    }

    public void modifyDimensions(float length, float height) {
        this.modifyLength(length);
        this.modifyHeight(height);
    }

    public float getHeight() {
        return height;
    }

    @Override
    public double getSurfaceArea() {
        float a = this.getLength();
        float h = this.getHeight();

        double root = ((a * a) / 4.d) + (h * h);
        double area = (a * a) + (2.d * a);
        return (area * Math.sqrt(root));
    }
    
    @Override
    public double getVolume() {
        float a = this.getLength();
        float h = this.getHeight();

        return ((a * a) * (h / 3.d));
    }

    @Override
    public void displayProperties() {

        System.out.printf("\n");
        System.out.printf("\nObject Type: Pyramid");
        System.out.printf("\nLength: ");
        System.out.print(this.getLength());
        System.out.printf("\nHeight: ");
        System.out.print(this.getHeight());
        System.out.printf("\nArea: ");
        System.out.print(this.getArea());
        System.out.printf("\nVolume: ");
        System.out.print(this.getVolume());
        System.out.printf("\nPerimeter: ");
        System.out.print(this.getPerimeter());
        System.out.printf("\nSurface Area: ");
        System.out.print(this.getSurfaceArea());
        System.out.printf("\n");
    }

    public static void main(String[] args) {
        System.out.printf("\nPublic Class: Pyramid");
    }
}
