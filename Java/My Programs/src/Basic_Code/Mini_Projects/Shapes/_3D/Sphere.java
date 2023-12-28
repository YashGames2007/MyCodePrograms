package Basic_Code.Mini_Projects.Shapes._3D;

import Basic_Code.Mini_Projects.Shapes._2D.Circle;

public class Sphere extends Circle implements Object_3D {
    
    public Sphere(float radius) {
        super(radius);
    }

    @Override
    public double getSurfaceArea() {
        float r = this.getRadius();
        return (4.d * Math.PI * r * r);
    }

    @Override
    public double getVolume() {
        float r = this.getRadius();
        return ((4 / 3.d) * Math.PI * r * r * r);
    }

    @Override
    public void displayProperties() {

        System.out.printf("\n");
        System.out.printf("\nObject Type: Sphere");
        System.out.printf("\nRadius: ");
        System.out.print(this.getRadius());
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
        System.out.printf("\nPublic Class: Sphere");
    }
}
