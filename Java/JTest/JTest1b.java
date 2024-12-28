import java.util.Scanner;

/**
 * Created with IntelliJ IDEA.
 * Description:
 * User: Surface
 * Date: 2024-06-09
 * Time: 22:20
 */
public class JTesta1b {
    public static void main(String[] args){
        int x=0,y=0,z=0;
        //定义输入
        Scanner scan=new Scanner(System.in);
        //输出提示信息
        System.out.print("请输入要想加的两个，以空格为间隔:");
        //获取x,y
        x=scan.nextInt();
        y=scan.nextInt();
        //计算结果
        z=x+y;
        //输出结果
        System.out.println(x+"+"+y+"="+z);
    }
}
