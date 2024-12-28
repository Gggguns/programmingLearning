/**
 * Created with IntelliJ IDEA.
 * Description:
 * User: Surface
 * Date: 2024-06-10
 * Time: 11:06
 */
public class JTest1f {
    public static void main(String[] args){
        //确定数据范围及已打印个数
        int range=2000,size=0;
        for(int i=0;i<=range;i++){
            if(isPrime(i)){
                System.out.printf("%-4d",i);
                size++;
                if(size<15)System.out.print("\t");
                else{
                    size=0;
                    System.out.println();
                }
            }
        }
    }
    //判素数
    public static boolean isPrime(int n){
        if(n==1||n==0)return false;
        for(int i=2;i<=n/i;i++){
            if(n%i==0)return false;
        }
        return true;
    }
}
