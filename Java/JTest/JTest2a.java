/**
 * Created with IntelliJ IDEA.
 * Description:
 * User: Surface
 * Date: 2024-06-10
 * Time: 12:13
 */
import java.util.Scanner;
import java.util.Random;
public class JTest2a {
    public static void main(String[] args){
        //创建Scanner类
        Scanner scan=new Scanner(System.in);
        //获取数组长度
        System.out.print("请输入数组的长度:");
        int n=scan.nextInt();
        //定义大小为n的数组
        int[] arr=new int[n];
        //创建Random类，产生范围1000以内的随机数
        Random ran=new Random();
        //依次赋值，统计数组总和与已打印内容个数，求最大值及下标
        long Sum=0,size=0,Max=0,maxIndex=-1;
        for(int i=0;i<n;i++){
            //赋值
            arr[i]=ran.nextInt(1001);
            //求和
            Sum+=arr[i];
            //确定最大值
            if(i==0||arr[i]>Max){
                Max=arr[i];
                maxIndex=i;
            }
            //输出
            System.out.printf("%-4d",arr[i]);
            //格式控制
            size++;
            if(size<10)System.out.print("\t");
            else{
                size=0;
                System.out.println();
            }
        }
        System.out.println("该数组的数据总和为"+Sum+",最大值为"+Max+",第一个出现的最大值的下表为"+maxIndex);
    }
}
