/***************************************************************************
 *   Copyright (C) 2005-2006 by Tarek Saidi                                *
 *   based on the FIPS-180-2 compliant SHA-256 implementation of	       *
 *   Christophe Devine.                                                    *
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

#ifndef _SHA256_H
#define _SHA256_H

#include <qglobal.h>

typedef struct
{
    quint32 total[2];
    quint32 state[8];
    quint8 buffer[64];
}sha256_context;

extern void sha256_starts( sha256_context *ctx );
extern void sha256_update( sha256_context *ctx, const quint8 *input, quint32 length );
extern void sha256_finish( sha256_context *ctx, quint8 digest[32] );

class SHA256{
	public:
		SHA256(){sha256_starts(&ctx);}
		void update(void* input,quint32 length){sha256_update(&ctx,(quint8*)input,length);}
		void finish(void* digest){sha256_finish(&ctx,(quint8*)digest);}
		static void hashBuffer(const void* input, void* digest,quint32 length);
	private:
		sha256_context ctx;	
};


#endif /* sha256.h */
