#pragma once
#define IN_MAX_LEN_TEXT 1024*1024	
#define IN_CODE_ENDL '\n'			
#define IN_CODE_TABLE {\
/*15*/		IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, \
/*31*/		IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, \
/*47*/		IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, \
/*63*/		IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, \
/*79*/		IN::F, IN::T, IN::F, IN::F, IN::F, IN::F, IN::T, IN::F, IN::F, IN::T, IN::F, IN::T, IN::F, IN::T, IN::T, IN::T, \
/*95*/		IN::F, IN::F, IN::T, IN::T, IN::T, IN::T, IN::T, '-',   IN::I, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, \
/*111*/		IN::F, IN::T, IN::F, IN::F, IN::F, IN::F, IN::T, IN::F, IN::F, IN::T, IN::F, IN::T, IN::F, IN::T, IN::T, IN::T, \
/*127*/		IN::F, IN::F, IN::T, IN::T, IN::T, IN::T, IN::T, '-',   IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, \
			\
/*143*/		'+'  , IN::T, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, \
/*159*/		IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, \
/*175*/		IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, \
/*191*/		IN::T, IN::F, IN::T, IN::F, IN::F, IN::F, IN::F, IN::F, IN::T, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, \
/*207*/		IN::T, IN::F, IN::T, IN::F, IN::T, IN::F, IN::F, IN::F, IN::F, IN::F, IN::T, IN::F, IN::T, IN::T, IN::T, IN::F, \
/*223*/		IN::T, IN::T, IN::T, IN::F, IN::F, IN::F, IN::F, IN::F, IN::T, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, \
/*239*/		IN::T, IN::F, IN::T, IN::F, IN::T, IN::F, IN::F, IN::F, IN::F, IN::F, IN::T, IN::F, IN::T, IN::T, IN::T, IN::F, \
/*255*/		IN::T, IN::T, IN::T, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F  \
} 

namespace In
{ 
	struct IN			
	{
		enum { T = 1024, F = 2048, I = 4096 }; 
		int size;	
		int lines;	
		int ignor;	
		unsigned char* text;	
		int code[256];	
	};
	IN getin(wchar_t infile[]);	 
};
