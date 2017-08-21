#ifndef FLTR_UDP_H
#define FLTR_UDP_H

struct UDP_HEADER{
	USHORT SourcePortNumber;
	USHORT DestinationPortNumber;
	USHORT TotalLength;
	USHORT Checksum;
};

void DebugPrintUDPHeader(struct UDP_HEADER * udph);

#endif