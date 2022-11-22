package Basic_Code.Mini_Projects.Shapes._3D;

import Basic_Code.Mini_Projects.Shapes._2D.Rectangle;

public class Cuboid extends Rectangle implements Object_3D {

    private float height;

    public Cuboid(float length, float width, float height) {
        super(length, width);
        this.height = height;
    }

    public void modifyDimensions(float length, float width, float height) {
        this.modifyDimensions(length, width);
        this.height = height;
    }

    public void modifyHeight(float height) {
        this.height = height;
    }

    public float getHeight() {
        return height;
    }

    @Override
    public double getVolume() {
        return (this.getArea() * this.height);
    }

    @Override
    public double getSurfaceArea() {

        float l = this.getLength();
        float w = this.getWidth();
        float h = this.getHeight();
        return ((2 * l * w) + (2 * l * h) + (2 * h * w));
    }

    @Override
    public void displayProperties() {

        System.out.printf("\n");
        System.out.printf("\nObject Type: Cuboid");
        System.out.printf("\nLength: ");
        System.out.print(this.getLength());
        System.out.printf("\nWidth: ");
        System.out.print(this.getWidth());
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
        System.out.printf("\nPublic Class: Cuboid");
    }
}
