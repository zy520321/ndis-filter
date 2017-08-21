#ifndef FLTR_UTILITIES_H
#define FLTR_UTILITIES_H

#define INLINE_WORD_FLIP(out, in)   \
      	  {                           \
            	WORD _in = (in);        \
	            (out) = (_in << 8) | (_in >> 8);  \
      	  }
	#define INLINE_HTONS(out, in)   INLINE_WORD_FLIP(out, in)
	#define INLINE_NTOHS(out, in)   INLINE_WORD_FLIP(out, in)

#define INLINE_WORD_FLIP_OUT(in)	((in) << 8 | (in) >> 8)

#define TRUE 1
#define FALSE 0

#define ERROR_ARPC_CN_NO_ALLOC "Error allocating memory to acn in arp.c > CreateNode."

#endif