#include "precomp.h"

void DebugPrintEthHeader(struct ETH_HEADER *eh)
{
	DbgPrint("EthHeader { %x:%x:%x-%x:%x:%x (dst) %x:%x:%x-%x:%x:%x (src) %x (type) }\n", 
				eh->DestinationAddress[0], eh->DestinationAddress[1], eh->DestinationAddress[2], 
				eh->DestinationAddress[3], eh->DestinationAddress[4], eh->DestinationAddress[5], 
				eh->SourceAddress[0], eh->SourceAddress[1], eh->SourceAddress[2], 
				eh->SourceAddress[3], eh->SourceAddress[4], eh->SourceAddress[5], 
				RtlUshortByteSwap(eh->EthType)
				);
}

