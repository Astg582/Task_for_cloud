#include "menu_bar.h"
#include <QMenu>
#include <QMenuBar>

Menu_bar::Menu_bar(QWidget *parent)
    : QMainWindow(parent) {

  QAction *quit = new QAction("&Quit", this);
  quit->setShortcut(tr("CTRL+Q"));


  QMenu *Server_transfers;
  QMenu *Managment;
  QMenu *Firewall_templates;
  QMenu *Notifications;

  Server_transfers = menuBar()->addMenu("Server transfers");
  Server_transfers->addMenu("Server");
  Server_transfers->addMenu("Storage Box");
  Server_transfers->addMenu("History");
  Server_transfers->addMenu("Traffic statistics");
  Server_transfers->addSeparator();
  Server_transfers->addAction(quit);



  Managment = menuBar()->addMenu("Managment");
  Firewall_templates = menuBar()->addMenu("Firewall templates");
  Notifications = menuBar()->addMenu("Notifications");

  qApp->setAttribute(Qt::AA_DontShowIconsInMenus, false);

  connect(quit, &QAction::triggered, qApp, &QApplication::quit);
}
