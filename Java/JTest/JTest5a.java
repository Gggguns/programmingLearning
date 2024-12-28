/**
 * Created with IntelliJ IDEA.
 * Description:
 * User: Surface
 * Date: 2024-06-11
 * Time: 15:09
 */

import javax.swing.*;
import java.awt.*;
public class JTest5a {
    public static void main(String[] args) {
        //创建JFrame对象
        JFrame frame=new JFrame("First GUI Program");
        //设置窗口大小
        frame.setSize(500,300);
        //设置背景颜色
        frame.getContentPane().setBackground(Color.RED);
        //设置窗口关闭则程序关闭
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        //将窗口设为可视化和居中
        frame.setLocationRelativeTo(null);
        frame.setVisible(true);
    }
}
