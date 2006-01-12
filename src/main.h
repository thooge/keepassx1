/***************************************************************************
 *   Copyright (C) 2005 by Tarek Saidi                                     *
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
#ifndef _MAIN_H_
#define _MAIN_H_

#include <QLabel>
#include <QPixmap>
#include <QString>
#include <QColor>
#include <QIcon>
#include "PwmConfig.h"

#define KEEPASS_VERSION "0.2.0"
#define NUM_CLIENT_ICONS 52

void createBanner(QLabel *Banner,QPixmap* symbol,QString text);
void createBanner(QLabel *Banner,QPixmap* symbol,QString text,QColor color1,QColor color2,QColor textcolor);
void openBrowser(QString url);
void showErrMsg(const QString& msg,QWidget* parent=NULL);

extern CConfig  config;
extern QString  AppDir;
extern QPixmap *EntryIcons;
extern QPixmap *Icon_Key32x32;
extern QPixmap *Icon_Settings32x32;
extern QPixmap *Icon_Search32x32;
extern QPixmap *Icon_I18n32x32;
extern QPixmap *Icon_Ok16x16;
extern QIcon *Icon_FileNew;
extern QIcon *Icon_FileOpen;
extern QIcon *Icon_FileClose;
extern QIcon *Icon_FileSave;
extern QIcon *Icon_FileSaveAs;
extern QIcon *Icon_Exit;
extern QIcon *Icon_File_Export;
extern QIcon *Icon_EditDelete;
extern QString DateTimeFormat;


#endif