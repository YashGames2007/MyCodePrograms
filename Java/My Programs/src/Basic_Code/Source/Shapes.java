package Basic_Code.Source;
import Basic_Code.Mini_Projects.Shapes._2D.*;
import Basic_Code.Mini_Projects.Shapes._3D.*;

public class Shapes {
    public static void main(String[] args) {

        Cube _Cube = new Cube(5);
        Cone _Cone = new Cone(5, 5);
        Circle _Circle = new Circle(5);
        Square _Square = new Square(5);
        Sphere _Sphere = new Sphere(5);
        Pyramid _Pyramid = new Pyramid(5, 5);
        Cuboid _Cuboid = new Cuboid(5, 5, 5);
        Cylinder _Cylinder = new Cylinder(5, 5);
        Triangle _Triangle = new Triangle(5, 5);
        Rectangle _Rectangle = new Rectangle(5, 5);

        _Cube.displayProperties();
        _Cone.displayProperties();
        _Cuboid.displayProperties();
        _Square.displayProperties();
        _Circle.displayProperties();
        _Sphere.displayProperties();
        _Pyramid.displayProperties();
        _Cylinder.displayProperties();
        _Triangle.displayProperties();
        _Rectangle.displayProperties();
        
    }
}
