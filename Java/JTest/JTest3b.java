/**
 * Created with IntelliJ IDEA.
 * Description:
 * User: Surface
 * Date: 2024-06-10
 * Time: 18:13
 */
import java.util.Scanner;
import java.lang.Math;
class Triangle{
    //构造函数
    public Triangle(double edge1,double edge2,double edge3){
        _edge1=edge1;
        _edge2=edge2;
        _edge3=edge3;
    }
    //计算面积
    public double calArea(){
        if(isTriangle()){
            double s=(_edge1+_edge2+_edge3)/2;
            return Math.sqrt(s*(s-_edge1)*(s-_edge2)*(s-_edge3));
        }
        else{
            System.out.println("此时的三条边无法构成三角形,无法计算面积");
            return -1;
        }
    }
    //计算周长
    public double calPerimeter(){
        if(isTriangle()) return _edge1+_edge2+_edge3;
        else{
            System.out.println("此时的三条边无法构成三角形，无法计算周长");
            return -1;
        }
    }
    //设置属性
    //边一
    public void setEdge1(){
        Scanner scan=new Scanner(System.in);
        System.out.print("请输入你想将三角形的该边设置为:");
        _edge1=scan.nextDouble();
    }
    //边二
    public void setEdge2(){
        Scanner scan=new Scanner(System.in);
        System.out.print("请输入你想将三角形的该边设置为:");
        _edge2=scan.nextDouble();
    }
    //边三
    public void setEdge3(){
        Scanner scan=new Scanner(System.in);
        System.out.print("请输入你想将三角形的该边设置为:");
        _edge3=scan.nextDouble();
    }
    //判三角形合法
    public boolean isTriangle(){
        if(_edge1+_edge2>_edge3&&_edge2+_edge3>_edge1&&_edge1+_edge3>_edge2)return true;
        else return false;
    }
    //获取三角形的属性
    //边一
    public double getEdge1(){
        return _edge1;
    }
    //边二
    public double getEdge2(){
        return _edge2;
    }
    //边三
    public double getEdge3(){
        return _edge3;
    }
    //属性
    double _edge1;
    double _edge2;
    double _edge3;
}
public class JTest3b {
    public static void main(String[] args){
        Triangle T=new Triangle(3,4,5);
        System.out.printf("此时三角形的三条边依次为:%.2f,%.2f,%.2f\n",T.getEdge1(),T.getEdge2(),T.getEdge3());
        System.out.printf("此时三角形的面积和周长依次为:%.2f,%.2f\n",T.calArea(),T.calPerimeter());
        System.out.println("下面，请根据提示信息将三角形的三条边修改成你期望的值");
        T.setEdge1();
        T.setEdge2();
        T.setEdge3();
        System.out.printf("此时三角形的三条边依次为:%.2f,%.2f,%.2f\n",T.getEdge1(),T.getEdge2(),T.getEdge3());
        System.out.printf("此时三角形的面积和周长依次为:%.2f,%.2f\n",T.calArea(),T.calPerimeter());
    }
}
