package Basic_Code.Mini_Projects.Shapes._2D;

// import java.lang.Math.*;

public class Circle implements Object_2D {

    private float radius;

    public Circle(float radius) {
        this.radius = radius;
    }

    public void modifyRadius(float radius) {
        this.radius = radius;
    }

    public float getRadius() {
        return radius;
    }

    public float getDiameter() {
        return (radius * 2.f);
    }

    public double getCircumference() {
        return (2 * Math.PI * radius);
    }

    @Override
    public float getPerimeter() {
        return (float) getCircumference();
    }

    @Override
    public double getArea() {
        return (Math.PI * radius * radius);
    }

    @Override
    public void displayProperties() {

        System.out.printf("\n");
        System.out.printf("\nObject Type: Circle");
        System.out.printf("\nRadius: ");
        System.out.print(this.getRadius());
        System.out.printf("\nCircumference: ");
        System.out.print(this.getCircumference());
        System.out.printf("\nArea: ");
        System.out.print(this.getArea());
        System.out.printf("\n");
    }

    public static void main(String[] args) {
        System.out.printf("\nPublic Class: Circle");
    }

}
