/**
 * Created with IntelliJ IDEA.
 * Description:
 * User: Surface
 * Date: 2024-06-10
 * Time: 14:55
 */
import java.util.HashMap;
import java.util.Random;
public class JTest2b {
    public static void main(String[] args){
        //确定二维数组大小
        int n=5,m=6;
        //创建Random类
        Random ran=new Random();
        //利用arr保存每一列和每一行的最大值
        int[] maxRows=new int[n];
        int[] maxCols=new int[m];
        //创建数组
        int[][] data=new int[5][6];
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                //产生随机数
                data[i][j]=ran.nextInt(100);
                //确定行列的最大值
                if(i==0||maxRows[i]<data[i][j])maxRows[i]=data[i][j];
                if(j==0||maxCols[j]<data[i][j])maxCols[j]=data[i][j];
            }
        }
        //记录结果
        boolean flag=false;
        int row=0,col=0,res=0;
        //将列的最大值全部放到HashMap中
        HashMap<Integer,Integer> hash=new HashMap<Integer,Integer>();
        for(int i=0;i<m;i++){
            hash.put(maxCols[i],i);
        }
        //遍历行的最大值
        for(int i=0;i<n;i++){
            if(hash.containsKey(maxRows[i])){
                flag=true;
                row=i;
                col=hash.get(maxRows[i]);
                res=maxRows[i];
                break;
            }
        }
        //二维数组打印
        System.out.println("随机生成的二维数组内容如下:");
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                System.out.printf("%-3d\t",data[i][j]);
            }
            System.out.println();
        }
        //输出是否存在行列最大的元素和行列最大的所有数
        System.out.print("每行最大的元素依次为:");
        for(int x:maxRows){
            System.out.printf("%-3d",x);
        }
        System.out.print("\n每列最大的元素以此为:");
        for(int x:maxCols){
            System.out.printf("%-3d",x);
        }
        if(flag){
            System.out.print("\n存在行列都为最大值的元素:"+res+",它在数组中第"+row+"行第"+col+"列\n");
        }
        else System.out.print("\n没有这样的元素\n");
    }
}
