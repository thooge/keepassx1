/***************************************************************************
 *   Copyright (C) 2005-2006 by Tarek Saidi                                *
 *   tarek.saidi@arcor.de                                                  *
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
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
 ***************************************************************************/ 

#ifndef _AUTOTYPE_H_
#define _AUTOTYPE_H_

#include <QObject>
#include <QWidget>
#include <QString>
#ifdef Q_WS_X11
	#define XK_MISCELLANY
	#define XK_XKB_KEYS
	#include <X11/extensions/XTest.h>
	#include <X11/keysymdef.h>
	#include <X11/Xlib.h>
#endif
#include "Database.h"

typedef struct tKeysymMap{
	Q_UINT16 keysym;
  	Q_UINT16 unicode;
};

class AutoType:public QObject{
public:
 static QWidget* MainWin;
 static void perform(CEntry* entry,QString& errors);
private:
 static tKeysymMap KeysymMap[];
 static Q_UINT16 getKeysym(const QChar& unicode);
 static int getModifiers(Display*,KeySym,int);
 static void pressModifiers(Display*,int,bool Press=true);
 static void releaseModifiers(Display*,int);
 static void templateToKeysyms(const QString& Template, QList<quint16>& KeySymList,CEntry* entry);
 static void stringToKeysyms(const QString& string,QList<quint16>& KeySymList);
 



};


#endif