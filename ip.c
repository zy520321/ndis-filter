#include "precomp.h"

void DebugPrintIPv4Header(struct IPv4_HEADER * ipv4h)
{
	DbgPrint("IPv4 Header { VIDE : %d, TotalLength : %d", 
		ipv4h->VIDE, RtlUshortByteSwap(ipv4h->TotalLength));
	DbgPrint("              Id : %d, Flags & FragmentOffset : %d", 
		RtlUshortByteSwap(ipv4h->Identification), ipv4h->FFO);
	DbgPrint("              TTL : %d, Protocol : %d, HeaderChecksum : %d", 
		ipv4h->TTL, ipv4h->Protocol, RtlUshortByteSwap(ipv4h->HeaderChecksum));
	DbgPrint("              src : %d.%d.%d.%d, dst : %d.%d.%d.%d }\n", 
		ipv4h->SourceAddress[0], ipv4h->SourceAddress[1], 
		ipv4h->SourceAddress[2], ipv4h->SourceAddress[3], 
		ipv4h->DestinationAddress[0], ipv4h->DestinationAddress[1], 
		ipv4h->DestinationAddress[2], ipv4h->DestinationAddress[3]
	);

}