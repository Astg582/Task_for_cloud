#include "menu_bar.h"
#include <QMenu>
#include <QMenuBar>
#include <QTimer>
#include <QFont>

Menu_bar::Menu_bar(QWidget *parent)
    : QMainWindow(parent) {

  QAction *quit = new QAction("&Quit", this);
  quit->setShortcut(tr("CTRL+Q"));

  QMenu *Server_transfers;
  QMenu *Managment;
  QMenu *Firewall_templates;
  QMenu *Notifications;

  Server_transfers = menuBar()->addMenu("Server transfers");
  Server_transfers->addMenu("Server")->addAction(" ");
  Server_transfers->addMenu("Storage Box")->addAction(" ");
  Server_transfers->addMenu("History")->addAction(" ");
  Server_transfers->addMenu("Traffic statistics")->addAction(" ");
  Server_transfers->addSeparator();
  Server_transfers->addAction(quit);

  Managment = menuBar()->addMenu("Managment");
  Managment->addAction(" ");
  Firewall_templates = menuBar()->addMenu("Firewall templates");
  Firewall_templates->addAction(" ");
  Notifications = menuBar()->addMenu("Notifications");
  Notifications->addAction(" ");

  QString baseStyle = "QMenu { background-color: #32374F; color: white; }";
    QString hoverStyle = "QMenu::item:selected, QMenu::item:pressed { background-color: #786A6A; }";
    Server_transfers->setStyleSheet(baseStyle + hoverStyle);
    Managment->setStyleSheet(baseStyle + hoverStyle);
    Firewall_templates->setStyleSheet(baseStyle + hoverStyle);
    Notifications->setStyleSheet(baseStyle + hoverStyle);



  qApp->setAttribute(Qt::AA_DontShowIconsInMenus, false);

  connect(quit, &QAction::triggered, qApp, &QApplication::quit);
}
