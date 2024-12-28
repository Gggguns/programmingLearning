/**
 * Created with IntelliJ IDEA.
 * Description:
 * User: Surface
 * Date: 2024-06-11
 * Time: 17:29
 */
import java.util.*;
import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
public class JTest5c {
    public static void main(String[] args){
        //创建一个窗口
        JFrame frame=new JFrame("Red And Green");
        //设置frame的布局器
        frame.setLayout(new BorderLayout());
        //设置大小
        frame.setSize(500,300);
        //设置居中
        frame.setLocationRelativeTo(null);
        //创建容器panel
        JPanel panel=new JPanel();
        //设置布局器
        panel.setLayout(new FlowLayout(FlowLayout.LEFT,90,70));
        //创建组件
        JButton redButton=new JButton("red");
        JButton greenButton=new JButton("green");
        //设置按钮大小
        Dimension buttonSize=new Dimension(100,100);
        redButton.setPreferredSize(buttonSize);
        greenButton.setPreferredSize(buttonSize);
        //设置监听
        redButton.addActionListener(new ActionListener(){
            public void actionPerformed(ActionEvent e){
                panel.setBackground(Color.RED);
            }
        });
        greenButton.addActionListener(new ActionListener(){
           public void actionPerformed(ActionEvent e){
               panel.setBackground(Color.GREEN);
           }
        });
        //将组件增加到panel中
        panel.add(redButton);
        panel.add(greenButton);
        //将panel放置到borderlayout的中间
        frame.add(panel,BorderLayout.CENTER);
        //设置默认关闭窗口则关闭程序
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        //设置可见
        frame.setVisible(true);
    }
}
