#include "precomp.h"

void DebugPrintTCPHeader(struct TCP_HEADER * tcph)
{
	DbgPrint("TCP Header { src port : %d, dst port : %d", 
		tcph->SourcePortAddress, tcph->DestinationPortAddress);
	DbgPrint("             seq : %d, ack : %d",
		tcph->SequenceNumber,
		tcph->AcknowledgementNumber);
	DbgPrint("             stuff : %d, window size : %d",
		tcph->Stuff, tcph->WindowSize);
	DbgPrint("             checksum : 0x%x, urgent ptr : 0x%d",
		tcph->Checksum, tcph->UrgentPointer);
}