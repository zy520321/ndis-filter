#ifndef FLTR_TCP_H
#define FLTR_TCP_H

struct TCP_HEADER{
	USHORT SourcePortAddress;
	USHORT DestinationPortAddress;
	ULONG SequenceNumber;
	ULONG AcknowledgementNumber;
	USHORT Stuff;
	USHORT WindowSize;
	USHORT Checksum;
	USHORT UrgentPointer;
};

void DebugPrintTCPHeader(struct TCP_HEADER * tcph);

#endif