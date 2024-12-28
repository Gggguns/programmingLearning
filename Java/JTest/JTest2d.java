/**
 * Created with IntelliJ IDEA.
 * Description:
 * User: Surface
 * Date: 2024-06-10
 * Time: 16:49
 */
import java.util.Scanner;
public class JTest2d {
    public static void main(String[] args){
        //创建Scanner类
        Scanner scan=new Scanner(System.in);
        while(true){
            //打印菜单
            menu();
            System.out.print("请输入你要选择的选项(比如:a):");
            String op=scan.next();
            System.out.println(op);
            if(op.equals("a")){
                //摄氏转华氏
                System.out.print("请输入你需要转换的摄氏温度(C>=-273.15C):");
                double C=scan.nextDouble();
                //判断是否大于绝对零度
                while(C<-273.15){
                    System.out.print("请输入大于等于-273.15C的摄氏温度:");
                    C=scan.nextDouble();
                }
                double F=9*C/5+32;
                System.out.printf("%.2fC与其对应的华氏温度为%.2fF\n",C,F);
            }
            else if(op.equals("b")){
                //华氏转摄氏
                System.out.print("请输入你需要转换的华氏温度(F>=-459.67F):");
                double F=scan.nextDouble();
                //判断是否大于绝对零度
                while(F<-459.67F){
                    System.out.print("请输入大于等于-459.67F的华氏温度:");
                    F=scan.nextDouble();
                }
                double C=5*(F-32)/9;
                System.out.printf("%.2fF与其对应的摄氏温度为%.2f\n",F,C);
            }
            else if(op.equals("c")){
                //关闭程序
                System.out.println("程序已关闭");
                break;
            }
            else System.out.println("很抱歉，没有这个选项");
        }
    }
    //菜单
    public static void menu(){
        System.out.printf("*********************************\n");
        System.out.printf("**      a) 摄氏温度转华氏温度      **\n");
        System.out.printf("**      b) 华氏温度转摄氏温度      **\n");
        System.out.printf("**      c)     关闭程序          **\n");
        System.out.printf("*********************************\n");
    }
}
