#include "dialog.h"
#include "ui_dialog.h"
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// \brief main
/// \param argc
/// \param argv
/// \return 
///
#include <fstream>
#include <iostream>
using namespace std;
#include <QProcess>
#include <QFile>
#include <QTextStream>
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include <QDir>
#include <QDebug>
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// \brief Dialog::Dialog
/// \param parent
///
Dialog::Dialog(QWidget *parent)
     : QDialog(parent)
     , ui(new Ui::Dialog)
     {
          ui->setupUi(this);

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// .
QProcess process2;
// получает список имён файлов
QString  stroka_obnovity_spisok=
"cd /mnt/97d838cf-b3a1-4c1d-9c9d-cf745cf3116a/загрузки/imageye2/vihod/black-white/ && ls > /home/viktor/my_projects_qt_2/ubraty_odinakovye_fayly_s_pamiatyiu/spisok.txt";          
             process2.start(stroka_obnovity_spisok.toStdString().c_str());
    process2.waitForFinished(-1); // will wait forever until finished
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////// загрузка имён файлов из файла в вектор ////////////////////////////////////////////////////////////////////////////////////////// 
   std::ifstream is2("/home/viktor/my_projects_qt_2/ubraty_odinakovye_fayly_s_pamiatyiu/spisok.txt");  
     std::istream_iterator<std::string> start2(is2), end2;  
     std::vector<std::string> list_of_fonts(start2, end2);
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// 
   QString stroka1=
   "magick compare -metric MAE \"/mnt/97d838cf-b3a1-4c1d-9c9d-cf745cf3116a/загрузки/imageye2/vihod/black-white/";
//list_of_fonts[0]; 
QString stroka2="\" \"/mnt/97d838cf-b3a1-4c1d-9c9d-cf745cf3116a/загрузки/imageye2/vihod/black-white/";
//list_of_fonts[1] ;
QString stroka3="\" null: 2>&1"; 
bool file_stiort=false;
QProcess process;
QString  stroka_vsia;
int y=0;
int x=y+1;
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// 
/// 
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// 
// TODO: прочитать x и y из файла
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Если файла /home/viktor/my_projects_qt_2/ubraty_odinakovye_fayly_s_pamiatyiu/x.txt нет создать его и записать в него 0 в qt c++ Linux
/// 
   QString filePath = "/home/viktor/my_projects_qt_2/ubraty_odinakovye_fayly_s_pamiatyiu/x.txt";
    
    // Создаем директорию, если она не существует
    QFileInfo fileInfo(filePath);
    QDir dir(fileInfo.path());
    if (!dir.exists()) {
        dir.mkpath(fileInfo.path());
    }
    
    // Создаем и открываем файл
    QFile file(filePath);
    if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QTextStream out(&file);
        out << "1"; // Записываем значение 0 в файл
        file.close();
    } else {
        qDebug() << "Не удалось создать файл:" << file.errorString();
    }
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// 
/// 
// читает x на котором остановился
QFile inputFile("/home/viktor/my_projects_qt_2/ubraty_odinakovye_fayly_s_pamiatyiu/x.txt");
if (inputFile.open(QIODevice::ReadOnly))
{
   QTextStream in(&inputFile);
  // while (!in.atEnd())
   {
      QString line = in.readLine();
  x=  line.toInt();
   }
   inputFile.close();
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Если файла /home/viktor/my_projects_qt_2/ubraty_odinakovye_fayly_s_pamiatyiu/y.txt нет создать его и записать в него 0 в qt c++ Linux
/// 
   QString filePath2 = "/home/viktor/my_projects_qt_2/ubraty_odinakovye_fayly_s_pamiatyiu/y.txt";
    
    // Создаем директорию, если она не существует
    QFileInfo fileInfo2(filePath2);
    QDir dir2(fileInfo2.path());
    if (!dir2.exists()) {
        dir2.mkpath(fileInfo2.path());
    }
    
    // Создаем и открываем файл
    QFile file2(filePath2);
    if (file2.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QTextStream out(&file2);
        out << "0"; // Записываем значение 0 в файл
        file2.close();
    } else {
        qDebug() << "Не удалось создать файл:" << file2.errorString();
    }
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// 
// читает y на котором остановился
QFile inputFile2("/home/viktor/my_projects_qt_2/ubraty_odinakovye_fayly_s_pamiatyiu/y.txt");
if (inputFile2.open(QIODevice::ReadOnly))
{
   QTextStream in(&inputFile2);
  // while (!in.atEnd())
   {
      QString line2 = in.readLine();
 y=  line2.toInt();
   }
   inputFile.close();
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    for (;y<356 ; y++)  
    {
     for ( ;x<355 ; x++)  
        {
               stroka_vsia=stroka1+list_of_fonts[y].c_str()+stroka2+list_of_fonts[x].c_str()  +stroka3;
             
             
             process.start(stroka_vsia.toStdString().c_str());
    process.waitForFinished(-1); // will wait forever until finished
             QString stderr = process.readAllStandardError();
        

 std::cout << stderr.toStdString().c_str()  << std::endl; 

 if (stderr=="0 (0)")   
             {
// std::cout << "!!!!!!"<< std::endl ; // TODO: стереть файл второй
QString name_of_file="/mnt/97d838cf-b3a1-4c1d-9c9d-cf745cf3116a/загрузки/imageye2/vihod/black-white/"
+QString::fromStdString(list_of_fonts[x]); // QString::fromStdString(str);
 file_stiort=QFile::remove(name_of_file);
            if (file_stiort ==true)
            std::cout << "файл "+list_of_fonts[x]+" стёрт"<< std::endl ; // TODO: стереть файл второй;
            else 
            std::cout << "файл "+list_of_fonts[x]+" не стёрт"<< std::endl ;
            
             }
             // тут внутренний цикл значит меняется x
              QFile file("/home/viktor/my_projects_qt_2/ubraty_odinakovye_fayly_s_pamiatyiu/x.txt");
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {;;}
        QTextStream out(&file);
    out << x;
     file.close(); 
          }
          // тут внешний цикл значит меняется y
           QFile file2("/home/viktor/my_projects_qt_2/ubraty_odinakovye_fayly_s_pamiatyiu/y.txt");
    if (!file2.open(QIODevice::WriteOnly | QIODevice::Text)) {;;}
         QTextStream out2(&file2);
    out2 << y;
     file2.close(); 
     }
 
     }

Dialog::~Dialog()
     {
          delete ui;
     }

