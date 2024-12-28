/**
 * Created with IntelliJ IDEA.
 * Description:
 * User: Surface
 * Date: 2024-06-11
 * Time: 15:34
 */
import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

class Rectangle {
    private double length;
    private double width;

    public Rectangle(double length, double width) {
        this.length = length;
        this.width = width;
    }

    public double getArea() {
        return length * width;
    }

    public double getPerimeter() {
        return 2 * (length + width);
    }
}
public class JTest5b {
    public static void main(String[] args) {
        // 创建 JFrame 实例
        JFrame frame = new JFrame("First GUI Program");
        frame.setSize(500, 300);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.getContentPane().setBackground(Color.RED);
        frame.setLocationRelativeTo(null); // 居中显示


        // 使用 BorderLayout 布局管理器
        frame.setLayout(new BorderLayout());

        // 创建 Panel 用于放置控件
        JPanel panel = new JPanel();
        panel.setLayout(new FlowLayout(FlowLayout.LEFT,10,30));

        // 创建控件
        JTextField lengthField = new JTextField(10);
        JTextField widthField = new JTextField(10);
        JButton areaButton = new JButton("面积");
        JButton perimeterButton = new JButton("周长");
        JLabel resultLabel = new JLabel("结果");

        // 长方形对象
        Rectangle rectangle = new Rectangle(0, 0);

        // 为按钮添加事件监听器
        areaButton.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                double length = Double.parseDouble(lengthField.getText());
                double width = Double.parseDouble(widthField.getText());
                resultLabel.setText("面积: " + (length * width));
            }
        });

        perimeterButton.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                double length = Double.parseDouble(lengthField.getText());
                double width = Double.parseDouble(widthField.getText());
                resultLabel.setText("周长: " + (2 * (length + width)));
            }
        });

        // 将控件添加到 Panel
        panel.add(new JLabel("长:"));
        panel.add(lengthField);
        panel.add(new JLabel("宽:"));
        panel.add(widthField);
        panel.add(areaButton);
        panel.add(perimeterButton);
        panel.add(resultLabel);

        // 将 Panel 添加到 JFrame
        frame.add(panel, BorderLayout.CENTER);

        // 显示窗口
        frame.setVisible(true);
    }
}
