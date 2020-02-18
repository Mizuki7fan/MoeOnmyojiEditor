#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_MOE.h"

class MOE : public QMainWindow
{
	Q_OBJECT

public:
	MOE(QWidget *parent = Q_NULLPTR);

private:
	Ui::MOEClass ui;
};
