/**
 * Created with IntelliJ IDEA.
 * Description:
 * User: Surface
 * Date: 2024-06-10
 * Time: 20:11
 */
import java.util.Scanner;
class Person{
    //构造函数
    public Person(String name,String code){
        _name=name;
        _code=code;
    }
    //显示信息
    public void showInfo(){
        System.out.printf("姓名:%s\n编号:%s\n",_name,_code);
    }
    //属性
    protected String _name;
    protected String _code;
}
class Student extends Person{
    //构造函数
    public Student(String name,String code,double math,double english,double java){
        super(name,code);
        _math=math;
        _english=english;
        _java=java;
    }
    //计算平均成绩
    public double calAverage(){
        return (_math+_english+_java)/3;
    }
    //展示学生信息
    public void showInfo(){
        System.out.printf("姓名:%s\n",_name);
        System.out.printf("编号:%s\n",_code);
        System.out.printf("数学成绩:%.2f\n",_math);
        System.out.printf("英语成绩:%.2f\n",_english);
        System.out.printf("java成绩:%.2f\n",_java);
        System.out.printf("平均成绩:%.2f\n",calAverage());
    }
    //设置属性
    //数学
    public void setMath(){
        Scanner scan=new Scanner(System.in);
        System.out.print("请输入该学生的数学成绩:");
        _math=scan.nextDouble();
    }
    //英语
    public void setEnglish(){
        Scanner scan=new Scanner(System.in);
        System.out.print("请输入该学生的英语成绩:");
        _english=scan.nextDouble();
    }
    //java
    public void setJava(){
        Scanner scan=new Scanner(System.in);
        System.out.print("请输入该学生的Java成绩:");
        _java=scan.nextDouble();
    }
    //属性
    double _math;
    double _english;
    double _java;
}
public class JTest3d {
    public static void main(String[] args){
        Person P=new Person("卢卡斯","90");
        P.showInfo();
        Student S=new Student("手心啊","88",66.5,33,99);
        S.showInfo();
        System.out.printf("下面，请根据提示信息更新学生的成绩信息\n");
        S.setMath();
        S.setEnglish();
        S.setJava();
        S.showInfo();
    }
}
