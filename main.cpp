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
#include "gameview.h"
#include "gamecanvas.h"

int main(int argc, char *argv[])
{
    QGuiApplication app( argc, argv );

    GameView gameView;
    GameCanvas gameCanvas;

    // Expose the Orientation class
    qmlRegisterType<Orientation>( "GameComponents", 1, 0, "Orientation" );
    qmlRegisterType<GameCanvas>( "GameComponents", 1, 0, "Orientation" );
    qmlRegisterType<GameView>( "GameComponents", 1, 0, "Orientation" );

    QQuickView view;
    view.engine()->rootContext()->setContextProperty("gameView", &gameView);
    view.engine()->rootContext()->setContextProperty("gameCanvas", &gameCanvas);
    view.setSource( QUrl( "qrc:///gameView.qml" ) );

    GameView::setViewer(view.rootObject());
    GameCanvas::setViewer(view.rootObject());
    view.show();


    return app.exec();
}
