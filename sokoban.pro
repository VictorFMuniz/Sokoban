TEMPLATE += app
TARGET = qmlsokoban

QT += quick sensors

# Source files
SOURCES += main.cpp orientation.cpp \
    game.cpp
HEADERS += orientation.h \
    game.h
RESOURCES += qmlsokoban.qrc

OTHER_FILES += main.qml \
        ToolBar.qml \
        BoardItem.qml \
        GameView.qml \
        ItemBorder0.qml \
        ItemBorder1.qml \
        ItemBorder2.qml \
        ItemBorder3.qml \
        ItemFloor.qml \
        ItemGoal.qml \
        ItemMan.qml \
        ItemObject.qml \
        game.js \
        AboutArea.qml \
        Button.qml \
        MenuPanel.qml \
        MenuTitle.qml
