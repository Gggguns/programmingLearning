#ifndef SIDEPANEL_H
#define SIDEPANEL_H

#include <QWidget>
#include <QTreeWidgetItem>

QT_BEGIN_NAMESPACE
namespace Ui { class SidePanel; }  // 匹配UI类名
QT_END_NAMESPACE

class SidePanel : public QWidget  // 继承QWidget（因UI是QWidget）
{
    Q_OBJECT

public:
    SidePanel(QWidget *parent = nullptr);
    ~SidePanel();

private slots:
    // 左侧导航按钮点击事件
    void on_btn_scene_clicked();    // 场景按钮
    void on_btn_red_clicked();      // 红方按钮
    void on_btn_blue_clicked();     // 蓝方按钮
    void on_btn_demand_clicked();   // 需求按钮（修正原UI中重复的btn_track）
    void on_btn_mark_clicked();     // 标绘按钮（修正原UI中重复的btn_track）
    void on_btn_user_clicked();     // 用户按钮

    // 顶部恢复按钮点击事件
    void on_pushButton_clicked();   // 恢复/收起按钮

    // 树形列表交互事件
    void on_treeWidget_itemClicked(QTreeWidgetItem *item, int column);  // 节点点击
    void on_treeWidget_customContextMenuRequested(const QPoint &pos);   // 右键菜单

private:
    Ui::SidePanel *ui;

    // 初始化函数
    void initStyle();               // 补充样式（可选）
    void initTreeWidget();          // 初始化树形列表数据（如果需要动态加载）
    void initContextMenu();         // 初始化右键菜单
};
#endif // SIDEPANEL_H