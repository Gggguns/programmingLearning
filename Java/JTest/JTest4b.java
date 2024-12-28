/**
 * Created with IntelliJ IDEA.
 * Description:
 * User: Surface
 * Date: 2024-06-11
 * Time: 12:01
 */
abstract class Shape {
    //抽象函数
    abstract double calArea();
}

//长方形
class Rectangle extends Shape {
    protected double length;
    protected double width;
    //构造函数
    public Rectangle(double length, double width) {
        this.length = length;
        this.width = width;
    }
    //计算面积
    @Override
    double calArea() {
        return length * width;
    }
}
//圆
class Circle extends Shape {
    private double radius;
    //构造函数
    public Circle(double radius) {
        this.radius = radius;
    }
    //计算面积
    @Override
    double calArea() {
        return Math.PI * radius * radius;
    }
}
//长方体
class Cube extends Rectangle {
    private double height;
    //构造函数
    public Cube(double length, double width, double height) {
        super(length, width);
        this.height = height;
    }
    //计算面积
    double calArea() {
        // Surface area of a cube: 2*(lw + lh + wh)
        return 2 * (length * width + length * height + width * height);
    }
    //计算体积
    double calVolume() {
        return length * width * height;
    }
}
public class JTest4b {
    public static void main(String[] args) {
        Cube cube = new Cube(2, 3, 4);
        System.out.println("Cube Surface Area: " + cube.calArea());
        System.out.println("Cube Volume: " + cube.calVolume());
    }
}
