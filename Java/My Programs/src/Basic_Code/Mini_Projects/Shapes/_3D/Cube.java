package Basic_Code.Mini_Projects.Shapes._3D;

import Basic_Code.Mini_Projects.Shapes._2D.Square;

public class Cube extends Square implements Object_3D {

    public Cube(float length) {
        super(length);
    }

    @Override
    public double getVolume() {
        return (this.getArea() * this.getLength());
    }

    @Override
    public double getSurfaceArea() {
        return (6 * this.getArea());
    }
    
    @Override
    public void displayProperties() {

        System.out.printf("\n");
        System.out.printf("\nObject Type: Cube");
        System.out.printf("\nLength: ");
        System.out.print(this.getLength());
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
        System.out.printf("\nPublic Class: Cube");
    }
}
