#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    m_pListProvider = ContactListProvider::getInstance();

    ui->setupUi(this);

    auto list = m_pListProvider->getList();

    for(int i(0); i < list.size(); ++i)
    {
        QPushButton* pTmpButton = new QPushButton(list[i]->name + " " + list[i]->surname, this);
        pTmpButton->setVisible(true);
        pTmpButton->setGeometry(0, 0, 100, 125);
        pTmpButton->setMinimumSize(100, 125);
        pTmpButton->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);

        ui->verticalLayout->addWidget(pTmpButton, Qt::AlignmentFlag::AlignTop);
        //ContactsLayout->addWidget(pTmpButton, Qt::AlignmentFlag::AlignTop);
    }

    ui->verticalLayout->addSpacerItem(new QSpacerItem(0, 0, QSizePolicy::Expanding, QSizePolicy::Expanding));
    //ui->ContactsLayout->addSpacerItem(new QSpacerItem(10,10, QSizePolicy::Expanding, QSizePolicy::Expanding));
}

MainWindow::~MainWindow()
{
    delete ui;
}

