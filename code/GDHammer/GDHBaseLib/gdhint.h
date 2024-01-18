/*
====================================
License of the GDHammer source code
====================================

GDHammer is Copyright (C) 2012-2024 Marat Sungatullin.
All rights reserved.

This library is free software; you can redistribute it and/or modify it
under the terms of EITHER:

The GNU Lesser General Public License as published by the Free Software
Foundation; either version 3.0 of the License, or (at your option) any later
version. The text of the GNU Lesser General Public License is included with
this library in the file GDH_GPL_LICENSE.TXT.

The BSD-style license that is included with this library in the file
GDH_BSD_LICENSE.TXT.

This library is distributed in the hope that it will be useful, but WITHOUT ANY
WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR
A PARTICULAR PURPOSE. See the files GDH_GPL_LICENSE.TXT and GDH_BSD_LICENSE.TXT
for more details.

///////////////////////////////////////
GDH's BSD license (GDH_BSD_LICENSE.TXT)
Game Development Hammer
Copyright (c) 2012-2024 Marat Sungatullin.
All rights reserved.
Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:

Redistributions of source code must retain the above copyright notice, this
list of conditions and the following disclaimer.

Redistributions in binary form must reproduce the above copyright notice, this
list of conditions and the following disclaimer in the documentation and/or
other materials provided with the distribution.

Neither the names of GDH's copyright owner nor the names of its contributors
may be used to endorse or promote products derived from this software without
specific prior written permission.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE
GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT
OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

///////////////////////////////////////
GDH's GPL license (GDH_GPL_LICENSE.TXT)
Game Development Hammer
Copyright (c) 2012-2024 Marat Sungatullin.
All rights reserved.
This program is free software: you can redistribute it and/or modify it under
the terms of the GNU General Public License as published by the Free Software
Foundation, either version 3 of the License, or (at your option) any later
version. This program is distributed in the hope that it will be useful, but
WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more
details. You should have received a copy of the GNU General Public License
along with this program. If not, see <http://www.gnu.org/licenses/>

Web-link: https://opensource.org/license/gpl-3-0/

====================================
Description of this file
====================================

Integer types definitions.
*/
#ifndef GDHINT_H_INCLUDED
#define GDHINT_H_INCLUDED

#include <limits>

#ifdef __GNUC__
#   if __GNUC__ < 8
#       error "Too old version of gcc"
#   endif

// for gcc we use exact sized integers from stdint.h
#include <cstdint>

namespace gdh
{
using Int8 = int8_t;
using Int16 = int16_t;
using Int32 = int32_t;

using UInt8 = uint8_t;
using UInt16 = uint16_t;
using UInt32 = uint32_t;

} // end of gdh

#else // !gcc (other compilers)
#   error "unsupported compiler"
#endif // compiler dependent code end

// signed exact integers
using GdhInt8 = gdh::Int8;
using GdhInt16 = gdh::Int16;
using GdhInt32 = gdh::Int32;

// unsigned exact integers
using GdhUInt8 = gdh::UInt8;
using GdhUInt16 = gdh::UInt16;
using GdhUInt32 = gdh::UInt32;

/// base type for size storage
using GdhSize = GdhUInt32;

/// base type for index storage
using GdhIndex = GdhUInt32;

/** value for uninitialized index or value for the case when some value needs
to be returned if we didn't find an index of the thing we were looking for.
*/
const GdhIndex kGDH_NOINDEX = GdhIndex(0xFFFFFFFF);

#endif // GDHINT_H_INCLUDED
