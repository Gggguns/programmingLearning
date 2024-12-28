/**
 * Created with IntelliJ IDEA.
 * Description:
 * User: Surface
 * Date: 2024-06-11
 * Time: 18:58
 */
import java.io.*;

public class JTest6b {
    public static void main(String[] args) {
        String filePath = "D:\\JTest6b\\test.java"; // 替换为实际的文件路径
        String outputFile = "D:\\JTest6b\\test2.java"; // 输出文件路径

        try (BufferedReader reader = new BufferedReader(new FileReader(filePath));
             BufferedWriter writer = new BufferedWriter(new FileWriter(outputFile))) {

            String line;
            int lineNumber = 1;
            while ((line = reader.readLine()) != null) {
                writer.write(lineNumber + " " + line);
                writer.newLine(); // 写入一个新行
                lineNumber++;
            }
            System.out.println("行号添加完成，文件已保存为：" + outputFile);

        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
