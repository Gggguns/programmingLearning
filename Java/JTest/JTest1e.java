/**
 * Created with IntelliJ IDEA.
 * Description:
 * User: Surface
 * Date: 2024-06-10
 * Time: 10:19
 */
import java.util.Scanner;
public class JTest1e {
    public static void main(String[] args){
        long n=0;
        while(n<2){
            //输出提示信息
            System.out.print("请输入n的值(n>=2):");
            //创建Scanner类
            Scanner scan=new Scanner(System.in);
            //接受数据
            n=scan.nextLong();
        }
        if(isPrime(n)){
            System.out.println(n+"是一个质数！");
        }
        else{
            System.out.println(n+"是一个合数！");
        }
    }
    public static boolean isPrime(long n){
        if(n==0||n==1)return false;
        for(long i=2;i<=n/i;i++){
            if(n%i==0)return false;
        }
        return true;
    }
}
