//#include <iostream>
#include <QTextStream>
#include <QFileInfo>
#include <QFile>

int main()
{
   QTextStream out(stdout);

   QString filename = "/home/astghik/Desktop/Task_for_cloud/task3/files/file.txt";
     QFile file(filename);

     if(file.open(QIODevice::WriteOnly)){
         QTextStream out(&file);

         out << "Joaquin Phoenix" << endl;
         out << "Cillian Murphy" << endl;
         out << "Anne Hathaway" << endl;
         out << "Zendaya" << endl;
         out << "Hyunjin | Stray Kids" << endl;

         file.close();
     } else {
         qWarning("Could not open file");
     }

     if (file.open(QIODevice::ReadOnly)){
         QTextStream in(&file);

         while(!in.atEnd()){
             QString line = in.readLine();
             out << line << endl;
         }

         file.close();
     } else {
         qWarning("could not open file for reading");
     }


   return 0;
}
