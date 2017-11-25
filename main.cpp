/***************************************************************************
 *   Copyright (C) 2011 by Glad Deschrijver                                *
 *     <glad.deschrijver@gmail.com>                                        *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, see <http://www.gnu.org/licenses/>.  *
 ***************************************************************************/
#include <QGuiApplication>
#include <QtQuick>
#include <QQmlContext>
#include <QDebug>
#include "orientation.h"
#include "game.h"

int main(int argc, char *argv[])
{
    QGuiApplication app( argc, argv );

    Game game; //Instanciando a classe Game

    // Expondo as classes para o QML
    qmlRegisterType<Orientation>( "GameComponents", 1, 0, "Orientation" );
    qmlRegisterType<Game>( "GameComponents", 1, 0, "Game" );


    //Preparando o QQuickView
    QQuickView view;
    view.engine()->rootContext()->setContextProperty("msg", &msg);
    view.setSource( QUrl( "qrc:///main.qml" ) );

    //Instanciando o QML como um objeto
    Game::setViewer(view.rootObject());

    //Iniciando o viewer
    viewer.show();

    return app.exec();
}
