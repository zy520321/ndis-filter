#include "precomp.h"

void DebugPrintICMPHeader(struct ICMP_HEADER * icmph)
{
	DbgPrint("ICMP Header { Type : %d, Code : %d", icmph->Type, icmph->Code);
	DbgPrint("              Checksum : %x, Rest : %d }", RtlUshortByteSwap(icmph->Checksum), icmph->RestOfHeader);

}

BOOLEAN IsQueryMessage(UCHAR type)
{
	if(	type == ICMPMT_ECHO_REPLY			||
		type == ICMPMT_ECHO_REQUEST			||
		type == ICMPMT_TIMESTAMP_REQUEST	||
		type == ICMPMT_TIMESTAMP_REPLY
	  ) {
		  return TRUE;
	}

	return FALSE;
}
 
BOOLEAN IsDestinationUnreachable(UCHAR type)
{
	if(type == ICMPMT_DESTINATION_UNREACHABLE){
		return TRUE;
	}

	return FALSE;
}
BOOLEAN IsPing(UCHAR type)
{
	if(type == ICMPMT_ECHO_REPLY ||
		type == ICMPMT_ECHO_REQUEST ){
			return TRUE;
	}
	return FALSE;
}
