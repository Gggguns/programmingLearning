/**
 * Created with IntelliJ IDEA.
 * Description:
 * User: Surface
 * Date: 2024-06-10
 * Time: 17:26
 */
import java.util.Scanner;
class Cube{
    //构造函数
    public Cube(double length,double width,double height){
        _length=length;
        _width=width;
        _height=height;
    }
    //计算表面积
    public double calArea(){
        return 2*(_length*_width+_width*_height+_length*_height);
    }
    //计算体积
    public double calVolume(){
        return _length*_width*_height;
    }
    //修改属性
    public void setLength(){
        Scanner scan=new Scanner(System.in);
        System.out.print("请输入你想将长方体的长设置为:");
        _length=scan.nextDouble();
    }
    public void setWidth(){
        Scanner scan=new Scanner(System.in);
        System.out.print("请输入你想将长方体的宽设置为:");
        _width=scan.nextDouble();
    }
    public void setHeight(){
        Scanner scan=new Scanner(System.in);
        System.out.print("请输入你想将长方体的高设置为:");
        _height=scan.nextDouble();
    }
    //获取属性
    public double getLength(){
        return _length;
    }
    public double getWidth(){
        return _width;
    }
    public double getHeight(){
        return _height;
    }
    //属性
    double _length;
    double _width;
    double _height;
}
public class JTest3a {
    public static void main(String[] args){
        Cube C=new Cube(3,3,3);
        System.out.printf("此时长方体的长宽高依次为:%.2f,%.2f,%.2f\n",C.getLength(),C.getWidth(),C.getHeight());
        System.out.printf("此时它的表面积和体积依次为:%.2f,%.2f",C.calArea(),C.calVolume());
        System.out.printf("下面，你可以根据提示将长方体的长宽高修改成你想设置的值\n");
        C.setLength();
        C.setWidth();
        C.setHeight();
        System.out.printf("此时长方体的长宽高依次为:%.2f,%.2f,%.2f\n",C.getLength(),C.getWidth(),C.getHeight());
        System.out.printf("此时它的表面积和体积依次为:%.2f,%.2f",C.calArea(),C.calVolume());
    }
}
