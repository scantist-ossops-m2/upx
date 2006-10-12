/* compress_zlib.cpp --

   This file is part of the UPX executable compressor.

   Copyright (C) 1996-2006 Markus Franz Xaver Johannes Oberhumer
   Copyright (C) 1996-2006 Laszlo Molnar
   All Rights Reserved.

   UPX and the UCL library are free software; you can redistribute them
   and/or modify them under the terms of the GNU General Public License as
   published by the Free Software Foundation; either version 2 of
   the License, or (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; see the file COPYING.
   If not, write to the Free Software Foundation, Inc.,
   59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.

   Markus F.X.J. Oberhumer              Laszlo Molnar
   <mfx@users.sourceforge.net>          <ml1050@users.sourceforge.net>
 */


#include "conf.h"
#include "compress.h"
#if !defined(WITH_ZLIB)
extern int compress_zlib_dummy;
int compress_zlib_dummy = 0;
#else

#include <zlib.h>


/*************************************************************************
//
**************************************************************************/

int upx_zlib_compress      ( const upx_bytep src, unsigned  src_len,
                                   upx_bytep dst, unsigned* dst_len,
                                   upx_callback_p cb_parm,
                                   int method, int level,
                             const upx_compress_config_t *cconf_parm,
                                   upx_compress_result_t *cresult )
{
    assert(method == M_DEFLATE);
    assert(level > 0); assert(cresult != NULL);

    UNUSED(src); UNUSED(src_len);
    UNUSED(dst); UNUSED(dst_len);
    UNUSED(cb_parm);
    UNUSED(method); UNUSED(level);
    UNUSED(cconf_parm);
    UNUSED(cresult);

    return UPX_E_ERROR;
}


/*************************************************************************
//
**************************************************************************/

int upx_zlib_decompress    ( const upx_bytep src, unsigned  src_len,
                                   upx_bytep dst, unsigned* dst_len,
                                   int method,
                             const upx_compress_result_t *cresult )
{
    assert(method == M_DEFLATE);
    UNUSED(cresult);

    UNUSED(src); UNUSED(src_len);
    UNUSED(dst); UNUSED(dst_len);
    UNUSED(method);
    UNUSED(cresult);

    return UPX_E_ERROR;
}


/*************************************************************************
//
**************************************************************************/

int upx_zlib_test_overlap  ( const upx_bytep buf, unsigned src_off,
                                   unsigned  src_len, unsigned* dst_len,
                                   int method,
                             const upx_compress_result_t *cresult )
{
    assert(method == M_DEFLATE);
    UNUSED(cresult);

    UNUSED(buf); UNUSED(src_off);
    UNUSED(src_len); UNUSED(dst_len);
    UNUSED(method);
    UNUSED(cresult);

    return UPX_E_ERROR;
}


/*************************************************************************
// misc
**************************************************************************/

const char *upx_zlib_version_string(void)
{
    return zlib_version;
}


#endif /* WITH_ZLIB */
/*
vi:ts=4:et:nowrap
*/
