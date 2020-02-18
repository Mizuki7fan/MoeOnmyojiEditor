#include "mainwindow.h"
#include "BasicInfoForm.h"
#include "SkillForm.h"
#include "VoiceForm.h"
#include "StoryForm.h"
#include <QLabel>
#include "DataForm.h"

#include <iostream>

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent)
{
    setWindowTitle(tr("Moe Onmyoji Editor"));
    //主窗体
    pwind = new QWidget;
    setCentralWidget(pwind);

    btnBasicInfo = new QPushButton(QStringLiteral("基本信息"));
    btnSkill = new QPushButton(QStringLiteral("技能"));
    btnVoice = new QPushButton(QStringLiteral("语音"));
    btnStory = new QPushButton(QStringLiteral("传记"));
    btnImport = new QPushButton(QStringLiteral("导入"));
    btnExport = new QPushButton(QStringLiteral("导出"));
    btnAbout = new QPushButton("About");
    QLabel* blank = new QLabel("   ", this);

    m_pStackedWidget = new QStackedWidget();

    basic_info_form = new BasicInfoForm();
    skill_form = new SkillForm();
    voice_form = new VoiceForm();
    story_form = new StoryForm();

    m_pStackedWidget->addWidget(basic_info_form);
    m_pStackedWidget->addWidget(skill_form);
    m_pStackedWidget->addWidget(voice_form);
    m_pStackedWidget->addWidget(story_form);

    QGridLayout* pLayout = new QGridLayout();
    pLayout->addWidget(btnBasicInfo, 0, 0);
    pLayout->addWidget(blank, 0, 1);
    pLayout->addWidget(btnSkill, 0, 2);
    pLayout->addWidget(blank, 0, 3);
    pLayout->addWidget(btnVoice, 0, 4);
    pLayout->addWidget(blank, 0, 5);
    pLayout->addWidget(btnStory, 0, 6);
    pLayout->addWidget(m_pStackedWidget, 1, 0, 2, 7);
    //addWidget(待添加QWidget，行数，列数，跨越行数，跨越列数);后面的参数可以缺省
    pLayout->addWidget(btnImport, 3, 4);
    pLayout->addWidget(btnExport, 3, 6);
    pLayout->addWidget(btnAbout, 3, 0);

    pwind->setLayout(pLayout);
    //通过匿名函数切换StackedWidget
    connect(btnBasicInfo, &QPushButton::clicked, this, [=]() {m_pStackedWidget->setCurrentIndex(0); });
    connect(btnSkill, &QPushButton::clicked, this, [=]() {m_pStackedWidget->setCurrentIndex(1); });
    connect(btnVoice, &QPushButton::clicked, this, [=]() {m_pStackedWidget->setCurrentIndex(2); });
    connect(btnStory, &QPushButton::clicked, this, [=]() {m_pStackedWidget->setCurrentIndex(3); });
    connect(btnExport, SIGNAL(clicked()), SLOT(Export()));
    connect(btnImport, SIGNAL(clicked()), SLOT(Import()));
    connect(btnAbout, SIGNAL(clicked()), SLOT(About()));
}

MainWindow::~MainWindow()
{
}

void MainWindow::Export(void)
{
    //读取式神的四项信息
    data_form = new DataForm();
    data_form->basic_info = basic_info_form->getData();
    data_form->skill_info = skill_form->getData();
    data_form->voice_info = voice_form -> getData();
    data_form->story_info = story_form->getData();

    QString fileName = QFileDialog::getSaveFileName(this,
        QStringLiteral("保存"),
        "",
        tr("TXT Files (*.txt);;"
            "All Files (*)"));
    if (!fileName.isEmpty())
    {
        Parser p(data_form);
        p.output(fileName);
    }
}

void MainWindow::Import(void)
{
    DataForm* data;
    QString fileName = QFileDialog::getOpenFileName(this,
        QStringLiteral("导入"),
        "",
        tr("TXT Files (*.txt);;"
            "All Files (*)"));
    if (!fileName.isEmpty())
    {
        Parser p(fileName);
        data = p.input();
    }
    basic_info_form->fill(data->basic_info);
    skill_form->fill(data->skill_info);
    voice_form->fill(data->voice_info);
    story_form->fill(data->story_info);


}

void MainWindow::About()
{
    QMessageBox::about(this, QString("About ") + this->windowTitle(),
        QString("<div><center><h1>") + this->windowTitle() + " v0.1</h1>" +
        "<div>"+QStringLiteral("萌娘百科阴阳师式神资料编辑器 by 葛生明玉")+"</div>"
        "<div>"+QStringLiteral("欢迎加群 916027306讨论")+"</div>");
}

