#ifndef APPLICATION_H
#define APPLICATION_H


#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>


#include "qucrc_t.h"
#include "crc_calc_for_text.h"
#include "crc_calc_for_hex.h"





class Application : public QGuiApplication
{

    public:

        static Application& get_instance(int &argc, char **argv)
            {
                static Application singleton(argc, argv);
                return singleton;
            }


    private:

        Application(int &argc, char **argv);
        Q_DISABLE_COPY(Application)


        static void attach_console(void);


        QuCRC_t uCRC;

        CRC_Calc_for_Text calc_text;
        CRC_Calc_for_Hex  calc_hex;


        QQmlApplicationEngine engine;  //must be last field (must be destroyed first
                                       //(it's GUI) only next destroyed data)
};





#endif // APPLICATION_H
