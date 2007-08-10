######################################################################
# Automatically generated by qmake (2.01a) Mo Jan 29 18:17:19 2007
######################################################################

DEPENDPATH += "crypto \
              dialogs \
              export \
              forms \
              import \
              lib \
              translations \
	      res"
INSTALLS += target data
data.files += ../share/keepass/*
TARGET = ../bin/keepassx

unix: !macx{
        target.path = $${PREFIX}/bin
        data.path = $${PREFIX}/share/keepass
        LIBS += -lXtst -lQtDBus
        SOURCES += lib/AutoType_X11.cpp
    }

macx{
    target.path = /Applications
    data.path = /Applications/keepass.app/Contents/share/keepass
    SOURCES += lib/AutoType_X11.cpp
}

win32{
    SOURCES += lib/AutoType_Win.cpp
    TARGET = ../$$TARGET
    QMAKE_LINK_OBJECT_SCRIPT = ../build/$$QMAKE_LINK_OBJECT_SCRIPT

}

FORMS += forms/EditGroupDlg.ui \
         forms/SearchDlg.ui \
         forms/AboutDlg.ui \
         forms/SettingsDlg.ui \
         forms/MainWindow.ui \
         forms/SimplePasswordDlg.ui \
         forms/DatabaseSettingsDlg.ui \
         forms/PasswordDlg.ui \
         forms/EditEntryDlg.ui \
         forms/PasswordGenDlg.ui \
	 forms/SelectIconDlg.ui \
	 forms/CollectEntropyDlg.ui \
	 forms/CustomizeDetailViewDlg.ui \
	 forms/CalendarDlg.ui \
	 forms/TrashCanDlg.ui \
	 forms/ExpiredEntriesDlg.ui \
	 forms/WorkspaceLockedWidget.ui
TRANSLATIONS += translations/keepass-de_DE.ts \
		translations/keepass-ru_RU.ts \
		translations/keepass-es_ES.ts \
		translations/keepass-fr_FR.ts \
		translations/keepass-cs_CS.ts \
                translations/keepass-xx_XX.ts
HEADERS += lib/IniReader.h \
           lib/UrlLabel.h \
           mainwindow.h \
           Kdb3Database.h \
           lib/SecString.h \
           crypto/twoclass.h \
           crypto/twofish.h \
	   import/Import.h \
	   import/Import_KeePassX_Xml.h \
           import/Import_PwManager.h \
           export/Export_Txt.h \
	   export/Export_KeePassX_Xml.h \
	   export/Export.h \
           import/Import_KWalletXml.h \
           dialogs/AboutDlg.h \
           dialogs/EditGroupDlg.h \
           dialogs/SearchDlg.h \
           dialogs/SettingsDlg.h \
           dialogs/DatabaseSettingsDlg.h \
           dialogs/PasswordDlg.h \
           dialogs/SimplePasswordDlg.h \
           dialogs/EditEntryDlg.h \
           dialogs/PasswordGenDlg.h \
	   dialogs/SelectIconDlg.h \
	   dialogs/CollectEntropyDlg.h \
	   dialogs/CustomizeDetailViewDlg.h \
	   dialogs/CalendarDlg.h \
	   dialogs/ExpiredEntriesDlg.h \
	   dialogs/TrashCanDlg.h \
           lib/random.h \
           Database.h \
           lib/KdePlugin.h \
	   lib/AutoType.h \
	   lib/FileDialogs.h \
           global.h \
           main.h \
           lib/GroupView.h \
           lib/EntryView.h \
           crypto/arcfour.h \
           lib/KpFileIconProvider.h \
	   crypto/aes_edefs.h \
	   crypto/aes_tdefs.h \
	   crypto/aes.h \
	   crypto/aesopt.h \
	   crypto/aestab.h \
	   crypto/aescpp.h \
	   crypto/sha256.h \
	   crypto/yarrow.h \
	   crypto/blowfish.h \
	   crypto/sha1.h \
	   lib/WaitAnimationWidget.h \
	   plugins/interfaces/IFileDialog.h \
	   plugins/interfaces/IKdeInit.h \
	   plugins/interfaces/IGnomeInit.h \
	   plugins/interfaces/IIconTheme.h \
	   KpxConfig.h \
           KpxFirefox.h
SOURCES += lib/UrlLabel.cpp \
           main.cpp \
           mainwindow.cpp \
           Kdb3Database.cpp \
           lib/SecString.cpp \
           crypto/twoclass.cpp \
           crypto/twofish.cpp \
	   crypto/blowfish.cpp \
	   crypto/sha1.cpp \
	   import/Import.cpp \
           import/Import_PwManager.cpp \
	   import/Import_KeePassX_Xml.cpp \
           export/Export_Txt.cpp \
	   export/Export_KeePassX_Xml.cpp \
	   export/Export.cpp \
           import/Import_KWalletXml.cpp \
           dialogs/AboutDlg.cpp \
           dialogs/EditGroupDlg.cpp \
           dialogs/SearchDlg.cpp \
           dialogs/SettingsDlg.cpp \
           dialogs/DatabaseSettingsDlg.cpp \
           dialogs/PasswordDlg.cpp \
           dialogs/SimplePasswordDlg.cpp \
           dialogs/EditEntryDlg.cpp \
           dialogs/PasswordGenDlg.cpp \
	   dialogs/SelectIconDlg.cpp \
	   dialogs/CollectEntropyDlg.cpp \
	   dialogs/CustomizeDetailViewDlg.cpp \
	   dialogs/CalendarDlg.cpp \
	   dialogs/ExpiredEntriesDlg.cpp \
	   dialogs/TrashCanDlg.cpp \
           lib/random.cpp \
           Database.cpp \
           lib/KdePlugin.cpp \
           lib/GroupView.cpp \
           lib/EntryView.cpp \
	   lib/FileDialogs.cpp \
           crypto/arcfour.cpp \
           lib/KpFileIconProvider.cpp \
	   crypto/aescrypt.c \
	   crypto/aeskey.c \
	   crypto/aestab.c \
	   crypto/aes_modes.c \
	   crypto/sha256.cpp \
	   crypto/yarrow.cpp \
	   lib/WaitAnimationWidget.cpp \
	   KpxConfig.cpp \
           KpxFirefox.cpp
RESOURCES += res/resources.qrc
MOC_DIR = ../build/moc
UI_DIR = ../build/ui
OBJECTS_DIR = ../build/
RCC_DIR = ../build/rcc
CONFIG += debug \
qt \
thread \
warn_off \
dbus \
assistant
QT += dbus xml
TEMPLATE = app
INCLUDEPATH += . \
lib \
crypto \
plugins/interfaces \
export \
import \
dialogs \
./
