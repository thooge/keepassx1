/***************************************************************************
 *   Copyright (C) 2005 by Tarek Saidi                                     *
 *   mail@tarek-saidi.de                                                   *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; version 2 of the License.               *

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

#include "random.h"


#if defined(Q_WS_X11) || defined(Q_WS_MAC)
	#include <QFile>
#elif defined(Q_WS_WIN)
	#include <windows.h>
	#include <QSysInfo>
#endif

#include <QCursor>
#include <QDateTime>
#include <QTime>

void Random::getEntropy(quint8* buffer, int length){
#if defined(Q_WS_X11) || defined(Q_WS_MAC)
	QFile dev_urandom("/dev/urandom");
	if (dev_urandom.open(QIODevice::ReadOnly|QIODevice::Unbuffered) && dev_urandom.read((char*)buffer,length)==length)
		return;
#elif defined(Q_WS_WIN)
	// RtlGenRandom
	if (QSysInfo::WindowsVersion>=QSysInfo::WV_XP){
		bool success=false;
		HMODULE hLib=LoadLibraryA("ADVAPI32.DLL");
		if (hLib) {
			BOOLEAN (APIENTRY *pfn)(void*, ULONG) = (BOOLEAN (APIENTRY *)(void*,ULONG))GetProcAddress(hLib,"SystemFunction036");
			if (pfn && pfn(buffer,length)) {
				success=true;
			}
			FreeLibrary(hLib);
		}
		if (success)
			return;
	}
#endif
	
	initStdRand();
	for(int i=0;i<length;i++){
		((quint8*)buffer)[i] = (quint8) (qrand()%256);
	}
}

void Random::initStdRand(){
	static bool initalized = false;
	if (initalized)
		return;
	
	QByteArray buffer;
	QDataStream stream(&buffer, QIODevice::WriteOnly);
	
	stream << QCursor::pos();
	stream << QDateTime::currentDateTime().toTime_t();
	stream << QTime::currentTime().msec();
	
	quint8 hash[32];
	SHA256::hashBuffer(buffer.data(), hash, buffer.size());
	
	qsrand( (uint) *hash );
	initalized = true;
}
