/**
 * Created with IntelliJ IDEA.
 * Description:
 * User: Surface
 * Date: 2024-06-11
 * Time: 11:46
 */
abstract class Shape {
    //抽象函数
    abstract double calArea();
}
//长方形
class Rectangle extends Shape {
    private double length;
    private double width;

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

// 测试代码

public class JTest4a {
    public static void main(String[] args) {
        Rectangle rect = new Rectangle(5, 3);
        System.out.println("Rectangle Area: " + rect.calArea());

        Circle circle = new Circle(4);
        System.out.println("Circle Area: " + circle.calArea());
    }
}
