package Basic_Code.Mini_Projects.Shapes._3D;

import Basic_Code.Mini_Projects.Shapes._2D.Circle;

public class Cylinder extends Circle implements Object_3D {

    private float height;

    public Cylinder(float radius, float height) {
        super(radius);
        this.height = height;
    }

    public void modifyHeight(float height) {
        this.height = height;
    }

    public void modifyDimensions(float radius, float height) {
        this.modifyRadius(radius);
        this.modifyHeight(height);
    }

    public float getHeight() {
        return height;
    }

    @Override
    public double getSurfaceArea() {
        float r = this.getRadius();
        float h = this.getHeight();

        return ((2.d * Math.PI * r * h) + (2 * Math.PI * r * r));
    }

    @Override
    public double getVolume() {
        float r = this.getRadius();
        float h = this.getHeight();

        return (Math.PI * r * r * h);
    }

    @Override
    public void displayProperties() {

        System.out.printf("\n");
        System.out.printf("\nObject Type: Cylinder");
        System.out.printf("\nRadius: ");
        System.out.print(this.getRadius());
        System.out.printf("\nHeight: ");
        System.out.print(this.getHeight());
        System.out.printf("\nArea: ");
        System.out.print(this.getArea());
        System.out.printf("\nVolume: ");
        System.out.print(this.getVolume());
        System.out.printf("\nSurface Area: ");
        System.out.print(this.getSurfaceArea());
        System.out.printf("\nCircumference: ");
        System.out.print(this.getCircumference());
        System.out.printf("\n");
    }

    public static void main(String[] args) {
        System.out.printf("\nPublic Class: Cylinder");
    }
}
