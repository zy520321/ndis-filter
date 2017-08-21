#include "precomp.h"

void DebugPrintUDPHeader(struct UDP_HEADER * udph)
{
	DbgPrint("UDP Header { src port : %d, dst port : %d",
			RtlUshortByteSwap(udph->SourcePortNumber), 
			RtlUshortByteSwap(udph->DestinationPortNumber)
			);
	DbgPrint("             Total Length : %d, Checksum : 0x%x }",
			RtlUshortByteSwap(udph->TotalLength), 
			RtlUshortByteSwap(udph->Checksum) 
			);
}