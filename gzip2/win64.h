
/*
    <C/C++ source code of the support dlls>    
    Copyright (C) <2020>  <BinaryWork Corp.>

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU GENERAL PUBLIC LICENSE
	and GNU LESSER GENERAL PUBLIC LICENSE along with this program.  
	If not, see <http://www.gnu.org/licenses/>.
    
    support: http://nomade.sourceforge.net
    
	direct programmers e-mails:
	Ricardo: arsoftware25@gmail.com
	Amanda : arsoftware10@gmail.com
	
	immediate contact(for a very fast answer) WhatsApp
	(+55)41 9627 1708 - it is always on
*/
 
#ifndef BE_WIN64_SUPPORT__
#define BE_WIN64_SUPPORT__	
	#ifdef _M_X64
	#define __INT32_OR_INT64 __int64
	#ifdef __GNUC__
	 //#warning size of __INT32_OR_INT64 is 8
	#else
	 //#pragma message ( "size of __INT32_OR_INT64 is 8" )
	#endif
	#else

	#define __INT32_OR_INT64 int
	#ifdef __GNUC__
	 //#warning size of __INT32_OR_INT64 is 4
	#else
	 //#pragma message ( "size of __INT32_OR_INT64 is 4" )
	#endif
	#endif
#endif