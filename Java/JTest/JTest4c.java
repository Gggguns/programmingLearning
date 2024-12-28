/**
 * Created with IntelliJ IDEA.
 * Description:
 * User: Surface
 * Date: 2024-06-11
 * Time: 12:19
 */
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Random;
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
public class JTest4c {
    public static void main(String[] args) {
        List<Shape> shapes = generateRandomShapes(10);
        sortShapesByArea(shapes);
    }
    //随机生成一个图形
    private static List<Shape> generateRandomShapes(int n) {
        List<Shape> shapes = new ArrayList<>();
        Random rand = new Random();

        for (int i = 0; i < n; i++) {
            int shapeType = rand.nextInt(3); // 0: Rectangle, 1: Circle, 2: Cube
            switch (shapeType) {
                case 0:
                    double length = rand.nextDouble() * 10 + 1;
                    double width = rand.nextDouble() * 10 + 1;
                    shapes.add(new Rectangle(length, width));
                    break;
                case 1:
                    double radius = rand.nextDouble() * 10 + 1;
                    shapes.add(new Circle(radius));
                    break;
                case 2:
                    length = rand.nextDouble() * 10 + 1;
                    width = rand.nextDouble() * 10 + 1;
                    double height = rand.nextDouble() * 10 + 1;
                    shapes.add(new Cube(length, width, height));
                    break;
            }
        }
        return shapes;
    }
    //按面积排序
    private static void sortShapesByArea(List<Shape> shapes) {
        Collections.sort(shapes, (s1, s2) -> Double.compare(s1.calArea(), s2.calArea()));

        for (Shape shape : shapes) {
            if (shape instanceof Cube) {
                System.out.println("Cube: Area = " + shape.calArea() + ", Volume = " + ((Cube) shape).calVolume());
            } else {
                System.out.println(shape.getClass().getSimpleName() + ": Area = " + shape.calArea());
            }
        }
    }
}
