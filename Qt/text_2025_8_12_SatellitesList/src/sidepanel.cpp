#include "sidepanel.h"
#include "ui_SidePanel.h"  // 匹配UI生成的头文件
#include <QMenu>
#include <QAction>
#include <QDebug>
#include <QMessageBox>

// 在SidePanel构造函数中添加调用
SidePanel::SidePanel(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::SidePanel)
{
    ui->setupUi(this);
    initStyle();
    initContextMenu();
    initTreeWidget();  // 新增：初始化树形列表数据

    setWindowTitle("卫星监控面板");
}

SidePanel::~SidePanel()
{
    delete ui;
}

// 补充样式调整（可选，UI中已通过styleSheet定义大部分样式）
void SidePanel::initStyle()
{
    // 示例：强制设置树形列表展开所有节点
    ui->treeWidget->expandAll();

    // 设置按钮图标（使用资源文件中的图片）
    // 场景按钮：关联scene相关图片
    ui->btn_scene->setIcon(QIcon(":/images/scene"));
    // 可根据需要设置图标大小
    ui->btn_scene->setIconSize(QSize(24, 24));

    // 红方按钮：可使用role相关图片（角色/方别关联）
    ui->btn_red->setIcon(QIcon(":/images/role"));
    ui->btn_red->setIconSize(QSize(24, 24));

    // 蓝方按钮：使用role_2作为区分
    ui->btn_blue->setIcon(QIcon(":/images/role_2"));
    ui->btn_blue->setIconSize(QSize(24, 24));

    // 需求按钮：直接关联demand图片
    ui->btn_demand->setIcon(QIcon(":/images/demand"));
    ui->btn_demand->setIconSize(QSize(24, 24));

    // 标绘按钮：关联plot（绘图）相关图片
    ui->btn_mark->setIcon(QIcon(":/images/plot"));
    ui->btn_mark->setIconSize(QSize(24, 24));

    // 用户按钮：关联personnel（人员）图片
    ui->btn_user->setIcon(QIcon(":/images/personnel"));
    ui->btn_user->setIconSize(QSize(24, 24));

    // 恢复/收起按钮：使用retract（收起）图片
    ui->pushButton->setIcon(QIcon(":/images/retract"));
    ui->pushButton->setIconSize(QSize(24, 24));
}

// 初始化右键菜单（针对树形列表）
void SidePanel::initContextMenu()
{
    // 启用树形列表的右键菜单功能
    ui->treeWidget->setContextMenuPolicy(Qt::CustomContextMenu);
}

// 场景按钮点击
void SidePanel::on_btn_scene_clicked()
{
    qDebug() << "场景按钮被点击";
    // 切换图标示例
    static bool isActive = false;
    if (isActive) {
        ui->btn_scene->setIcon(QIcon(":/images/scene"));
    } else {
        ui->btn_scene->setIcon(QIcon(":/images/scene_2"));
    }
    isActive = !isActive;
}

// 红方按钮点击
void SidePanel::on_btn_red_clicked()
{
    qDebug() << "红方按钮被点击";
    // 示例：切换到红方视图
    ui->treeWidget->setStyleSheet("QTreeWidget { border: 1px solid #FF5733; }"); // 红方主题色
}

// 蓝方按钮点击
void SidePanel::on_btn_blue_clicked()
{
    qDebug() << "蓝方按钮被点击";
    // 示例：切换到蓝方视图
    ui->treeWidget->setStyleSheet("QTreeWidget { border: 1px solid #337AB7; }"); // 蓝方主题色
}

// 需求按钮点击（修正原UI中重复的btn_track，需在UI中将第二个btn_track改名为btn_demand）
void SidePanel::on_btn_demand_clicked()
{
    qDebug() << "需求按钮被点击";
    // 示例：显示需求列表
}

// 标绘按钮点击（修正原UI中重复的btn_track，需在UI中将第一个btn_track改名为btn_mark）
void SidePanel::on_btn_mark_clicked()
{
    qDebug() << "标绘按钮被点击";
    // 示例：激活标绘功能
}

// 用户按钮点击
void SidePanel::on_btn_user_clicked()
{
    qDebug() << "用户按钮被点击";
    // 示例：显示用户列表
}

// 顶部恢复按钮点击（右侧按钮）
void SidePanel::on_pushButton_clicked()
{
    qDebug() << "恢复按钮被点击";
    // 示例：恢复默认样式
    ui->treeWidget->setStyleSheet(""); // 清空自定义样式，恢复UI中定义的默认样式
    ui->treeWidget->collapseAll();    // 折叠所有节点
    ui->treeWidget->expandToDepth(0); // 只展开第一级节点
}

// 树形列表节点点击
// 在sidepanel.cpp中修改on_treeWidget_itemClicked函数
// 修改sidepanel.cpp中的on_treeWidget_itemClicked函数
void SidePanel::on_treeWidget_itemClicked(QTreeWidgetItem *item, int column)
{
    if (!item) return;
    qDebug() << "点击树形节点：" << item->text(column);

    // 判断节点层级（三级节点：父节点存在且父节点是二级节点）
    if (item->parent() != nullptr && item->parent()->parent() != nullptr 
        && item->parent()->parent()->parent() == nullptr) {
        // 三级节点：显示弹窗
        QMessageBox::information(this, "三级节点选中", 
            QString("您点击了三级节点：%1 > %2 > %3")
            .arg(item->parent()->parent()->text(column))  // 一级节点
            .arg(item->parent()->text(column))            // 二级节点
            .arg(item->text(column)));                    // 三级节点
    } else if (item->parent() == nullptr) {
        // 一级节点（如"通信卫星"）
        ui->textEdit->setText(QString("当前选中：%1").arg(item->text(column)));
    } else {
        // 二级节点（保持原有文本显示）
        ui->textEdit->setText(QString("当前选中：%1 > %2").arg(item->parent()->text(column)).arg(item->text(column)));
    }
}

// 树形列表右键菜单
void SidePanel::on_treeWidget_customContextMenuRequested(const QPoint &pos)
{
    QTreeWidgetItem *currentItem = ui->treeWidget->itemAt(pos);
    if (!currentItem) return; // 未选中节点时不显示菜单

    // 创建右键菜单（匹配UI中QMenu的样式）
    QMenu menu(this);
    menu.addAction("指向");
    menu.addAction("属性");
    menu.addAction("通信设置");
    menu.addAction("导航设置");
    menu.addAction("关联站点");
    menu.addSeparator(); // 分隔线
    menu.addAction("删除");
    menu.addAction("添加星座");

    // 显示菜单并处理选择
    QAction *selectedAction = menu.exec(ui->treeWidget->mapToGlobal(pos));
    if (selectedAction) {
        qDebug() << "右键菜单选择：" << selectedAction->text() 
                 << "，目标节点：" << currentItem->text(0);
        // 示例：根据选择执行对应操作
        if (selectedAction->text() == "属性") {
            QMessageBox::information(this, "属性", QString("%1 的属性信息").arg(currentItem->text(0)));
        }
    }
}

// initTreeWidget()实现
void SidePanel::initTreeWidget()
{
    // 清空现有节点（避免重复添加）
    ui->treeWidget->clear();

    // 一级节点：通信卫星（假设这是已存在的根节点）
    QTreeWidgetItem *rootItem = new QTreeWidgetItem(QStringList() << "通信卫星");
    ui->treeWidget->addTopLevelItem(rootItem);

    // 为每个一级节点（中星系列、北斗系列等）添加二级目录
    // 1. 中星-9 二级目录
    QTreeWidgetItem *zhongxing9 = new QTreeWidgetItem(QStringList() << "中星-9");
    rootItem->addChild(zhongxing9);
    zhongxing9->addChild(new QTreeWidgetItem(QStringList() << "中星-9A"));
    zhongxing9->addChild(new QTreeWidgetItem(QStringList() << "中星-9B"));

    // 2. 中星-6B 二级目录
    QTreeWidgetItem *zhongxing6B = new QTreeWidgetItem(QStringList() << "中星-6B");
    rootItem->addChild(zhongxing6B);
    zhongxing6B->addChild(new QTreeWidgetItem(QStringList() << "转发器A"));
    zhongxing6B->addChild(new QTreeWidgetItem(QStringList() << "转发器B"));

    // 3. 北斗-3 二级目录
    QTreeWidgetItem *beidou3 = new QTreeWidgetItem(QStringList() << "北斗-3");
    rootItem->addChild(beidou3);
    beidou3->addChild(new QTreeWidgetItem(QStringList() << "卫星M1"));
    beidou3->addChild(new QTreeWidgetItem(QStringList() << "卫星M2"));
    beidou3->addChild(new QTreeWidgetItem(QStringList() << "卫星M3"));

    // 4. 其他一级节点添加二级目录（示例）
    QTreeWidgetItem *fengyun4 = new QTreeWidgetItem(QStringList() << "风云-4");
    rootItem->addChild(fengyun4);
    fengyun4->addChild(new QTreeWidgetItem(QStringList() << "气象载荷A"));
    fengyun4->addChild(new QTreeWidgetItem(QStringList() << "气象载荷B"));

    // 展开所有节点（可选）
    ui->treeWidget->expandAll();
}