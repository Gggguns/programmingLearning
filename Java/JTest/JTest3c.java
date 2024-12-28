/**
 * Created with IntelliJ IDEA.
 * Description:
 * User: Surface
 * Date: 2024-06-10
 * Time: 19:13
 */
import java.util.Scanner;
class Complex{
    //构造函数
    public Complex(double real,double image){
        _real=real;
        _image=image;
    }
    //拷贝构造
    public Complex(Complex C){
        _real=C._real;
        _image=C._image;
    }
    //复数相乘
    public Complex multiply(Complex C){
        Complex Ret=new Complex(C._real*_real+ C._image*_image,C._image*_real+C._real*_image);
        return Ret;
    }
    //复数相加
    public Complex add(Complex C){
        Complex Ret=new Complex(C._real+_real,C._image+_image);
        return Ret;
    }
    //设置属性
    //实部
    public void setReal(){
        Scanner scan=new Scanner(System.in);
        System.out.print("请输入你期望将实部设置为:");
        _real=scan.nextDouble();
    }
    //虚部
    public void setImage(){
        Scanner scan=new Scanner(System.in);
        System.out.print("请输入你期望将虚部设置为:");
        _image=scan.nextDouble();
    }
    //获取属性
    //实部
    public double getReal(){
        return _real;
    }
    //虚部
    public double getImage(){
        return _image;
    }
    //属性
    //实部
    double _real;
    double _image;
}
public class JTest3c {
    public static void main(String[] args){
        Complex C1=new Complex(1,1);
        Complex C2=new Complex(-2,1);
        System.out.printf("复数C1为%.2f %.2fi\n",C1.getReal(),C1.getImage());
        System.out.printf("复数C2为%.2f %.2fi\n",C2.getReal(),C2.getImage());
        Complex mulRes=C1.multiply(C2);
        Complex addRes=C1.add(C2);
        System.out.printf("C1+C2的结果为:%.2f %.2fi\n",addRes.getReal(),addRes.getImage());
        System.out.printf("C1*C2的结果为:%.2f %.2fi\n",mulRes.getReal(),mulRes.getImage());
        System.out.println("下面，请根据提示信息将C1设置成你期望的值");
        C1.setReal();
        C1.setImage();
        System.out.printf("复数C1为%.2f %.2fi\n",C1.getReal(),C1.getImage());
        System.out.printf("复数C2为%.2f %.2fi\n",C2.getReal(),C2.getImage());
        mulRes=C1.multiply(C2);
        addRes=C1.add(C2);
        System.out.printf("C1+C2的结果为:%.2f %.2fi\n",addRes.getReal(),addRes.getImage());
        System.out.printf("C1*C2的结果为:%.2f %.2fi\n",mulRes.getReal(),mulRes.getImage());
    }
}
