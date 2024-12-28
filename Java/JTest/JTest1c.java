import java.util.Scanner;

/**
 * Created with IntelliJ IDEA.
 * Description:
 * User: Surface
 * Date: 2024-06-10
 * Time: 9:33
 */

public class JTest1c {
    public static void main(String[] args){
        //定义输入
        Scanner scan=new Scanner(System.in);
        //获取身高体重
        System.out.print("你的身高(单位: 米):");
        double height=scan.nextDouble();
        System.out.print("你的体重(单位:公斤):");
        double weight=scan.nextDouble();
        System.out.println("你的身高为"+height+"米,体重为"+weight+"公斤！");
    }
}
