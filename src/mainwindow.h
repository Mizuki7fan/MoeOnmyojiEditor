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
    //�Ϸ�������ť
    QPushButton* btnBasicInfo;//������Ϣ
    QPushButton* btnSkill;//����
    QPushButton* btnVoice;//����
    QPushButton* btnStory;//����
    QPushButton* btnExport;//����
    QPushButton* btnImport;//����
    QPushButton* btnDownload;//����
    QPushButton* btnUpload;//�ϴ�
    QPushButton* btnImageScale;//ͼƬ����
    QPushButton* btnAbout;
    QLabel* lHint;
    //��������QStackedWidget ҳ�棬ÿ��ҳ�����һ����ť����Ȼ������İ�ťֻ�ǿ�������
    
    QStackedWidget* m_pStackedWidget;

    BasicInfoForm* basic_info_form;
    SkillForm* skill_form;
    VoiceForm* voice_form;
    StoryForm* story_form;

    DataForm* data_form;

};