/**
 * Created with IntelliJ IDEA.
 * Description:
 * User: Surface
 * Date: 2024-06-10
 * Time: 9:56
 */
import java.util.Scanner;
public class JTest1d {
    public static void main(String[] args){
        //定义输入
        Scanner scan=new Scanner(System.in);
        //获取用户身高体重
        System.out.print("你的身高(单位: 米):");
        double height=scan.nextDouble();
        System.out.print("你的体重(单位:公斤):");
        double weight=scan.nextDouble();
        //计算身体质量指数
        double bMI=weight/height;
        //输出相关信息
        System.out.print("你的身高为"+height+"米，体重为"+weight+"公斤，身体质量属于");
        //判断
        if(bMI<=18)System.out.print("偏瘦");
        else if(bMI<=25)System.out.print("正常体重");
        else if(bMI<=30)System.out.print("超重");
        else if(bMI<=35)System.out.print("轻度肥胖");
        else if(bMI<=40)System.out.print("中度肥胖");
        else System.out.print("重度肥胖");
        System.out.println("!");
    }
}
