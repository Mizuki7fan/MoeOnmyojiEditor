#pragma once

#include <QMainWindow>
#include <QGridLayout>
#include <QWidget>
#include <QPushButton>
#include <QStackedWidget>
#include <QLabel>
#include "Parser.h"

class BasicInfoForm;
class SkillForm;
class VoiceForm;
class StoryForm;
class DataForm;


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget* parent = 0);
    ~MainWindow();

public slots:
    void About(void);
    void Export(void);
    void Import(void);
    void ImageScale(void);

private: 
    QWidget* pwind;
    //上方三个按钮
    QPushButton* btnBasicInfo;//基本信息
    QPushButton* btnSkill;//技能
    QPushButton* btnVoice;//语音
    QPushButton* btnStory;//传记
    QPushButton* btnExport;//导出
    QPushButton* btnImport;//导入
    QPushButton* btnDownload;//下载
    QPushButton* btnUpload;//上传
    QPushButton* btnImageScale;//图片缩放
    QPushButton* btnAbout;
    QLabel* lHint;
    //设置三个QStackedWidget 页面，每个页面包含一个按钮（当然这里面的按钮只是看看）；
    
    QStackedWidget* m_pStackedWidget;

    BasicInfoForm* basic_info_form;
    SkillForm* skill_form;
    VoiceForm* voice_form;
    StoryForm* story_form;

    DataForm* data_form;

};