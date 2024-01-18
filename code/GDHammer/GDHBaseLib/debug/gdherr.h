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

*/

#ifndef GDHERR_H_INCLUDED
#define GDHERR_H_INCLUDED

#include "GDHBaseLib/gdhint.h"

enum class GdhResultType : GdhByte
{
    kERROR = 0,
    kOk = 1,
    kFATAL = 2,
    kCANCEL = 3,
    kWARN = 4
};

enum class GdhErrorCodes : GdhInt16
{
    kUnknown = -1,
    kNone

};

enum class GdhErrorSource : GdhByte
{
    kGdh,

};

namespace gdh
{

/* Class for values to return from functions.
*/
class Result
{
public:
    Result() = default;

    Result(Int16 errorCode,
           Byte result = GdhResultType::kERROR,
           Byte custom = GdhErrorSource::kGdh)
    : m_result{result}
    , m_custom{custom}
    , m_errorCode{errorCode}
    {

    }

    Byte getResult() const { return m_result; }
    Byte getCustom() const { return m_custom; }
    Int16 getErrorCode() const { return m_errorCode; }

    operator bool() const { return static_cast<Byte>(GdhResultType::kOk) == m_result; }
private:
    Byte m_result{GdhResultType::kOk}; // common result of operation (Ok, error, fatal etc)
    Byte m_custom{GdhErrorSource::kGdh}; // use it for library identification for example
    Int16 m_errorCode{GdhErrorCodes::kNone};
};
} // end of gdh


#endif // GDHERR_H_INCLUDED
