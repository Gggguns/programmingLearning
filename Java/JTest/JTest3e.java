/**
 * Created with IntelliJ IDEA.
 * Description:
 * User: Surface
 * Date: 2024-06-10
 * Time: 21:30
 */
import java.util.Vector;
import java.util.Random;
import java.util.Scanner;
class Student{
    //构造函数
    public Student(String name,String num,double computerNetwork,double java,double english){
        _name=name;
        _num=num;
        _computerNetwork=computerNetwork;
        _java=java;
        _english=english;
        _totalScore=_computerNetwork+_java+_english;
        countFlunkSize();
    }
    public Student(Student S){
        _name=S._name;
        _num=S._num;
        _computerNetwork=S._computerNetwork;
        _java=S._java;
        _english=S._english;
        _totalScore=S._totalScore;
        _flunkSize=S._flunkSize;
    }
    //统计不及格课程数量
    public void countFlunkSize(){
        _flunkSize=0;
        if(_english<60)_flunkSize++;
        if(_computerNetwork<60)_flunkSize++;
        if(_java<60)_flunkSize++;
    }
    //打印表头
    public static void showHead(){
        System.out.println("***********************************************************");
        System.out.printf("%-3s\t\t%-3s\t%-5s\t%-1s\t\t%-4s\t%-3s\n","姓名","学号","计算机网络","java","英语","总成绩");
    }
    //打印表尾巴
    public static void showTail(){
        System.out.println("***********************************************************");
    }
    //打印学生信息
    public void showStudent(){
        System.out.printf("%-3s\t\t%-3s\t\t%-5.2f\t\t%-1.2f\t\t%-4.2f\t%-3.2f\n",
                _name,_num,_computerNetwork,_java,_english,_totalScore);
    }
    //属性
    String _name;
    String _num;
    double _computerNetwork;
    double _java;
    double _english;
    int _flunkSize;
    double _totalScore;
}
class Class{
    public Class(){
        Scanner scan=new Scanner(System.in);
        _students=new Vector<Student>();
        _totalScoreMaxArr=new Vector<Student>();
        _computerNetworkScoreMaxArr=new Vector<Student>();
        _javaScoreMaxArr=new Vector<Student>();
        _englishScoreMaxArr=new Vector<Student>();
        System.out.print("请输入你想随机生成的班级大小:");
        int n=scan.nextInt();
        for(int i=0;i<n;i++){
            addStudent(randomCreateStudent(i));
        }
    }
    //更新属性值
    //随机生成学生
    Student randomCreateStudent(int i){
        Random ran=new Random();
        String surname="李张陈黄周林何宋郑谢冯于袁邓许傅苏蒋叶阎潘戴夏范方石姚廖孔康江史邵段雷汤尹武赖樊兰殷陶翟安倪严牛温芦俞葛";
        String firstName="一二三四五六看潇填好海宽顶光宗耀祖";
        //创建可扩容字符串
        StringBuilder name=new StringBuilder();
        //用随机数随机确定姓
        int ranNum=ran.nextInt(surname.length());
        name.append(surname.charAt(ranNum));
        //再次生成随机数，确定名的为两个字还是一个字
        ranNum=(ran.nextInt(firstName.length())+1)%3;
        if(ranNum==1){
            //取一次
            ranNum=ran.nextInt(surname.length());
            name.append(surname.charAt(ranNum));
        }
        else{
            //取两次
            ranNum=ran.nextInt(surname.length());
            name.append(surname.charAt(ranNum));
            ranNum=ran.nextInt(surname.length());
            name.append(surname.charAt(ranNum));
        }
        //随机生成成绩
        double computerNetworkScore=(ran.nextDouble()+100)%100*100;
        double englishScore=(ran.nextDouble()+100)%100*100;
        double javaScore=(ran.nextDouble()+100)%100*100;
        //增加到学生表中
        Student S=new Student(name.toString(),Integer.toString(i+1),computerNetworkScore,javaScore,englishScore);
        return S;
    }
    //增加学生信息
    public void addStudent(Student S){
        _students.add(S);
        //判断总成绩最高
        if(S._totalScore==_totalScoreMax)addTotalScoreMaxArr(S);
        else if(S._totalScore>_totalScoreMax){
            _totalScoreMax=S._totalScore;
            setTotalScoreMaxArr(S);
        }
        //判断单科成绩最高
        //计算机网络
        if(S._computerNetwork==_computerNetworkScoreMax)addComputerNetworkScoreMaxArr(S);
        else if(S._computerNetwork>_computerNetworkScoreMax){
            _computerNetworkScoreMax=S._computerNetwork;
            setComputerNetworkScoreMaxArr(S);
        }
        //java
        if(S._java==_javaScoreMax)addJavaScoreMaxArr(S);
        else if(S._java>_javaScoreMax){
            _javaScoreMax=S._java;
            setJavaScoreMaxArr(S);
        }
        //英语
        if(S._english==_englishScoreMax)addEnglishScoreMaxArr(S);
        else if(S._english>_englishScoreMax){
            _englishScoreMax=S._english;
            setEnglishScoreMaxArr(S);
        }
    }
    //java最高成绩
    public void setJavaScoreMax(double Score){
        _javaScoreMax=Score;
    }
    //计算机网络最高成绩
    public void setComputerNetworkScoreMax(double Score){
        _computerNetworkScoreMax=Score;
    }
    //英语最高成绩
    public void setEnglishScoreMax(double Score){
        _englishScoreMax=Score;
    }
    //总成绩最高
    public void setTotalScore(double Score){
        _totalScoreMax=Score;
    }
    //增加总成绩最高学生信息
    public void addTotalScoreMaxArr(Student S){
        _totalScoreMaxArr.add(S);
    }
    //增加计算机网络成绩最高学生信息
    public void addComputerNetworkScoreMaxArr(Student S){
        _computerNetworkScoreMaxArr.add(S);
    }
    //增加英语成绩最高学生信息
    public void addEnglishScoreMaxArr(Student S){
        _englishScoreMaxArr.add(S);
    }
    //增加java成绩最高学生信息
    public void addJavaScoreMaxArr(Student S){
        _javaScoreMaxArr.add(S);
    }
    //重新设置总成绩最高学生信息表
    public void setTotalScoreMaxArr(Student S){
        _totalScoreMaxArr.clear();
        _totalScoreMaxArr.add(S);
    }
    //重新设置计算机网络成绩最高学生信息表
    public void setComputerNetworkScoreMaxArr(Student S){
        _computerNetworkScoreMaxArr.clear();
        _computerNetworkScoreMaxArr.add(S);
    }
    //重新设置英语成绩最高学生信息表
    public void setEnglishScoreMaxArr(Student S){
        _englishScoreMaxArr.clear();
        _englishScoreMaxArr.add(S);
    }
    //重新设置java成绩最高学生信息表
    public void setJavaScoreMaxArr(Student S){
        _javaScoreMaxArr.clear();
        _javaScoreMaxArr.add(S);
    }
    //显示两科以上未及格信息
    void showFailedMoreThanTwoStudent(){
        Student.showHead();
        for(Student s:_students){
            if(s._flunkSize>=2)s.showStudent();
        }
        Student.showTail();
    }
    //显示一科以上未及格信息
    void showFailedMoreThanOneStudent(){
        Student.showHead();
        for(Student s:_students){
            if(s._flunkSize>=1)s.showStudent();
        }
        Student.showTail();
    }
    //显示表中的学生信息
    public void showStudentList(Vector<Student> v){
        Student.showHead();
        for(Student S:v)S.showStudent();
        Student.showTail();
    }
    //显示总成绩最高的学生信息
    public void showStudentListTotalScoreMax(){
        showStudentList(_totalScoreMaxArr);
    }
    //显示计算机网络成绩最高的学生信息
    public void showStudentListComputerNetworkScoreMax(){
        showStudentList(_computerNetworkScoreMaxArr);
    }
    //显示java成绩最高学生信息
    public void showStudentListJavScoreMax(){
        showStudentList(_javaScoreMaxArr);
    }
    //显示英语成绩最高学生信息
    public void showStudentListEnglishScoreMax(){
        showStudentList(_englishScoreMaxArr);
    }
    //显示班级所有学生信息
    public void showStudentListClass(){
        showStudentList(_students);
    }
    //姓名查找
    public void nameFind(String name){
        Vector<Student> Res=new Vector<Student>();
        for(Student S:_students){
            if(S._name.equals(name))Res.add(S);
        }
        if(Res.size()>0)showStudentList(Res);
        else System.out.println("很抱歉，没有在该班级查到此人的信息");
    }
    //学号查找
    public void numFind(String num){
        Vector<Student> Res=new Vector<Student>();
        for(Student S:_students){
            if(S._num.equals(num))Res.add(S);
        }
        if(Res.size()>0)showStudentList(Res);
        else System.out.println("很抱歉，没有在该班级查到此人的信息");
    }
    //属性
    Vector<Student> _totalScoreMaxArr;         //总成绩最高的学生信息表
    Vector<Student> _computerNetworkScoreMaxArr;  //计算机网络成绩最高的学生信息表
    Vector<Student> _englishScoreMaxArr;        //计算机网络成绩最高的学生信息表
    Vector<Student> _javaScoreMaxArr;           //java成绩最高的学生信息表

    Vector<Student> _students;                 //班级的学生信息表
    double _totalScoreMax=0;                   //总成绩最高值
    double _computerNetworkScoreMax=0;         //计算机网络成绩最高值
    double _englishScoreMax=0;                 //英语成绩最高值
    double _javaScoreMax=0;                    //java成绩最高值
}
public class JTest3e {
    public static void main(String[] args){
        Class C=new Class();
        Scanner scan=new Scanner(System.in);
        //显示班级所有学生信息
        System.out.printf("\n班级所有学生信息表\n");
        C.showStudentListClass();
        //显示分别显示班级总成绩最高和单科最高学生信息
        //总成绩
        System.out.printf("\n总成绩最高学生信息表\n");
        C.showStudentListTotalScoreMax();
        //计算机网络
        System.out.printf("\n计算机网络成绩最高学生信息表\n");
        C.showStudentListComputerNetworkScoreMax();
        //java
        System.out.printf("\njava成绩最高学生信息表\n");
        C.showStudentListJavScoreMax();
        //英语
        System.out.printf("\n英语成绩最高学生信息表\n");
        C.showStudentListEnglishScoreMax();
        System.out.printf("请输入你要查找的学生的姓名:");
        String name=scan.next();
        C.nameFind(name);
        System.out.printf("请输入你要查找的学生的学号:");
        String num=scan.next();
        C.nameFind(num);
        //一科以上不及格的学生信息表
        System.out.println("\n一科以上不及格的学生信息表");
        C.showFailedMoreThanOneStudent();
        //两科以上不及格的学生信息表
        System.out.println("\n两科以上不及格的学生信息表");
        C.showFailedMoreThanTwoStudent();
    }
}
