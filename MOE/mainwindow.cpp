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
    //������
    pwind = new QWidget;
    setCentralWidget(pwind);

    btnBasicInfo = new QPushButton(QStringLiteral("������Ϣ"));
    btnSkill = new QPushButton(QStringLiteral("����"));
    btnVoice = new QPushButton(QStringLiteral("����"));
    btnStory = new QPushButton(QStringLiteral("����"));
    btnImport = new QPushButton(QStringLiteral("����"));
    btnExport = new QPushButton(QStringLiteral("����"));
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
    //addWidget(�����QWidget����������������Խ��������Խ����);����Ĳ�������ȱʡ
    pLayout->addWidget(btnImport, 3, 4);
    pLayout->addWidget(btnExport, 3, 6);
    pLayout->addWidget(btnAbout, 3, 0);

    pwind->setLayout(pLayout);
    //ͨ�����������л�StackedWidget
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
    //��ȡʽ���������Ϣ
    data_form = new DataForm();
    data_form->basic_info = basic_info_form->getData();
    data_form->skill_info = skill_form->getData();
    data_form->voice_info = voice_form -> getData();
    data_form->story_info = story_form->getData();

    QString fileName = QFileDialog::getSaveFileName(this,
        QStringLiteral("����"),
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
        QStringLiteral("����"),
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
        "<div>"+QStringLiteral("����ٿ�����ʦʽ�����ϱ༭�� by ��������")+"</div>"
        "<div>"+QStringLiteral("��ӭ��Ⱥ 916027306����")+"</div>");
}

